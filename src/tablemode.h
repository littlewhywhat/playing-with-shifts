#ifndef TABLEMODE_H
#define TABLEMODE_H

#include <cstdint>
#include <vector>

#include "strategy.h"
#include "wordtable.h"

class TableMode : public Mode {
  private:
    const WordTable * m_WT;
    bool has_wd() const override {
        return m_WT;
    }
    bool good_strat_ch(const Strategy & s) const override {
        if (!s.val())
            return true;
        const uint64_t max_comb_val = ((uint64_t) 1) << s.Bcnt();
        if (max_comb_val > get_wt().size())
            return false;
        return good_strat_tm(max_comb_val, s.val());
    }     
    virtual bool good_strat_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const = 0;
  protected:
    const WordTable & get_wt() const {
        return *m_WT;
    }
  public:
    virtual ~TableMode() {};
    void set_wd(const WordTable & wt) override {
        m_WT = &wt;
    }
};

#endif
