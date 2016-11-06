#include "app.h"
#include "argsparser.h"

int main(int argc, char * argsv[]) {
    ArgsParser args;
    args.parse(argc, argsv);
    App app(args);
    app.run();
    return 0;
}
