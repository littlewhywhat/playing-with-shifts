#include <iostream>

#include "playgraph.h"
#include "argsparser.h"

int main (int argc, char * argv[]) {
    try { 
        ArgsParser args(std::cout, argc, argv);
        PlayGraph pg(args.getFilename(),
                args.getWordLen(),
                args.getModeCode());
        pg.run(&std::cout);
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }   
    return 0;
}
