#ifndef GRAPH2WT_H
#define GRAPH2WT_H

#include <string>
#include <set>

#include "graph.h"
#include "wordtable.h"

class Graph2Wt {
  private:
    uint32_t m_WordLen;
    std::set<std::string> m_Words;

    void produceNext(WordTable & wt, GNode * node, uint32_t lettercnt, std::string & buffer) {
        if (lettercnt == m_WordLen) {
            if (m_Words.find(buffer) == m_Words.end()) {
                wt.add(buffer);
                m_Words.insert(buffer);
            }
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
    void translate(const Graph & graph, WordTable & wt) {
        uint32_t lettercnt = 0;
        std::string buffer;
        for (GNode * node : graph.nodes())
            produceNext(wt, node, lettercnt, buffer);
    }
};

#endif
