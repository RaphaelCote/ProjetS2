#include "controllerControls.h"
#include <windows.h>

float TRESHOLD = 0.25;

int led_state = 0;
long index = 0;

static DWORD WINAPI ThreadEntry(LPVOID lpParam)
{
    auto *data = reinterpret_cast<std::pair<ControllerControls *, int> *>(lpParam);
    if (data)
    {
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

    // // Create a lambda function to capture the instance of MyClass and call its member function
    // auto lambda = [&](int arg) {
    //     this->ThreadReceiveSerial();
    // };

    // // Create a pair to store MyClass instance and the argument
    // auto* data = new std::pair<ControllerControls*, int>(this,42);

    // // Create a thread and pass the entry point function
    // HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

    // if (threadHandle == nullptr) {
    //     std::cerr << "Error creating thread.\n";
    // }
}

void ControllerControls::ThreadReceiveSerial()
{
    while (Thread_Actif)
    {
        while(ready_to_read == false)
        {Sleep(1);}
        Sleep(10);
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
                //cout << "Arduino: " << raw_msg << endl;
                messageReceived = json::parse(raw_msg);
                this->UpdateAllValues();
                //cout << "All values are updated: " << etatB1 << endl;
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

void ControllerControls::ReceiveSerial()
{
    if(ready_to_read)
    {
        Sleep(10);
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
                cons->SupprimerObjet("Json");
                cons->AfficherTexte(std::cout, raw_msg,20,200,"Json");

                for (int i = 0; i < raw_msg.length(); i++)
                {
                    if(raw_msg[i] != '{')
                    {
                        raw_msg.erase(0,1);
                        i--;
                    }
                    else
                    {
                        break;
                    }
                }
                

                //cout << "Arduino: " << raw_msg << endl;
                if(raw_msg.length() < 2)
                {
                    ready_to_read = false;
                    ready_to_send = true;
                    return;
                }
                messageReceived = json::parse(raw_msg);
                cons->SupprimerObjet("ParseJson");

                cons->AfficherTexte(std::cout, raw_msg,20,180,"ParseJson");

                UpdateAllValues();
                //cout << "All values are updated: " << etatB1 << endl;
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
    // Joystick
    this->etatJoyX = this->GetJoyXMenu0(&(this->JoystickValX));
    this->etatJoyY = this->GetJoyYMenu0(&(this->JoystickValY));

    // Angle
    float angle;
    this->GetValue("Angle", &(angle));

    for (int i = GROSSEUR_TAB_ANGLE - 1; i > 0; i--)
    {
        Tab_AnglesManette[i] = Tab_AnglesManette[i - 1];
    }

    Tab_AnglesManette[0] = angle;

    for (int i = 0; i < GROSSEUR_TAB_ANGLE; i++)
    {
        angle += Tab_AnglesManette[i];
    }

    AngleManette = angle / GROSSEUR_TAB_ANGLE;

    // buttons
    this->etatB1 = this->GetBouttonMenu0(1);
    this->etatB2 = this->GetBouttonMenu0(2);
    this->etatB3 = this->GetBouttonMenu0(3);
    this->etatB4 = this->GetBouttonMenu0(4);
    this->etatB5 = this->GetBouttonMenu0(5);
}

void ControllerControls::ListenForControls()
{
    if (ready_to_send == true)
    {
        // cout << "Sending" << endl;
        this->AddMessage("Moteur", 0);
        if (!this->SendMessageJson())
            return;

        // cout << "Veuillez lancer: ";
    }

    // cout << "Message: " << messageReceived << endl;
    // cout << "B1: " << this->etatB1 << endl;
    Angle(AngleManette);
    Joystick(JoystickValY, 0);
    // cout << "Sleep for 1" << endl;
    // Sleep(1000);
    // cout << " Finished" << endl;
    // Sleep(100);

    if (etatB1 == etatBoutton::BouttonAppuyer && etatB1 != oldEtatB1)
    {
        MainAction();
    }
    else if (etatJoyX == etatJoystick::JoystickUp && oldEtatJoyX != etatJoystick::JoystickUp)
    {
        Joystick(0, 1);
    }
    else if (etatJoyX == etatJoystick::JoystickDown && oldEtatJoyX != etatJoystick::JoystickDown)
    {
        Joystick(0, -1);
    }
    else if (etatB2 == etatBoutton::BouttonAppuyer && etatB2 != oldEtatB2)
    {
        PreviousSelection();
    }
    else if (etatB4 == etatBoutton::BouttonAppuyer && etatB4 != oldEtatB4)
    {
        NextSelection();
    }
    else if (etatB5 == etatBoutton::BouttonAppuyer && etatB5 != oldEtatB5)
    {
        Menu();
    }

    oldEtatB1 = etatB1;
    oldEtatB2 = etatB2;
    oldEtatB3 = etatB3;
    oldEtatB4 = etatB4;
    oldEtatB5 = etatB5;
    oldEtatJoyX = etatJoyX;
    oldEtatJoyY = etatJoyY;
}

etatJoystick ControllerControls::GetJoyXMenu0(float *value)
{

    this->GetValue("JoyX", value);
    // JoyX -1 == en bas
    // JoyY 1 == en haut
    if (*value >= TRESHOLD) // up
    {
        return etatJoystick::JoystickUp;
    }
    else if (*value <= -TRESHOLD) // down
    {
        return etatJoystick::JoystickDown;
    }
    else // center
    {
        return etatJoystick::JoystickMiddle;
    }
}

etatJoystick ControllerControls::GetJoyYMenu0(float *value)
{
    this->GetValue("JoyY", value);

    //////////////////////////////////////
    //
    if (*value >= TRESHOLD) // up
    {
        return etatJoystick::JoystickUp;
    }
    else if (*value <= -TRESHOLD) // down
    {
        return etatJoystick::JoystickDown;
    }
    else // center
    {
        return etatJoystick::JoystickMiddle;
    }
}

etatBoutton ControllerControls::GetBouttonMenu0(int boutton)
{
    int B1;

    this->GetValue("B" + to_string(boutton), &B1);

    if (B1 == 1)
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
    if (!ready_to_send)
        return false;
    // Return 0 if error
    string msg = message_to_send.dump();
    // cout << "Message: " << msg << endl;
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    message_to_send.clear();
    ready_to_read = true;
    ready_to_send = false;

    // cout << "B1 Send: " << this->etatB1 << endl;

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

void ControllerControls::GetValue(string name, int *value)
{
    if(messageReceived.contains(name))
        *value = messageReceived[name.c_str()];
    else
    {
        cons->SupprimerObjet("NoName");

        cons->AfficherTexte(std::cout, name,20,160,"NoName");
        *value = 0;
    }
}
void ControllerControls::GetValue(string name, bool *value)
{
    if(messageReceived.contains(name))
        *value = messageReceived[name.c_str()];
    else
    {
        cons->SupprimerObjet("NoName");

        cons->AfficherTexte(std::cout, name,20,160,"NoName");
        *value = false;
    }
}
void ControllerControls::GetValue(string name, string *value)
{
    if(messageReceived.contains(name))
        *value = messageReceived[name.c_str()];
    else
    {
        cons->SupprimerObjet("NoName");

        cons->AfficherTexte(std::cout, name,20,160,"NoName");
        *value = "";
    }
}
void ControllerControls::GetValue(string name, float *value)
{
    if(messageReceived.contains(name))
        *value = messageReceived[name.c_str()];
    else
    {
        cons->SupprimerObjet("NoName");

        cons->AfficherTexte(std::cout, name,20,160,"NoName");
        *value = 0;
    }
}
