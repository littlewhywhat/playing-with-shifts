#ifndef CONVERTER_H
#define CONVERTER_H

class Converter {
  public:  
    static uint64_t s2i(const std::string & s);
    static std::string i2s(uint64_t val, uint32_t wordlen);
};
#endif
