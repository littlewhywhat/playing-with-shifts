#ifndef LANGREADER_H
#define LANGREADER_H

#include <string>
#include <set>
#include "language.h"

class LangReader {
  public: 
    void read(const std::string & path, Language & wordset) const;
};

#endif
