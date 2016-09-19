#ifndef I_LTTR_VECTOR_H
#define I_LTTR_VECTOR_H

#include <vector>
#include <utility>
#include <cstdint>

#include "strategy.h"

class Comb {
  private:
     std::vector<std::pair<uint32_t, char>> m_Id_Lttrs;
  public:
     Comb(uint64_t val, const Strategy & s) {
        uint64_t mask = 1;
        for (uint32_t bid : s.bids()) {
            char letter = (val & mask) + '0';
            m_Id_Lttrs.push_back(std::make_pair(bid, letter));
            val >>= 1;
        }
     }
     const std::vector<std::pair<uint32_t, char>> vals() const {
     	return m_Id_Lttrs;
     }
};

#endif
