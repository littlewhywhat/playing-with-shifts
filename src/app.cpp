#include <iostream>

#include "app.h"
#include "gameserver.h"

App::void run() {
    try {
        for (GameServer * gs : m_Args.servers())
            gs -> launch();
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
}
