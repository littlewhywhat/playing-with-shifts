#include <ostream>
#include <string>

#include "converter.h"
#include "wordtable.h"

uint32_t WordTable::size() const {
    return m_Words.size();
}
void WordTable::add(const std::string & word) {
    m_Words.push_back(Converter::s2i(word));
}

void WordTable::clear() {
    m_Words.clear();
}
