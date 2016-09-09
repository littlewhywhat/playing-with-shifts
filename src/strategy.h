#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy {
  private:
    int m_Val;
  public:
    Strategy(int val) : m_Val(val) {}
    void incr() { m_Val++; }
    int32_t countB() {
        int val = m_Val;
        int32_t i = 0;
        while (val != 0) {
            if (val % 2 != 0)
                i++;
            val /= 2;
        }
        return i;
    }
};

#endif