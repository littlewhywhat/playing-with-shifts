#include <iostream>

#include "app.h"
#include "appcontext.h"

void App::run(int argc, char * argsv[]) {
    ArgsParser parser;
    Bundle config;
    ApplicationArguments arguments(argc, argsv);
    parser.parse(arguments, config);
    AppContext& context = AppContext::get();
    context.setup(config);
    switch (context.mode()) {
        case GRAPH_GENERATOR:
            context.get_graphgenerator_service().generate(config);
            return;
        case GAME_SERVER: 
            context.get_gameserver_service().launch(config);
            return;
    }
}
