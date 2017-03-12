#include <iostream>

#include "app.h"
#include "gameserver.h"

void App::run() {
	for (GameServer * gs : m_Args.servers())
    	try {
            gs -> launch();
    	} catch (const char * e) {
        	//std::cout << e << std::endl;
    	}
}
