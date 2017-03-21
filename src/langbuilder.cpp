#include <cstdint>

#include "langbuilder.h"
#include "converter.h"
#include "language.h"

void LangBuilder::build(const uint32_t & wordlen, Language & lang) const {
    uint64_t max_comb = 1 << ((uint64_t) wordlen);
    for (uint64_t comb = 0; comb < max_comb; comb++) 
        if (is_relevant(comb, wordlen))
            lang.insert(Converter::i2s(comb, wordlen));
}
