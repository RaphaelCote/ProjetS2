#include <iostream>
#include <fstream>

#include "gameloader.h"
#include "../include/json.hpp"
#include "niveau.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"
#include "utility.h"

using json = nlohmann::json;

Gameloader::Gameloader()
{
}

Gameloader::~Gameloader()
{
}

Niveau *Gameloader::getLevelFromJson(string filename)
{
    // To test
    // "./levels/levelTemplate.txt"
    std::ifstream gameFile(filename);

    std::stringstream buffer;
    buffer << gameFile.rdbuf();
    string gameFileString = buffer.str();

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
            int posxboat = gamedata["level"]["friendlyboatlist"][i]["coordoneeX"];
            int posyboat = gamedata["level"]["friendlyboatlist"][i]["coordoneeY"];
            int posx = gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["coordoneeX"];
            int posy = gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["coordoneeY"];

            niveau->playerBoats[i]->characters[j] = new PlayerCharacter(posx + posxboat, posy + posyboat, gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["width"], gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["height"], gamedata["level"]["friendlyboatlist"][i]["characterlist"][j]["image"]);
            niveau->playerBoats[i]->addCharacter(niveau->playerBoats[i]->characters[j]);
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
            int posxboat = gamedata["level"]["enemyboatlist"][i]["coordoneeX"];
            int posyboat = gamedata["level"]["enemyboatlist"][i]["coordoneeY"];
            int posx = gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["coordoneeX"];
            int posy = gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["coordoneeY"];

            niveau->enemyBoats[i]->characters[j] = new EnemyCharacter(posx + posxboat, posy + posyboat, gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["width"], gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["height"], gamedata["level"]["enemyboatlist"][i]["characterlist"][j]["image"]);
            niveau->enemyBoats[i]->addCharacter(niveau->enemyBoats[i]->characters[j]);
        }
    }

    return niveau;
}