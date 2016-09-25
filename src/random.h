#include <ctime>

class Random {
  public:
    Random() {
        std::srand(std::time(0));
    }
    uint32_t randint(const uint32_t & to) const {
        if (!to)
            throw "NO!";
        return std::rand() % to;
    }
    uint32_t randint(const uint32_t & from, const uint32_t & to) const {
        if (from == to)
            return from;
        return randint(to - from) + from;
    }
    uint32_t randnode(const uint32_t & cnt_nodes) const {
        return randint(cnt_nodes);
    }
    uint32_t randlbl() const {
        return randint(2);
    }
};
