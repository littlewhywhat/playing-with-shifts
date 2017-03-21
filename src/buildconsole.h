#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <ostream>

#include "console.h"

class BuildConsole : public Console {
  public:
    BuildConsole() : Console() {}
    virtual bool is_relevant(uint64_t comb, const uint32_t & wordlen) const = 0;
    void start(Language &lang, const uint32_t &wordlen) override;
};

#endif
