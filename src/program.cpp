#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <set>

#include "wordtree.h"
#include "graph.h"
#include "strategy.h"
#include "mode1.h"

Graph readgraph() {
    Graph graph(4);
    graph.addEdge(0, 1, '0');
    graph.addEdge(0, 1, '1');
    graph.addEdge(1, 0, '0');
    graph.addEdge(1, 0, '1');
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
    int wordlen = 10;
    std::cout << "calculating... " << std::endl;
    Graph graph = readgraph();
    WordTree wt = toWordTree(graph, wordlen);

    Alphabet alpha;
    alpha.add('0');
    alpha.add('1');

    Strategy strat(0, wordlen);
    Mode * mode = new Mode1();
    std::cout << wt << std::endl;
    uint32_t max = 0;
    int num = 1 << strat.lim();
    for (int i = 0; i < num; i++) {
        if (mode -> good_strategy(strat, wt, alpha)) {
            std::cout << strat << std::endl; 
            if (max < strat.countB())
                max = strat.countB();
        }
        strat.incr();
    }
    std::cout << "Max: " << max << std::endl;
    delete mode;    
    return 0;
}
