#ifndef LANGUAGE_H
#define LANGUAGE_H

class Language {
  public:
    virtual ~Language() {};
    virtual bool has(uint64_t word, const uint32_t & wordlen) const = 0;
};

#endif
