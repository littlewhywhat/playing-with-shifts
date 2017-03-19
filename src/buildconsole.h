#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <ostream>

#include "console.h"
#include "langbuilder.h"
#include "language.h"

class BuildConsole : public Console {
  public:
    BuildConsole(std::ostream & out) : Console(out) {}
    void start() override;
    static Console * create(std::ostream & out) {
        return new BuildConsole(out);
    }
};

#endif
