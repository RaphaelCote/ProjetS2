#include <iostream>
#include <fstream>
#include <sstream>
//fstream permet de traiter des fichiers
#include "gameloader.h"
#include "../include/json.hpp"
#include "niveau.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"
#include "utility.h"
// si on ne met pas �a, sa scarp le code laule/lol
//sstream permet de manipuler des strings en m�moire 
using json = nlohmann::json;

Gameloader::Gameloader()
{
}

Gameloader::~Gameloader()
{
}

Niveau *Gameloader::getLevelFromJson(std::string filename)
{
    // To test
    // "./levels/levelTemplate.txt"
    
    std::ifstream gameFile(filename);// en th�orie c'est  <fstream> qui doit �tre include pour cela 

    std::stringstream buffer;//en th�orie c'est <sstream> qui doit �tre include pour cela 
    buffer << gameFile.rdbuf();
    std::string gameFileString = buffer.str();

    json gamedata = json::parse(gameFileString);

    Niveau *niveau = new Niveau(gamedata["level"]["width"], gamedata["level"]["height"], gamedata["level"]["image"]);

    for (int i = 0; i < gamedata["level"]["friendlyboatlist"].size(); i++)
    {
        Coordonnee bateau;
        bateau.x = gamedata["level"]["friendlyboatlist"][i]["coordoneeX"];
        bateau.y = gamedata["level"]["friendlyboatlist"][i]["coordoneeY"];
        niveau->addRaftPlayer(gamedata["level"]["friendlyboatlist"][i]["width"],
                              gamedata["level"]["friendlyboatlist"][i]["height"],
                              bateau,
                              gamedata["level"]["friendlyboatlist"][i]["image"],
                              gamedata["level"]["friendlyboatlist"][i]["characterlist"].size());

        for (int j = 0; j < gamedata["level"]["friendlyboatlist"][i]["characterlist"].size(); j++)
        {
            Coordonnee player;
            Hitbox hitboxplayer;
            int posxboat = gamedata["level"]["friendlyboatlist"][i]["coordoneeX"];
            int posyboat = gamedata["level"]["friendlyboatlist"][i]["coordoneeY"];
            int posx = gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["coordoneeX"];
            int posy = gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["coordoneeY"];
            player.x = posx + posxboat;
            player.y = posy + posyboat;
            hitboxplayer.width = gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["width"];
            hitboxplayer.height = gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["height"];

            niveau->playerBoats[i]->addCharacter(new PlayerCharacter(player, hitboxplayer, gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["image"]));
        }
    }

    for (int i = 0; i < gamedata["level"]["enemyboatlist"].size(); i++)
    {
        Coordonnee bateau;
        bateau.x = gamedata["level"]["enemyboatlist"][i]["coordoneeX"];
        bateau.y = gamedata["level"]["enemyboatlist"][i]["coordoneeY"];
        niveau->addRaftenemy(gamedata["level"]["enemyboatlist"][i]["width"],
                             gamedata["level"]["enemyboatlist"][i]["height"],
                             bateau,
                             gamedata["level"]["enemyboatlist"][i]["image"],
                             gamedata["level"]["enemyboatlist"][i]["characterlist"].size());

        for (int j = 0; j < gamedata["level"]["enemyboatlist"][i]["characterlist"].size(); j++)
        {
            Coordonnee enemy;
            Hitbox hitboxenemy;
            int posxboat = gamedata["level"]["enemyboatlist"][i]["coordoneeX"];
            int posyboat = gamedata["level"]["enemyboatlist"][i]["coordoneeY"];
            int posx = gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["coordoneeX"];
            int posy = gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["coordoneeY"];
            enemy.x = posx + posxboat;
            enemy.y = posy + posyboat;
            hitboxenemy.height = gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["height"];
            hitboxenemy.width = gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["width"];

            niveau->enemyBoats[i]->addCharacter(new EnemyCharacter(enemy, hitboxenemy, gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["image"]));
        }
    }

    return niveau;
}
