#ifndef GRAPH2WT_H
#define GRAPH2WT_H

#include <string>
#include <set>
#include <cstdint>

#include "graph.h"
#include "worddata.h"

class Graph2Wd {
  private:
    const uint32_t m_WordLen;
    void produceNext(std::set<std::string> & wordset, WordData & wd, const GNode * node, uint32_t lettercnt, std::string & buffer) const {
        if (lettercnt == m_WordLen) {
            if (wordset.find(buffer) == wordset.end()) {
                wd.add(buffer);
                wordset.insert(buffer);
            }
            return;
        }
        for (GEdge * edge : node -> out()) {
            lettercnt += 1;
            buffer.push_back(edge -> m_Label);
            produceNext(wordset, wd, edge -> m_Node, lettercnt, buffer);
            lettercnt -= 1;
            buffer.pop_back();
        }

    }
  public:
    Graph2Wd(const uint32_t & wordlen) : m_WordLen(wordlen) {}
    void translate(const Graph & graph, WordData & wd) const {
        std::set<std::string> wordset;
        uint32_t lettercnt = 0;
        std::string buffer;
        for (auto node : graph.nodes())
            produceNext(wordset, wd, node, lettercnt, buffer);
    }
};

#endif
