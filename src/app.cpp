#include <iostream>

#include "app.h"
#include "appcontext.h"

void App::run() {
    AppContext::get().get_gameserver_service()
            .launch(m_Args.get_modes(),
                    m_Args.get_what_tags(),
                    m_Args.get_player_tag(),
                    m_Args.get_wordlen());
}
