#include <iostream>

#include "app.h"
#include "gameroom.h"

void App::run() {
    m_Args.get_gameserver().launch();
}
