#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

class Language {
  public:
    Language() {}
    virtual ~Language() {}
    virtual void add(const std::string & word) = 0;
    virtual void clear() = 0;
};
#endif
