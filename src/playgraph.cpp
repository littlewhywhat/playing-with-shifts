#include <iostream>

#include "graphconsole.h"
#include "maxbcntplayer.h"
#include "argsparser.h"

int main (int argc, char * argv[]) {
    try { 
        ArgsParser args(std::cout, argc, argv);
        GraphConsole gc(std::cout, args.getFilename());
        gc.load(args.getModeCode(), args.getWordLen());
        MaxBCntPlayer * mbc_player = new MaxBCntPlayer();
        mbc_player -> play(gc); 
        delete mbc_player; 
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }   
    return 0;
}
