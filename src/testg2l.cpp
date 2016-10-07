#include <cstdint>
#include <iostream>

#include "graphconsole.h"

const uint32_t PATH_ID = 1;
const uint32_t LEN_ID = 2;
const uint32_t GAME_MODE_ID = 3;

int main(int argc, char * argsv[]) {
    const char * filename = argsv[PATH_ID];
    GraphConsole gc(std::cout, filename);
    int wordlen = std::stoi(argsv[LEN_ID]);
    int game_mode = std::stoi(argsv[GAME_MODE_ID]);
    gc.load(game_mode, wordlen);
    std::cout << gc.lang(); 
    return 0;
}
