#include <string>
#include <set>
#include <cstdint>

#include "graph2lang.h"
#include "graph.h"
#include "language.h"

void Graph2Lang::produceNext(std::set<std::string> & wordset, Language & lang, const GNode * node, uint32_t lettercnt, std::string & buffer) const {
    if (lettercnt == lang.wordlen()) {
        if (wordset.find(buffer) == wordset.end()) {
            lang.add(buffer);
            wordset.insert(buffer);
        }
        return;
    }
    for (GEdge * edge : node -> out()) {
        lettercnt += 1;
        buffer.push_back(edge -> m_Label);
        produceNext(wordset, lang, edge -> m_Node, lettercnt, buffer);
        lettercnt -= 1;
        buffer.pop_back();
    }
}
void Graph2Lang::translate(const Graph & graph, Language & lang) const {
    std::set<std::string> wordset;
    uint32_t lettercnt = 0;
    std::string buffer;
    for (auto node : graph.nodes())
        produceNext(wordset, lang, node, lettercnt, buffer);
}
