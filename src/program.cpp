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
#include "greader.h"

void print_usage(const char * program) {
    std::cout << "usage: " << program 
              << "filename wordlength mode{1,2}" 
              << std::endl;
}

const int FILENAME_I = 1;
const int WORDLEN_I = 2;
const int MODE_CODE = 3;

int main (int argc, char * argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;   
    }
    const char * filename = argv[FILENAME_I];
    const int wordlen = atoi(argv[WORDLEN_I]);
    const int mode_code = atoi(argv[MODE_CODE]);
    GReader gr;
    gr.setFilename(filename);
    Graph graph;
    try {
        gr.read(graph);
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }
    WordTree wt;
    Graph2Wt g2wt(wordlen);
    std::cout << "Building wordtree..." << std::endl;
    g2wt.translate(graph, wt);
    
    Alphabet alpha;
    alpha.add('0');
    alpha.add('1');

    Strategy strat(0, wordlen);
    Mode * mode;
    if (mode_code == 1)
        mode = new Mode1();
    else 
        mode = new Mode2();
    //std::cout << wt << std::endl;
    uint32_t max = 0;
    std::cout << "good strategies are: " << std::endl;
    while (!strat.outOfLen()) {
        if (mode -> good_strategy(strat, wt, alpha)) {
            std::cout << strat << std::endl; 
            if (max < strat.countB())
                max = strat.countB();
        }
        if (strat.countB() > max)
            strat.incr();
        while (strat.countB() <= max && !strat.outOfLen()) {
            strat.incr();
        }
    }
    std::cout << "max = " << max << std::endl;
    delete mode;
    return 0;
}
