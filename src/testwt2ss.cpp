#include <cstdint>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>

#include "worddata.h"
#include "wordtable.h"
#include "wordtree.h"
#include "strategy.h"
#include "game.h"
#include "gamefactory.h"

std::list<std::string> play(const Game & game) {
    std::list<std::string> l;
    std::stringstream ss;
    uint32_t max_strat = (uint32_t)1 << game.wordlen();
    for (uint32_t i = 0; i < max_strat; i++) {
        Strategy s(i, game.wordlen());
        if (game.play(s)) {
            ss << s;
            l.push_back(ss.str());
            ss.str(std::string());
            ss.clear();
        }
    }
    return l;
}

class GsReader {
  public: 
    void read(WordData & wd, const char * path) {
        std::fstream fs(path);

        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            wd.add(buffer);
        }
    }
};

const int PATH_ID = 1;
const int STRAT_LEN_ID = 2;
const int MODE_CODE_ID = 3;

int main(int argc, char * argv[]) {
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    uint32_t game_mode = std::stoi(argv[MODE_CODE_ID]);
    Game * game = GameFactory::get() -> create_instance(game_mode, strat_len);
    GsReader gsr;
    gsr.read(game -> wd(), argv[PATH_ID]);
    std::list<std::string> res = play(*game);
    delete game;
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
