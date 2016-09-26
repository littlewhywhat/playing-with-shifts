#ifndef SUBSHIFT_H
#define SUBSHIFT_H

class Subshift {
  public:
    virtual ~Subshift() {};
    virtual bool in(uint64_t word, const uint32_t & wordlen) const = 0;
};

#endif
