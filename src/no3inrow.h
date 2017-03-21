#ifndef NO3INROW_H
#define NO3INROW_H

#include "buildconsole.h"

class No3inRow : public BuildConsole {
  public:
    bool is_relevant(uint64_t word, const uint32_t & wordlen) const override; 
    static BuildConsole * create() { return new No3inRow(); }
};

#endif
