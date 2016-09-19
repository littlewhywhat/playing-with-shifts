#ifndef MODE2_H
#define MODE2_H

#include <cstdint>
#include <map>
#include <utility>
#include <set>
#include <list>

#include "mode.h"
#include "i_lttr_vector.h"

class Mode2 : public Mode {
  private:
    class Cmp {
      private:
        std::set<uint32_t> m_Bids;
      public:
        Cmp(const std::vector<uint32_t> & bids) {
            for (auto bid : bids)
                m_Bids.insert(bid);
        }
        bool operator() (const std::string & a, const std::string & b) const {
            if (a.length() != b.length())
                return true;
            for (uint32_t i = 0; i < a.length(); i++) {
                if (m_Bids.find(i) == m_Bids.end() && a.at(i) != b.at(i)) {
                    return true;
                }
            }
            return false;
        }
    };
  public:
    ~Mode2() override {}
    bool good_strat(const Strategy & s, const WordTable & wt) const override {
        uint32_t max = (uint32_t)1 << s.bids().size();
        Cmp c(s.bids());
        std::map<std::string, uint32_t, Cmp> g_words(c);
        std::list<std::string> s_words;
        for (uint32_t i = 0; i < max; i++) {
            i_lttr_vector id_letters;
            make_id_letters(id_letters, i, s);
            s_words = wt.findAll(id_letters);
            if (s_words.empty())
                return false;
            if (i == 0)
                for (auto word : s_words)
                    g_words.insert(std::make_pair(word, 1));
            else {
                for (auto word : s_words) {
                    auto search = g_words.find(word);
                    if (search != g_words.end())
                        (*search).second += 1;
                }
            }
        }
        for (auto word : s_words) {
            auto search = g_words.find(word);
            if (search != g_words.end() && (*search).second == max)
                return true;
        }
        return false;
    }
};

#endif
