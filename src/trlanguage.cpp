#include <string>
#include <ostream>

#include "tnode.h"
#include "trlanguage.h"

void TrLanguage::add_word(TNode & node, const std::string & word, uint32_t pos) {
    if (pos == word.length())
        return;
    if (word.at(pos) == '0') {
        if (!node.has_zero())
            node.set_zero(new TNode());
        add_word(node.zero(), word, pos + 1);
    }
    if (word.at(pos) == '1') {
        if (!node.has_one())
            node.set_one(new TNode());
        add_word(node.one(), word, pos + 1);
    }
}
void TrLanguage::add(const std::string & word) {
    add_word(m_Tree, word, 0);
}
std::ostream & TrLanguage::print(std::ostream & out) const {
    out << m_Tree;
    return out;
}
