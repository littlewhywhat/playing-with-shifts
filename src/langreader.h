#ifndef LANGREADER_H
#define LANGREADER_H

#include <string>

#include "language.h"

class LangReader {
  public: 
    void read(Language & lang, const std::string & path) const; 
};

#endif
