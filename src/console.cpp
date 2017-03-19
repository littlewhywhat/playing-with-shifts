#include "console.h"
#include "game.h"
#include "gamefactory.h"
#include "language.h"
#include "strategy.h"

void Console::load(const uint32_t & game_mode) {
    m_Game = GameFactory::get() -> create_instance(game_mode, m_WordLen);
    if (!m_Game)
        throw "No such game mode.";
    for (auto & word : m_WordSet)
        game().add_word(word);
}

bool Console::play(const Strategy &strategy) const {
    if (!m_Game)
        throw "There is no game loaded.";
    return game().play(strategy);
}

void Console::print_lang() const {
    for (auto & word : m_WordSet)
        m_Out << word << std::endl;
}
