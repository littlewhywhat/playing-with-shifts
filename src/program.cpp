#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <set>

#include "wordtree.h"
#include "graph.h"
#include "strategy.h"
#include "mode1.h"
#include "mode2.h"
#include "graph2wt.h"

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

int main (void) {
    int wordlen = 5;
    std::cout << "calculating... " << std::endl;
    Graph graph = readgraph();
    WordTree wt;
    Graph2Wt g2wt(wordlen);
    g2wt.translate(graph, wt);
    wt.addWord("01110");
    Alphabet alpha;
    alpha.add('0');
    alpha.add('1');

    Strategy strat(0, wordlen);
    Mode * mode = new Mode2();
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
