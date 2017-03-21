#include <string>
#include <set>
#include <cstdint>

#include "graph2lang.h"
#include "graph.h"

void Graph2Lang::produceNext(std::set<std::string> & wordset, const uint32_t & wordlength, const GNode * node, uint32_t lettercnt, std::string & buffer) const {
    if (lettercnt == wordlength) {
        if (wordset.find(buffer) == wordset.end())
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
std::set<std::string> Graph2Lang::translate(const Graph &graph, const uint32_t &wordlength) const {
    std::set<std::string> wordset;
    uint32_t lettercnt = 0;
    std::string buffer;
    for (auto node : graph.nodes())
        produceNext(wordset, wordlength, node, lettercnt, buffer);
    return wordset;
}
