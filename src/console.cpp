#include "console.h"
#include "game.h"
#include "gamefactory.h"
#include "language.h"
#include "strategy.h"

void Console::set_setup(const std::string & setup) {
    m_Setup = setup;
}
void Console::load(const uint32_t & game_mode) {
    m_Game = GameFactory::get() -> create_instance(game_mode, m_WordLen);
    if (!m_Game)
        throw "No such game mode.";
    for (auto & word : m_WordSet)
        game().add_word(word);
}


