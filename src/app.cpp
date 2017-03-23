#include <iostream>

#include "app.h"
#include "gameroom.h"

void App::run() {
	for (GameRoom * gs : m_Args.servers())
    	try {
            gs -> launch();
    	} catch (const char * e) {
        	//std::cout << e << std::endl;
    	}
}
