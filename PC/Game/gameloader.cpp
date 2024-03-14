#include <iostream>
#include <fstream>

#include "gameloader.h"
#include "../include/json.hpp"
#include "niveau.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"

using json = nlohmann::json;

Gameloader::Gameloader()
{
}

Gameloader::~Gameloader()
{
}

void Gameloader::getLevelsFromJson()
{
    std::ifstream gameFile("./levels/level1seting.json");

    std::stringstream buffer;
    buffer << gameFile.rdbuf();
    string gameFileString = buffer.str();

    json gamedata = json::parse(gameFileString);

    ptrniveau = new Niveau(gamedata["niveau"]["width"], gamedata["niveau"]["height"], gamedata["niveau"]["image"]);
    for (int i = 0; i < gamedata["niveau"]["frendlylisteboat"].size(); i++)
    {
        ptrniveau->addRaftPlayer(gamedata["niveau"]["frendlylisteboat"]["wight"],
                                 gamedata["niveau"]["frendlylisteboat"]["hieght"], gamedata["niveau"]["frendlylisteboat"]["corodoneeX"],
                                 gamedata["niveau"]["frendlylisteboat"]["corodoneeY"], gamedata["niveau"]["frendlylisteboat"]["image"],
                                 gamedata["niveau"]["frendlylisteboat"]["listeplayer"].size(), i);
        for (int j = 0; j < gamedata["niveau"]["frendlylisteboat"]["listeplayer"].size(); j++)
        {
            int posxboat = gamedata["niveau"]["frendlylisteboat"]["corodoneeX"];
            int posyboat = gamedata["niveau"]["frendlylisteboat"]["corodoneeY"];
            int posx = gamedata["niveau"]["frendlylisteboat"]["listeplayer"]["corodoneeX"];
            int posy = gamedata["niveau"]["frendlylisteboat"]["listeplayer"]["corodoneeY"];
            ptrniveau->playerBoats[i]->characters[j] = new PlayerCharacter(posx + posxboat, posy + posyboat, gamedata["niveau"]["frendlylisteboat"]["listeplayer"]["width"], gamedata["niveau"]["frendlylisteboat"]["listeplayer"]["height"], gamedata["niveau"]["frendlylisteboat"]["listeplayer"]["image"]);
            ptrniveau->playerBoats[i]->addCharacter(ptrniveau->playerBoats[i]->characters[j]);
        }
    }
    for (int i = 0; i < gamedata["niveau"]["enemylisteboat"].size(); i++)
    {
        ptrniveau->addRaftenemy(gamedata["niveau"]["enemylisteboat"]["wight"],
                                gamedata["niveau"]["enemylisteboat"]["hieght"], gamedata["niveau"]["enemylisteboat"]["corodoneeX"],
                                gamedata["niveau"]["enemylisteboat"]["corodoneeY"], gamedata["niveau"]["enemylisteboat"]["image"],
                                gamedata["niveau"]["enemylisteboat"]["listeplayer"], i);
        for (int j = 0; j < gamedata["niveau"]["enemylisteboat"]["listeplayer"].size(); j++)
        {
            int posxboat = gamedata["niveau"]["enemylisteboat"]["corodoneeX"];
            int posyboat = gamedata["niveau"]["enemylisteboat"]["corodoneeY"];
            int posx = gamedata["niveau"]["enemylisteboat"]["listeplayer"]["corodoneeX"];
            int posy = gamedata["niveau"]["enemylisteboat"]["listeplayer"]["corodoneeY"];
            ptrniveau->enemyBoats[i]->characters[j] = new EnemyCharacter(posx + posxboat, posy + posyboat, gamedata["niveau"]["enemylisteboat"]["listeplayer"]["width"], gamedata["niveau"]["enemylisteboat"]["listeplayer"]["height"], gamedata["niveau"]["enemylisteboat"]["listeplayer"]["image"]);
            ptrniveau->enemyBoats[i]->addCharacter(ptrniveau->enemyBoats[i]->characters[j]);
        }
    }
}
