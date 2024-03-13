
#include "ComJson.h"



ComJson::ComJson(long baud)
{
    Baudrate = baud;
    etat = etatComJson::ComJsonEnabled;
}

ComJson::~ComJson()
{
    
}

etatComJson ComJson::GetEtat()
{
    return etat;
}

void ComJson::SetEtat(etatComJson etatVoulu)
{
    etat = etatVoulu;
}

void ComJson::sendMsg() {

  // Serialisation
  serializeJson(Send, Serial);

    Send.clear();
    
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void ComJson::readMsg(){
    Received.clear();
    shouldRead_ = false;
  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(Received, Serial);
  
  shouldSend_ = true;

  // Si erreur dans le message
  if (error) {
    
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
}


void ComJson::AddMessage(const char* name, int value)
{
    Send[name] = value;
}

void ComJson::AddMessage(const char* name, bool value)
{
    Send[name] = value;
}

void ComJson::AddMessage(const char* name, const char* value)
{
    Send[name] = value;
}

void ComJson::AddMessage(const char* name, float value)
{
    Send[name] = value;
}

void ComJson::AddMessage(const char* name, unsigned long value)
{
    Send[name] = value;
}

bool ComJson::GetValue(const char* name, int* value)
{
    JsonVariant parse_msg = Received[name];
    if(parse_msg.isNull())
        return false;
    *value = Received[name].as<int>();
    return true;
}
bool ComJson::GetValue(const char* name, bool* value)
{
    JsonVariant parse_msg = Received[name];
    if(parse_msg.isNull())
        return false;
    *value = Received[name].as<bool>();
    return true;
}
bool ComJson::GetValue(const char* name, char* value)
{
    JsonVariant parse_msg = Received[name];
    if(parse_msg.isNull())
        return false;
    //*value = Received[name].as<char>();
    return true;
}
bool ComJson::GetValue(const char* name, float* value)
{
    JsonVariant parse_msg = Received[name];
    if(parse_msg.isNull())
        return false;
    *value = Received[name].as<float>();
    return true;
}


