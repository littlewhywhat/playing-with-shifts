#include <iostream>

#include "langconsole.h"
#include "maxbcntplayer.h"

const uint32_t WORDLEN_ID = 1;
const uint32_t GAME_MODE_ID = 2;
const uint32_t LANG_TAG_ID = 3;
const uint32_t CNT_ARGS = 4;

void print_usage(std::ostream & out, char * argv[], const uint32_t & num_args) {
    out << "You just called: " << std::endl;
    for (uint32_t i = 0; i < num_args; i++)
        out << argv[i] << ' ';
    out << std::endl;   
    out << "Wrong number of arguments: " << num_args - 1 << std::endl
        << "instead of " << CNT_ARGS - 1<< std::endl;
    out << "Usage: " << std::endl
        << argv[0] << " wordlen mcode subsh_tag" << std::endl;
}

int main(int argc, char * argsv[]) {
    if (argc != CNT_ARGS) {
        print_usage(std::cout, argsv, argc);
        return 1;
    }
    std::string lang_tag = argsv[LANG_TAG_ID];
    uint32_t game_mode = std::stoi(argsv[GAME_MODE_ID]);
    uint32_t wordlen = std::stoi(argsv[WORDLEN_ID]); 
    LangConsole lc(std::cout);
    lc.set_langbuilder(lang_tag);
    lc.load(game_mode, wordlen);
    MaxBCntPlayer mbc_player;
    mbc_player.play(lc);
    return 0;
}
