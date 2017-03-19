#include <cstdint>

#include "language.h"
#include "langbuilder.h"
#include "converter.h"

void LangBuilder::build(const uint32_t & wordlen, std::set<std::string> & wordset) const {
    uint64_t max_comb = 1 << ((uint64_t) wordlen);
    for (uint64_t comb = 0; comb < max_comb; comb++) 
        if (is_relevant(comb, wordlen))
            wordset.insert(Converter::i2s(comb, wordlen));
}
