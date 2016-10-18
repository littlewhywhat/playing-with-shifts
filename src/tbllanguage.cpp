#include <ostream>
#include <string>

#include "utils.h"
#include "tbllanguage.h"

uint32_t TblLanguage::size() const {
    return m_Words.size();
}
void TblLanguage::add(const std::string & word) override {
    m_Words.push_back(s2i(word));
}
std::ostream & print(std::ostream & out) const override {
    for (auto word : m_Words)
        out << i2s(word, wordlen()) << std::endl;
    return out;
}
