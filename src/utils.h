#ifndef UTILS_H
#define UTILS_H

uint64_t s2i(const std::string & s) {
    uint64_t i = 0;
    for (uint32_t pos = 0; pos < s.length(); pos++)
        if (s.at(pos) - '0')
            i += 1 << pos;
    return i;
}

std::string i2s(uint64_t val, uint32_t wordlen) {
    std::string s;
    for (uint32_t i = 0; i < wordlen; i++) {
        s.push_back((val & 1) + '0');
        val >>= 1;
    }
    return s;
}

#endif
