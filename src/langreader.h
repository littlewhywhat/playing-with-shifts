#ifndef LANGREADER_H
#define LANGREADER_H

#include <string>
#include <set>

#include "language.h"

class LangReader {
  public: 
    void read(const std::string & path, std::set<std::string> & wordset) const;
};

#endif
