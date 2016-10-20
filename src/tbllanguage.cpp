#include <ostream>
#include <string>

#include "converter.h"
#include "tbllanguage.h"

uint32_t TblLanguage::size() const {
    return m_Words.size();
}
void TblLanguage::add(const std::string & word) {
    m_Words.push_back(Converter::s2i(word));
}
std::ostream & TblLanguage::print(std::ostream & out) const {
    for (auto word : m_Words)
        out << Converter::i2s(word, wordlen()) << std::endl;
    return out;
}
