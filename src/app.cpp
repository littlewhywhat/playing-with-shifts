#include <iostream>

#include "app.h"

void App::run() {
    m_Args.get_gameserver().launch();
}
