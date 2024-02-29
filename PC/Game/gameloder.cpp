#include "gameloder.h"
#include <iostream>
#include <fstream>
#include <json.hpp>
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



}
