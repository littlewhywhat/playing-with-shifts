#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <set>

#include "wordtree.h"
#include "graph.h"
#include "strategy.h"
#include "mode.h"

Graph readgraph() {
    Graph graph(4);
    graph.addEdge(0, 1, '0');
    graph.addEdge(0, 1, '1');
    graph.addEdge(1, 2, '0');
    graph.addEdge(1, 3, '1');
    graph.addEdge(2, 3, '1');
    graph.addEdge(3, 0, '0');
    return graph;
}

void dive(WordTree & wt, GNode * node, uint32_t & count, uint32_t & lim, std::string & str) {
    if (count == lim) {
        wt.addWord(str);
        return;
    }
    for (GEdge * edge : node -> out()) {
        count += 1;
        str.push_back(edge -> m_Label);
        dive(wt, edge -> m_Node, count, lim, str);
        count -= 1;
        str.pop_back();
    }
}

WordTree toWordTree(Graph & g, uint32_t lim) {
    WordTree wt;
    uint32_t count = 0;
    std::string buffer;
    for (GNode * node : g.nodes())
        dive(wt, node, count, lim, buffer); 
    return wt;
}

int main (void) {
    std::cout << "calculating... " << std::endl;
    Graph graph = readgraph();
    WordTree wt = toWordTree(graph, 5);

    Strategy strat(0);
    Mode mode;
    int slen = 3;
    int max = 0;
    int num = 1 << slen;
    for (int i = 0; i < num; i++) {
        if (mode.good_strategy(strat, wt)
                && max < strat.countB())
            max = strat.countB();
        strat.incr();
    }
    std::cout << max << std::endl;
    
    return 0;
}
