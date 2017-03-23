#ifndef SuccessPLAYER_H
#define SuccessPLAYER_H

#include "languageservice.h"
#include "player.h"

class SuccessPlayer : public Player {
  private:
    Strategy m_MaxStrategy;
  protected:
    Strategy m_PrevStrategy;
  public:
    SuccessPlayer(const uint32_t & len) : Player(),
                                          m_MaxStrategy(Strategy::MAX(len)),
                                          m_PrevStrategy(Strategy::MIN(len)) {}
    bool has_next() const override;
    const Strategy & next_strategy(const uint32_t & score) override;
    void reset() override;

    static Player * create(const uint32_t & len) {
        return new SuccessPlayer(len);
    }
};

#endif
