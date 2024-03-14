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
    
        ptrniveau->addRaftPlayer(gamedata["niveau"]["frendlylisteboat"][i]["width"],
                                 gamedata["niveau"]["frendlylisteboat"][i]["height"], gamedata["niveau"]["frendlylisteboat"][i]["corodoneeX"],
                                 gamedata["niveau"]["frendlylisteboat"][i]["corodoneeY"], gamedata["niveau"]["frendlylisteboat"][i]["image"],
                                 gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"].size(), i);
        for (int j = 0; j < gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"].size(); j++)
        {
            int posxboat = gamedata["niveau"]["frendlylisteboat"][i]["corodoneeX"];
            int posyboat = gamedata["niveau"]["frendlylisteboat"][i]["corodoneeY"];
            int posx = gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"][j]["corodoneeX"];
            int posy = gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"][j]["corodoneeY"];
            ptrniveau->playerBoats[i]->characters[j] = new PlayerCharacter(posx + posxboat, posy + posyboat, gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"][j]["width"], gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"][j]["height"], gamedata["niveau"]["frendlylisteboat"][i]["listeplayer"][j]["image"]);
            ptrniveau->playerBoats[i]->addCharacter(ptrniveau->playerBoats[i]->characters[j]);
        }
    }
  
    for (int i = 0; i < gamedata["niveau"]["enemylisteboat"].size(); i++)
    {
        ptrniveau->addRaftenemy(gamedata["niveau"]["enemylisteboat"][i]["width"],
                                gamedata["niveau"]["enemylisteboat"][i]["height"], gamedata["niveau"]["enemylisteboat"][i]["corodoneeX"],
                                gamedata["niveau"]["enemylisteboat"][i]["corodoneeY"], gamedata["niveau"]["enemylisteboat"][i]["image"],
                                gamedata["niveau"]["enemylisteboat"][i]["listeplayer"].size(), i);
        for (int j = 0; j < gamedata["niveau"]["enemylisteboat"][i]["listeplayer"].size(); j++)
        {
            int posxboat = gamedata["niveau"]["enemylisteboat"][i]["corodoneeX"];
            int posyboat = gamedata["niveau"]["enemylisteboat"][i]["corodoneeY"];
            int posx = gamedata["niveau"]["enemylisteboat"][i]["listeplayer"][j]["corodoneeX"];
            int posy = gamedata["niveau"]["enemylisteboat"][i]["listeplayer"][j]["corodoneeY"];
            ptrniveau->enemyBoats[i]->characters[j] = new EnemyCharacter(posx + posxboat, posy + posyboat, gamedata["niveau"]["enemylisteboat"][i]["listeplayer"][j]["width"], gamedata["niveau"]["enemylisteboat"][i]["listeplayer"][j]["height"], gamedata["niveau"]["enemylisteboat"][i]["listeplayer"][j]["image"]);
            ptrniveau->enemyBoats[i]->addCharacter(ptrniveau->enemyBoats[i]->characters[j]);
        }
    }
}
