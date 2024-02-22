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
#include "Accelerometre.h"
#include "Moteur.h"
#include "Bargraphe.h"

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle
#define MENUHEIGHT 5

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message
int ledState = 0;
int potValue = 0;
int pinLED = 7;
int pinPOT = A7;




EcranLCD LCD;
Joystick joystick(A3, A4);
Accelerometre Acc(A0, A1, A2);
Moteur Mot(9);
Bargraphe Bar;

Boutton b1(34);
Boutton b2(35);
Boutton b3(36);
Boutton b4(37);
Boutton b5(38);

int positionMenu = 0;
int oldPositionMenu = -1;
bool AfficheMenuPrincipal = true;
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

char TabMenuBoutton[2][16] = {"B2:     B3:    ",
                              "B4:     B5:    "};

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
  LCD.Cursor(true, 0, 0);
  // LCD.EcrireData('A');
  // LCD.EcrireData('L');
  // LCD.EcrireData('L');
  // LCD.EcrireData('O');
  // delay(2000);

  // LCD.ClearLCD();
  // AfficheValDec(1000,9,1);
  // delay(1000);
  // AfficheValDec(1234,2,1);
  // delay(1000);
  //LCD.EcrireTableau(MenuPrincipal,15,2);
}


void loop() 
{
  //delay(1000);
  
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
      AfficheMenuPrincipal = true;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(TabMenuAccel, 15, 2);
    }
    MenuAccelerometre();
    
    break;

  case 2://Menu Boutton
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      AfficheMenuPrincipal = true;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(TabMenuBoutton, 15, 2);
    }
    MenuBouton();
    
    break;

  case 3://BarGraphe
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      AfficheMenuPrincipal = true;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(tabMenuBargraphe, 15, 2);
    }
    MenuBargraphe();
    
    break;

  case 4://Moteur
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      AfficheMenuPrincipal = true;
      LCD.Cursor(false,0,0);
      LCD.EcrireTableau(tabMenuMoteur, 15, 2);
    }
    MenuMoteur();
    
    break;

  case 5://Joystick
    if(oldMenu != Menu)
    {
      oldMenu = Menu;
      AfficheMenuPrincipal = true;
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
    if(positionMenu != oldPositionMenu || AfficheMenuPrincipal)
    {
      oldPositionMenu = positionMenu;
      AfficheMenuPrincipal = false;
      LCD.EcrireLigne(MenuPrincipal[0],15,0);
      LCD.EcrireLigne(MenuPrincipal[1],15,1);
      LCD.Cursor(true, 0, 0);
    }
    
    
    break;

  case 1:
    if(positionMenu != oldPositionMenu || AfficheMenuPrincipal)
    {
      oldPositionMenu = positionMenu;
      AfficheMenuPrincipal = false;
      LCD.EcrireLigne(MenuPrincipal[1],15,0);
      LCD.EcrireLigne(MenuPrincipal[2],15,1);
      LCD.Cursor(true, 0, 0);
    }
    
  break;

  case 2:
    if(positionMenu != oldPositionMenu || AfficheMenuPrincipal)
    {
      oldPositionMenu = positionMenu;
      AfficheMenuPrincipal = false;
      LCD.EcrireLigne(MenuPrincipal[2],15,0);
      LCD.EcrireLigne(MenuPrincipal[3],15,1);
      LCD.Cursor(true, 0, 0);
    }
    
  break;

  case 3:
    if(positionMenu != oldPositionMenu || AfficheMenuPrincipal)
    {
      oldPositionMenu = positionMenu;
      AfficheMenuPrincipal = false;
      LCD.EcrireLigne(MenuPrincipal[3],15,0);
      LCD.EcrireLigne(MenuPrincipal[4],15,1);
      LCD.Cursor(true, 0, 0);
    }
    
  break;

  case 4:
    if(positionMenu != oldPositionMenu || AfficheMenuPrincipal)
    {
      oldPositionMenu = positionMenu;
      AfficheMenuPrincipal = false;
      LCD.EcrireLigne(MenuPrincipal[4],15,0);
      LCD.EcrireLigne(MenuPrincipal[0],15,1);
      LCD.Cursor(true, 0, 0);
    }
    
  break;
  
  default:
    break;
  }
}

void MenuJoystick()
{
  GestionBouttonMenu();
  int joyx, joyy;

  joystick.GetAll(&joyx, &joyy);

  AfficheValDec(joyx, 2, 1);
  AfficheValDec(joyy, 9, 1);

}

void MenuBouton()
{
  GestionBouttonMenu();

  if(b2.Update() == etatBoutton::BouttonAppuyer)
  {
    LCD.EcrireCharactere('1', 3, 0); 
  }
  else
  {
    LCD.EcrireCharactere('0', 3, 0); 
  }


  if(b3.Update() == etatBoutton::BouttonAppuyer)
  {
    LCD.EcrireCharactere('1', 11, 0); 
  }
  else
  {
    LCD.EcrireCharactere('0', 11, 0); 
  }


  if(b4.Update() == etatBoutton::BouttonAppuyer)
  {
    LCD.EcrireCharactere('1', 3, 1); 
  }
  else
  {
    LCD.EcrireCharactere('0', 3, 1); 
  }


  if(b5.Update() == etatBoutton::BouttonAppuyer)
  {
    LCD.EcrireCharactere('1', 11, 1); 
  }
  else
  {
    LCD.EcrireCharactere('0', 11, 1); 
  }
}

void MenuAccelerometre()
{
  GestionBouttonMenu();
  int xVal, yVal, zVal;

  Acc.GetAll(&xVal, &yVal, &zVal);

  AfficheValDec(xVal, 10, 0);
  AfficheValDec(yVal, 2, 1);
  AfficheValDec(zVal, 10, 1);

  
}

void MenuMoteur()
{
  static int puissance = 0;
  static int timer = millis();
  static bool sense = false;
  GestionBouttonMenu();

  if(millis() - timer >= 20)
  {
    timer = millis();
    if(puissance >= 255 || puissance <= 0)
      sense = !sense;

    if(sense)
      puissance++;
    else
      puissance--;

    Mot.ActualiseMoteur(puissance);
    AfficheValDec(puissance, 11, 0);
  }
}

void MenuBargraphe()
{
  static int puissance = 0;
  static unsigned long timer = millis();
  static unsigned long temps = 50;
  static bool sense = false;
  static int barLED = 0x00;
  static int mode = 1;
  GestionBouttonMenu();

  if(millis() - timer >= temps)
  {
    timer = millis();
    if(mode == 0)
    {
      temps = 50;

      if(puissance >= 100) sense = false;
      else if(puissance <= 0) sense = true;

      if(sense) puissance++;
      else puissance--;

      Bar.AllumeBargraphePuissance(puissance);
      AfficheValDec(puissance, 11, 0);
    }
    else if(mode == 1)//petit probleme
    {
      temps = 500; 
      barLED = barLED << 1;
      
      if((barLED & 0x0200) == 0x00) barLED += 1;

      Bar.AllumeBits(barLED);
      AfficheValDec(barLED & 0x03FF, 11, 0);
    }
    
  }

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
    else//revient au menu principal
    {
      Mot.ActualiseMoteur(0);
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


void AfficheValDec(int val, int xValue, int yValue)
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
    LCD.EcrireCharactere(compt+0x30, xValue+offset, yValue); 
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