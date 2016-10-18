#include "console.h"
#include "game.h"
#include "gamefactory.h"
#include "language.h"
#include "strategy.h"

void Console::set_setup(const std::string & setup) {
    m_Setup.clear();
    m_Setup += setup;
}
void Console::load(const uint32_t & game_mode, const uint32_t & wordlen) {
    m_Game = GameFactory::get() -> create_instance(game_mode, wordlen);
    if (!m_Game)
        throw "No such game mode.";
    fill(game().lang());
}
