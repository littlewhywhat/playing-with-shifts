#include <iostream>

#include "app.h"
#include "argsparser.h"

int main (int argc, char * argv[]) {
    try { 
        ArgsParser args(std::cout, argc, argv);
        App app(std::cout, args.getFilename(),
                           args.getWordLen(),
                           args.getModeCode());
        app.run();
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }   
    return 0;
}
