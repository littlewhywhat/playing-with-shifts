#ifndef GRAPH2WT_H
#define GRAPH2WT_H

#include <string>

#include "graph.h"
#include "wordtable.h"

class Graph2Wt {
  private:
    uint32_t m_WordLen;
    void produceNext(WordTable & wt, GNode * node, uint32_t lettercnt, std::string & buffer) const {
        if (lettercnt == m_WordLen) {
            wt.add(buffer);
            return;
        }
        for (GEdge * edge : node -> out()) {
            lettercnt += 1;
            buffer.push_back(edge -> m_Label);
            produceNext(wt, edge -> m_Node, lettercnt, buffer);
            lettercnt -= 1;
            buffer.pop_back();
        }

    }
  public:
    Graph2Wt(uint32_t wordlen) : m_WordLen(wordlen) {}
    void translate(const Graph & graph, WordTable & wt) const {
        uint32_t lettercnt = 0;
        std::string buffer;
        for (GNode * node : graph.nodes())
            produceNext(wt, node, lettercnt, buffer);
    }
};

#endif
