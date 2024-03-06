#include "controllerControls.h"
#include <windows.h>


float TRESHOLD = 0.25;

int led_state = 0;
long index = 0;

static DWORD WINAPI ThreadEntry(LPVOID lpParam) {
        auto* data = reinterpret_cast<std::pair<ControllerControls*, int>*>(lpParam);
        if (data) {
            data->first->ThreadReceiveSerial();
            delete data;
        }
        return 0;
    }

ControllerControls::ControllerControls(EventManager *em, string com) : Controls(em)
{
    comPort = com;
    InitializeSerial();
    etatB1 = etatBoutton::BouttonRelacher;
    oldEtatB1 = etatBoutton::BouttonRelacher;
    etatJoyX = etatJoystick::JoystickMiddle;
    etatJoyY = etatJoystick::JoystickMiddle;
    oldEtatJoyX = etatJoystick::JoystickMiddle;
    oldEtatJoyY = etatJoystick::JoystickMiddle;
    ready_to_send = true;
    ready_to_read = false;
    Thread_Actif = true;

    // Create a lambda function to capture the instance of MyClass and call its member function
    auto lambda = [&](int arg) {
        this->ThreadReceiveSerial();
    };

    // Create a pair to store MyClass instance and the argument
    auto* data = new std::pair<ControllerControls*, int>(this,42);

    // Create a thread and pass the entry point function
    HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

    if (threadHandle == nullptr) {
        std::cerr << "Error creating thread.\n";
    }
}



void ControllerControls::ThreadReceiveSerial()
{
    while(Thread_Actif)
    {
        while(ready_to_read == false)
        {Sleep(1);}
        Sleep(100);
        //cout << "Thread is life" << endl;
        messageReceived.clear(); // effacer le message precedent
        if (!RcvFromSerial())
        {
            cerr << "Erreur lors de la reception du message. " << endl;
        }
        else
        {
            try
            {
                cout << "Arduino: " << raw_msg << endl;
                messageReceived = json::parse(raw_msg);
                this->UpdateAllValues();
                cout << "All values are updated: " << etatB1 << endl;
                //cout << "Message de l'Arduino: " << messageReceived << endl;
            }
            catch(nlohmann::detail::parse_error e)
            {
                cout << "Erreur Parse: " << e.what() << '\n';
            }
        }
        
        ready_to_read = false;
        ready_to_send = true;
    }
}

void ControllerControls::UpdateAllValues()
{
    //Joystick
    this->etatJoyX = this->GetJoyXMenu0(&(this->JoystickValX));
    this->etatJoyY = this->GetJoyXMenu0(&(this->JoystickValY));

    //Angle
    this->GetValue("Angle", &(this->AngleManette));

    //buttons
    this->etatB1 = this->GetBouttonMenu0(1);
    this->etatB2 = this->GetBouttonMenu0(2);
    this->etatB3 = this->GetBouttonMenu0(3);
    this->etatB4 = this->GetBouttonMenu0(4);
    this->etatB5 = this->GetBouttonMenu0(5);
}


void ControllerControls::ListenForControls()
{
    if(ready_to_send == true)
    {
        ready_to_send = false;
        this->AddMessage("Moteur", 0);
        if(!this->SendMessageJson())
            return;

        cout << "Veuillez lancer: ";
    }
    
    //cout << "Message: " << messageReceived << endl;
    //cout << "B1: " << this->etatB1 << endl;
    Angle(AngleManette);
    Joystick(JoystickValX, JoystickValY);

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

etatJoystick ControllerControls::GetJoyXMenu0(float* value)
{
    
    this->GetValue("JoyX", value);
    //JoyX -1 == en bas
    //JoyY 1 == en haut
    if(*value >= TRESHOLD)//up
    {
        return etatJoystick::JoystickUp;
    }
    else if(*value <= -TRESHOLD)//down
    {
        return etatJoystick::JoystickDown;
    }
    else//center
    {
        return etatJoystick::JoystickMiddle;
    }

}

etatJoystick ControllerControls::GetJoyYMenu0(float* value)
{
    this->GetValue("JoyY", value);

    //////////////////////////////////////
    //
    if(*value >= TRESHOLD)//up
    {
        return etatJoystick::JoystickUp;
    }
    else if(*value <= -TRESHOLD)//down
    {
        return etatJoystick::JoystickDown;
    }
    else//center
    {
        return etatJoystick::JoystickMiddle;
    }

}

etatBoutton ControllerControls::GetBouttonMenu0(int boutton)
{
    int B1;

    this->GetValue("B" + to_string(boutton), &B1);

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
    if(!ready_to_send)
        return false;
    // Return 0 if error
    string msg = message_to_send.dump();
    //cout << "Message: " << msg << endl;
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    message_to_send.clear();
    ready_to_read = true;
    ready_to_send = false;

    //cout << "B1 Send: " << this->etatB1 << endl;
    
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


