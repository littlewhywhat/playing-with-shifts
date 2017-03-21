#include <string>
#include <set>
#include <cstdint>

#include "graph2lang.h"
#include "graph.h"
#include "language.h"

void Graph2Lang::produceNext(Language & wordset, const uint32_t & wordlength, const GNode * node, uint32_t lettercnt, std::string & buffer) const {
    if (lettercnt == wordlength) {
        if (!wordset.has(buffer))
            wordset.insert(buffer);
        return;
    }
    for (GEdge * edge : node -> out()) {
        lettercnt += 1;
        buffer.push_back(edge -> m_Label);
        produceNext(wordset, wordlength, edge -> m_Node, lettercnt, buffer);
        lettercnt -= 1;
        buffer.pop_back();
    }
}
void Graph2Lang::translate(const Graph &graph, Language & lang, const uint32_t &wordlength) const {
    uint32_t lettercnt = 0;
    std::string buffer;
    for (auto node : graph.nodes())
        produceNext(lang, wordlength, node, lettercnt, buffer);
}
