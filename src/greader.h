#ifndef GREADER_H
#define GREADER_H

#include <string>

#include "graph.h"

class GReader {
  private:
    const static char DELIM = ',';
  public: 
    void read(Graph & g, const std::string & path) const;
};

#endif
