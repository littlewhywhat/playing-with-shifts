#include <iostream>

#include "app.h"
#include "gameserver.h"

void App::run() {
    try {
        for (GameServer * gs : m_Args.servers())
            gs -> launch();
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
}
