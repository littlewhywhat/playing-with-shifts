#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

class WordStructure {
  public:
    WordStructure() {}
    virtual ~WordStructure() {}
    virtual void add(const std::string & word) = 0;
    virtual void clear() = 0;
};
#endif
