#include "console.h"
#include "player.h"
#include "strategy.h"

void Player::play(Console & console) {
    reset_score();
    if (m_OutLang) {
        console.out() << "language:" << std::endl;
        console.print_lang();
        console.out() << std::endl;
    }
    precompute(console);
    uint64_t strat_bound = (uint64_t) 1 << console.wordlen();
    for (uint64_t strat_val = 0; strat_val < strat_bound; strat_val++) {
        Strategy strat(strat_val, console.wordlen());
        compute(console, strat);
    }
    postcompute(console);
}
