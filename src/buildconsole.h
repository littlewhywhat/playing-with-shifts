#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <ostream>

#include "console.h"
#include "langbuilder.h"

class BuildConsole : public Console {
  public:
    BuildConsole() : Console() {}
    void start(Language &lang, const uint32_t &wordlen) override;
    static Console * create() {
        return new BuildConsole();
    }
};

#endif
