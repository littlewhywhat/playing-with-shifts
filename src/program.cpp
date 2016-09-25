#include <iostream>

#include "app.h"
#include "argsparser.h"

int main (int argc, char * argv[]) {
    try { 
        ArgsParser args(std::cout, argc, argv);
        App app(args.getFilename(),
                args.getWordLen(),
                args.getModeCode());
        app.run(&std::cout);
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }   
    return 0;
}
