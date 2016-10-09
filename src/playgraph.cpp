#include <iostream>

#include "graphconsole.h"
#include "maxbcntplayer.h"
#include "argsparser.h"
#include "gameserver.h"

int main (int argc, char * argv[]) {
    try { 
        ArgsParser args(std::cout, argc, argv);
        GraphConsole gc(std::cout, args.getFilename());
        gc.set_wordlen(args.getWordLen());
        MaxBCntPlayer mbc_player;
        mbc_player.set_out_result(true);
        mbc_player.set_out_lang(true);
        std::vector<uint32_t> game_modes;
        game_modes.push_back(args.getModeCode());
        GameServer gs(gc, mbc_player, game_modes);
        gs.launch();
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }   
    return 0;
}
