#include <cstdint>

#include "language.h"
#include "langbuilder.h"
#include "utils"

void LangBuilder::build(Language & lang) const {
    uint64_t max_comb = 1 << ((uint64_t) lang.wordlen());
    for (uint64_t comb = 0; comb < max_comb; comb++) 
        if (is_relevant(comb, lang.wordlen()))
            lang.add(i2s(comb, lang.wordlen()));
}
