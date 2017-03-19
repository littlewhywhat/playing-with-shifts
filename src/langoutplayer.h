#ifndef LANGOUTPLAYER_H
#define LANGOUTPLAYER_H

#include <algorithm>

#include "console.h"
#include "player.h"

class LangOutPlayer : public Player {
  private:
    void precompute(Console & console) override {
        console.print_lang();
    }
  public:
    LangOutPlayer() : Player() {}
    static Player * create() { return new LangOutPlayer(); }
};

#endif
