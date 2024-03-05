#include "controllerControls.h"

float TRESHOLD = 0.25;

int led_state = 0;
long index = 0;

etatBoutton etatB1 = etatBoutton::BouttonEnabled;
etatBoutton oldEtatB1 = etatBoutton::BouttonEnabled;

etatJoystick etatJoyX = etatJoystick::JoystickEnabled;
etatJoystick etatJoyY = etatJoystick::JoystickEnabled;
etatJoystick oldEtatJoyX = etatJoystick::JoystickEnabled;
etatJoystick oldEtatJoyY = etatJoystick::JoystickEnabled;


ControllerControls::ControllerControls(EventManager *em, string com) : Controls(em)
{
    comPort = com;
    InitializeSerial();
}


void ControllerControls::ListenForControls()
{
    if(index%10 == 0)
        led_state = 0;

    this->AddMessage("led", led_state);
    if(!this->SendMessageJson())
        return;
    Sleep(10);

    led_state = led_state >> 1;
    led_state += 512;

    cout << "Veuillez lancer: ";
    
    
    
    etatJoyX = GetJoyXMenu0();
    etatJoyY = GetJoyYMenu0();
    etatB1 = GetB1Menu0();
    float angle;
        float joystickX;
        float joystickY;
        index = 0;
        this->GetValue("Angle", &angle);
        this->GetValue("JoyY", &joystickY);
        this->GetValue("JoyY", &joystickX);
        Angle(angle);
        Joystick(joystickX, joystickY);

    if (etatB1 == etatBoutton::BouttonAppuyer && etatB1 != oldEtatB1)
    {
        
        MainAction();
    }
    else if (etatJoyX == etatJoystick::JoystickUp && etatJoyX != oldEtatJoyX)
    {
        Joystick(0, 1);
    }
    else if (etatJoyX == etatJoystick::JoystickDown && etatJoyX != oldEtatJoyX)
    {
        Joystick(0, -1);
    }
    // else if (input == "n")
    // {
    //     PreviousSelection();
    // }
    // else if (input == "m")
    // {
    //     NextSelection();
    // }
    // else if (input == "p")
    // {
    //     Menu();
    // }
    // else if (input == "u")
    // {
    //     float angle;
    //     cout << "Veuillez entrer un angle : ";
    //     cin >> angle;

    //     Angle(angle);
    // }
    // else if (input == "i")
    // {
    //     float joystickX;
    //     float joystickY;
    //     cout << "Veuillez entrer un x de Joystick : ";
    //     cin >> joystickX;
    //     cout << "Veuillez entrer un y de Joystick : ";
    //     cin >> joystickY;

    //     Joystick(joystickX, joystickY);
    // }

    oldEtatB1 = etatB1;
    oldEtatJoyX = etatJoyX;
    oldEtatJoyY = etatJoyY;
}

etatJoystick ControllerControls::GetJoyXMenu0()
{
    float joystickValX;
    
    

    this->GetValue("JoyX", &joystickValX);
    
    

    //JoyX -1 == en bas
    //JoyY 1 == en haut
    if(joystickValX >= TRESHOLD)//up
    {
        return etatJoystick::JoystickUp;
    }
    else if(joystickValX <= -TRESHOLD)//down
    {
        return etatJoystick::JoystickDown;
    }
    else//center
    {
        return etatJoystick::JoystickMiddle;
    }

}

etatJoystick ControllerControls::GetJoyYMenu0()
{
    float joystickValY;

    this->GetValue("JoyY", &joystickValY);

    //////////////////////////////////////
    //
    if(joystickValY >= TRESHOLD)//up
    {
        return etatJoystick::JoystickUp;
    }
    else if(joystickValY <= -TRESHOLD)//down
    {
        return etatJoystick::JoystickDown;
    }
    else//center
    {
        return etatJoystick::JoystickMiddle;
    }

}

etatBoutton ControllerControls::GetB1Menu0()
{
    int B1;

    this->GetValue("B1", &B1);

    if(B1 == 1)
    {
        return etatBoutton::BouttonAppuyer;
    }
    else
    {
        return etatBoutton::BouttonRelacher;
    }
}


void ControllerControls::InitializeSerial()
{
    arduino = new SerialPort(comPort.c_str(), BAUD);

    // const char com = "\\\\.\\COM3";
    // SerialPort arduino = SerialPort("\\\\.\\COM3");
    if (!arduino->isConnected())
    {
        cerr << "Impossible de se connecter au port " << string(comPort) << ". Fermeture du programme!" << endl;
        exit(1);
    }
}

bool ControllerControls::SendToSerial()
{
    // Return 0 if error
    string msg = message_to_send.dump();
    //cout << "Message: " << msg << endl;
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    message_to_send.clear();
    messageReceived.clear(); // effacer le message precedent
    if (!RcvFromSerial())
    {
        cerr << "Erreur lors de la reception du message. " << endl;
    }
    //cout << "Message de l'Arduino: " << raw_msg << endl;
    // Impression du message de l'Arduino si valide
    if (raw_msg.size() <= 0)
    {
        return false;
    }
        // cout << "raw_msg: " << raw_msg << endl;  // debug
        //  Transfert du message en json
        try
        {
            messageReceived = json::parse(raw_msg);
            //cout << "Message de l'Arduino: " << messageReceived << endl;
        }
        catch(nlohmann::detail::parse_error e)
        {
            cout << "Erreur Parse: " << e.what() << '\n';
            return false;
        }
        
        
    
    return ret;
}

bool ControllerControls::RcvFromSerial()
{
    // Return 0 if error
    // Message output in msg
    string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    raw_msg.clear(); // clear string
    // Read serialport until '\n' character (Blocking)

    // Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
    /*
        while(msg.back()!='\n'){
            if(msg.size()>MSG_MAX_SIZE){
                return false;
            }

            buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
            str_buffer.assign(char_buffer, buffer_size);
            msg.append(str_buffer);
        }
    */

    // Version fonctionnelle dans VScode et Visual Studio
    Sleep(100);
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    raw_msg.append(str_buffer);

    // msg.pop_back(); //remove '/n' from string

    return true;
}



bool ControllerControls::SendMessageJson()
{
    return SendToSerial();
}

void ControllerControls::AddMessage(string name, int value)
{
    message_to_send[name.c_str()] = value;
}

void ControllerControls::AddMessage(string name, bool value)
{
    message_to_send[name.c_str()] = value;
}

void ControllerControls::AddMessage(string name, string value)
{
    message_to_send[name.c_str()] = value;
}

void ControllerControls::AddMessage(string name, float value)
{
    message_to_send[name.c_str()] = value;
}

void ControllerControls::GetValue(string name, int* value)
{
    *value = messageReceived[name.c_str()];
}
void ControllerControls::GetValue(string name, bool* value)
{
    *value = messageReceived[name.c_str()];
}
void ControllerControls::GetValue(string name, string* value)
{
    *value = messageReceived[name.c_str()];
}
void ControllerControls::GetValue(string name, float* value)
{
    *value = messageReceived[name.c_str()];
}


