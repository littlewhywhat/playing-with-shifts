#ifndef MAXBCNT_H
#define MAXBCNT_H

#include <cstdint>
#include <ostream>

#include "mode.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"
#include "strategy.h"

class MaxBCnt {
  private:
    uint32_t m_WordLen;
    WordData * m_WordData;
    Mode * m_Mode;
    void set_mode(const uint32_t & mode_code) {
        switch (mode_code) {
            case 1: m_Mode = new Mode1();
                    break;
            case 2: m_Mode = new Mode2();
                    break;
            case 3: m_Mode = new Mode3();
                    break;
            default: throw "Invalid mode code!";
        }
    }
    void set_worddata(const uint32_t & mode_code, const uint32_t & wordlen) {
        if (mode_code == 3)
            m_WordData = new WordTree();
        else
            m_WordData = new WordTable(wordlen);
    }
  public:
    MaxBCnt() : m_WordLen(0), m_WordData(NULL), m_Mode(NULL) {} 
    MaxBCnt(const uint32_t & mode_code, const uint32_t & wordlen) : m_WordLen(wordlen) {
        set(mode_code, wordlen);
    }
    void set(const uint32_t & mode_code, const uint32_t & wordlen) {
        m_WordLen = wordlen;
        set_worddata(mode_code, wordlen);
        set_mode(mode_code);
    }
    WordData & data() {
        return *m_WordData;
    }
    uint32_t compute(std::ostream * out) const {
        uint32_t maxBcnt = 0;   
        if (out)
            *out << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << m_WordLen;
        m_WordData -> set_wd(*m_Mode);
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
        //for (uint64_t strat_val = strat_bound - 1; strat_val > 0; strat_val--) {
            Strategy strat(strat_val, m_WordLen);
            uint32_t bcnt = strat.Bcnt();
            if (bcnt > maxBcnt && m_Mode -> good_strat(strat)) {
                if (out)
                    *out << strat << std::endl;
                maxBcnt = bcnt;
            }
        }
        return maxBcnt;
    }
};

#endif
