/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include "Boutton.h"
#include "EcranLCD.h"
#include "Joystick.h"

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle
#define MENUHEIGHT 5

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message
int ledState = 0;
int potValue = 0;
int pinLED = 7;
int pinPOT = A0;




EcranLCD LCD;
Joystick joystick(A3, A4);
Boutton b1(34);

int positionMenu = 0;
int Menu = 0;
int oldMenu = -1;

char tableau[2][16] = {"HELLO WORLD    ",
                       "Frank is here  "};


char MenuPrincipal[MENUHEIGHT][16] = {"1 - Accel      ",
                                      "2 - Boutton    ",
                                      "3 - Bargraphe  ",
                                      "4 - Moteur     ",
                                      "5 - Joystick   "};

char TabMenuAccel[2][16] = {"Accel   X:     ",
                            "Y:      Z:     "};

char TabMenuBoutton[2][16] = {"B1:     B2:    ",
                              "B3:     B4:    "};

char tabMenuBargraphe[2][16] = {"Bargraphe      ",
                                "               "};

char tabMenuMoteur[2][16] = {"Moteur         ",
                             "               "};

char tabMenuJoystick[2][16] = {"Joystick       ",
                               "X:     Y:      "};


/*------------------------- Prototypes de fonctions -------------------------*/
void MenuPrincipalGestion();
void MenuJoystick();
void MenuBouton();
void MenuAccelerometre();
void MenuMoteur();
void MenuBargraphe();

void GestionBouttonMenu();
void GestionJoystick();

void AfficheValDec(int val, int x, int y);

void sendMsg(); 
void readMsg();
void serialEvent();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  //pinMode(pinLED, OUTPUT);
  //digitalWrite(pinLED, ledState);
  LCD.Initialisation();
  //LCD.EcrireCommande(0x00);
  // LCD.EcrireData('A');
  // LCD.EcrireData('L');
  // LCD.EcrireData('L');
  // LCD.EcrireData('O');
  delay(3000);

  AfficheValDec(1000,9,2);
  delay(1000);
  AfficheValDec(1234,2,2);
  delay(5000);
  //LCD.EcrireTableau(MenuPrincipal,15,2);
}


void loop() 
{
  switch (Menu)
  {
  case 0://menu principal
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
    }
    MenuPrincipalGestion();
    
    break;

  case 1://menu accelerometre
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(TabMenuAccel, 15, 2);
    }
    MenuAccelerometre();
    
    break;

  case 2://Menu Boutton
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(TabMenuBoutton, 15, 2);
    }
    MenuBouton();
    
    break;

  case 3://BarGraphe
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(tabMenuBargraphe, 15, 2);
    }
    MenuBargraphe();
    
    break;

  case 4://Moteur
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(tabMenuMoteur, 15, 2);
    }
    MenuMoteur();
    
    break;

  case 5://Joystick
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(tabMenuJoystick, 15, 2);
    }
    MenuJoystick();
    
    break;
  
  default:
    break;
  }
  




  // if(shouldRead_){
  //   readMsg();
  //   sendMsg();
  // }

  // potValue = analogRead(pinPOT);
  // //Serial.println(potValue);          // debug
  // delay(10);  // delais de 10 ms
}



void MenuPrincipalGestion()
{
  GestionJoystick();
  GestionBouttonMenu();
  switch (positionMenu)
  {
  case 0:
    LCD.EcrireLigne(MenuPrincipal[0],15,0);
    LCD.EcrireLigne(MenuPrincipal[1],15,1);
    break;

  case 1:
    LCD.EcrireLigne(MenuPrincipal[1],15,0);
    LCD.EcrireLigne(MenuPrincipal[2],15,1);
  break;

  case 2:
    LCD.EcrireLigne(MenuPrincipal[2],15,0);
    LCD.EcrireLigne(MenuPrincipal[3],15,1);
  break;

  case 3:
    LCD.EcrireLigne(MenuPrincipal[3],15,0);
    LCD.EcrireLigne(MenuPrincipal[4],15,1);
  break;

  case 4:
    LCD.EcrireLigne(MenuPrincipal[4],15,0);
    LCD.EcrireLigne(MenuPrincipal[0],15,1);
  break;
  
  default:
    break;
  }
  LCD.Cursor(true, 0, 0);
  delay(10);
}

void MenuJoystick()
{
  GestionBouttonMenu();
  int joyx, joyy;

  joystick.GetAll(&joyx, &joyy);

  AfficheValDec(joyx, 2, 2);
  AfficheValDec(joyy, 9, 2);

}

void MenuBouton()
{
  GestionBouttonMenu();
}

void MenuAccelerometre()
{
  GestionBouttonMenu();
}

void MenuMoteur()
{
  GestionBouttonMenu();
}

void MenuBargraphe()
{
  GestionBouttonMenu();
}


void GestionBouttonMenu()
{
  static etatBoutton oldEtat;

  if(b1.Update() == etatBoutton::BouttonAppuyer && oldEtat == etatBoutton::BouttonRelacher)
  {
    oldEtat = etatBoutton::BouttonAppuyer;
    if(Menu == 0)
    {
      Menu = positionMenu+1;
    }
    else
    {
      Menu = 0;
    }
  }
  else
  {
    oldEtat = b1.Update();
  }
}

void GestionJoystick()
{
  static etatJoystick oldEtat;

  if(joystick.updateJoystickMenuY() == etatJoystick::JoystickDown && (oldEtat == etatJoystick::JoystickMiddle || oldEtat == etatJoystick::JoystickUp))
  {
    oldEtat = etatJoystick::JoystickDown;
    if(positionMenu >= MENUHEIGHT -1)
    {
      positionMenu = 0;
    }
    else
    {
      positionMenu++;
    }

  }
  else if(joystick.updateJoystickMenuY() == etatJoystick::JoystickUp && (oldEtat == etatJoystick::JoystickMiddle || oldEtat == etatJoystick::JoystickDown))
  {
    oldEtat = etatJoystick::JoystickUp;
    if(positionMenu <= 0)
    {
      positionMenu = MENUHEIGHT-1;
    }
    else
    {
      positionMenu--;
    }
    

  }
  else
  {
    oldEtat = joystick.updateJoystickMenuY();
  }
}


void AfficheValDec(int val, int x, int y)
{
  int offset = 0, valTemp = val;
  for(int i = 1000; i >= 1; i=i/10)
  {
    int compt = 0;
    val = valTemp;
    while(valTemp>= i)
    {
      valTemp = valTemp - i;
      compt++;
      Serial.print("i: ");
      Serial.print(i);
      Serial.print("  valTemp: ");
      Serial.print(valTemp);
      Serial.print("  compt: ");
      Serial.println(compt);
    }
    valTemp = val - i*compt;
    LCD.EcrireData(compt+0x30, x+offset, y); 
    offset++;   
  }
}



/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg() {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["time"] = millis();
  doc["analog"] = potValue;

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Analyse des éléments du message message
  parse_msg = doc["led"];
  if (!parse_msg.isNull()) {
    // mettre la led a la valeur doc["led"]
    digitalWrite(pinLED,doc["led"].as<bool>());
  }
}