#ifndef GRAPH2WT_H
#define GRAPH2WT_H

#include <string>
#include <set>

#include "graph.h"
#include "wordtable.h"

class Graph2Wt {
  private:
    const uint32_t m_WordLen;
    void produceNext(std::set<std::string> & wordset, WordTable & wt, const GNode * node, uint32_t lettercnt, std::string & buffer) const {
        if (lettercnt == m_WordLen) {
            if (wordset.find(buffer) == wordset.end()) {
                wt.add(buffer);
                wordset.insert(buffer);
            }
            return;
        }
        for (GEdge * edge : node -> out()) {
            lettercnt += 1;
            buffer.push_back(edge -> m_Label);
            produceNext(wordset, wt, edge -> m_Node, lettercnt, buffer);
            lettercnt -= 1;
            buffer.pop_back();
        }

    }
  public:
    Graph2Wt(const uint32_t & wordlen) : m_WordLen(wordlen) {}
    void translate(const Graph & graph, WordTable & wt) const {
        std::set<std::string> wordset;
        uint32_t lettercnt = 0;
        std::string buffer;
        for (GNode * node : graph.nodes())
            produceNext(wordset, wt, node, lettercnt, buffer);
    }
};

#endif
