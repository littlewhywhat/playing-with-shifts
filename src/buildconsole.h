#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <ostream>

#include "console.h"
#include "langbuilder.h"
#include "language.h"

class BuildConsole : public Console {
  public:
    BuildConsole() : Console() {}
    std::set<std::string> start(const uint32_t & wordlen) override;
    static Console * create() {
        return new BuildConsole();
    }
};

#endif
