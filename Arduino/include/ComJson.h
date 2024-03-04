
#ifndef COMJSON_H
#define COMJSON_H

#include <Arduino.h>
#include <ArduinoJson.h>



enum etatComJson
{
    ComJsonEnabled = 3,
    ComJsonDisabled = 4
};


class ComJson
{
private:
    long Baudrate;
    etatComJson etat;
    StaticJsonDocument<500> Send;
    StaticJsonDocument<500> Received;
    


public:
    volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
    volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message


    ComJson(long baud);
    ~ComJson();
    etatComJson GetEtat();
    void SetEtat(etatComJson etatVoulu);
    void sendMsg();
    void readMsg();

    void AddMessage(const char* name, int value);
    void AddMessage(const char* name, bool value);
    void AddMessage(const char* name, const char* value);
    void AddMessage(const char* name, float value);
    void AddMessage(const char* name, unsigned long value);

    bool GetValue(const char* name, int* value);
    bool GetValue(const char* name, bool* value);
    bool GetValue(const char* name, char* value);
    bool GetValue(const char* name, float* value);
};




#endif