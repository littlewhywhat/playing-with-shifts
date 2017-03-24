#include <iostream>

#include "app.h"
#include "appcontext.h"

void App::run(int argc, char * argsv[]) {
    ArgsParser parser;
    AppConfig config;
    parser.parse(argc, argsv, config);
    AppContext::get().setup(config);
    if (config.defines_generator())
        AppContext::get().get_graphgenerator_service()
                .generate(config.get_pathname(),
                          config.get_cntnodes(),
                          config.get_cntgraphs());
    if (config.defines_server())
        AppContext::get().get_gameserver_service()
                .launch(config.get_gamemodes(),
                        config.get_langhostids(),
                        config.get_playertag(),
                        config.get_wordlen());
}
