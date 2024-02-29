#include "gameloder.h"
#include <iostream>
#include <fstream>
#include <json.hpp>
#include "niveau.h"
using json =nlohmann::json;
gameloder::gameloder()
{
}

gameloder::~gameloder()
{
}

void gameloder::getlevelsformeJson(){
std::ifstream game_file("level1seting.json");
json gamedata = json::parse(game_file);

Niveau* ptrniveau;
ptrniveau= new Niveau(gamedata["niveau"]["wight"],gamedata["niveau"]["hieght"],gamedata["niveau"]["image"]);
for(int i=0; i<gamedata["niveau"]["frendlylisteboat"].size();i++){
    ptrniveau->addRaft(gamedata["niveau"]["frendlylisteboat"]["wight"],
                        gamedata["niveau"]["frendlylisteboat"]["hieght"],gamedata["niveau"]["frendlylisteboat"]["corodoneeX"],
                        gamedata["niveau"]["frendlylisteboat"]["corodoneeX"],gamedata["niveau"]["frendlylisteboat"]["image"]);
    
}
}
