#include <cstdint>
#include <string>
#include <iostream>

#include "langconsole.h"
#include "player.h"

const int PATH_ID = 1;
const int STRAT_LEN_ID = 2;
const int MODE_CODE_ID = 3;

int main(int argc, char * argv[]) {
    std::string path = argv[PATH_ID];
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    uint32_t game_mode = std::stoi(argv[MODE_CODE_ID]);
    LangConsole lc(std::cout, path);
    lc.load(game_mode, strat_len);
    Player player;
    player.set_out_result(true);
    player.play(lc);
    return 0;
}
