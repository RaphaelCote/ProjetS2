#include "controllerControls.h"


ControllerControls::ControllerControls(EventManager *em, string com) : Controls(em)
{
    comPort = com;
    InitializeSerial();
}


void ControllerControls::ListenForControls()
{
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
    cout << "Message: " << msg << endl;
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    message_to_send.clear();
    messageReceived.clear(); // effacer le message precedent
    if (!RcvFromSerial())
    {
        cerr << "Erreur lors de la reception du message. " << endl;
    }

    // Impression du message de l'Arduino si valide
    if (raw_msg.size() > 0)
    {
        // cout << "raw_msg: " << raw_msg << endl;  // debug
        //  Transfert du message en json
        messageReceived = json::parse(raw_msg);
        cout << "Message de l'Arduino: " << messageReceived << endl;
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
    *value = messageReceived[name];
}
void ControllerControls::GetValue(string name, bool* value)
{
    *value = messageReceived[name];
}
void ControllerControls::GetValue(string name, string* value)
{
    *value = messageReceived[name];
}
void ControllerControls::GetValue(string name, float* value)
{
    *value = messageReceived[name];
}


