#include <iostream>

#include "app.h"
#include "appcontext.h"

void App::run(int argc, char * argsv[]) {
    ArgsParser parser;
    Bundle config;
    ApplicationArguments arguments(argc, argsv);
    parser.parse(arguments, config);
    AppContext::get().setup(config);
    //AppContext::get().get_graphgenerator_service()
    //            .generate(config);
    AppContext::get().get_gameserver_service()
                .launch(config);
}
