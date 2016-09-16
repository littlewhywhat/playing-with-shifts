#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <set>

#include "wordtable.h"
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
    WordTable wt;
    Graph2Wt g2wt(wordlen);
    std::cout << "Building wordtable..." << std::endl;
    g2wt.translate(graph, wt);
    std::cout << wt << std::endl;

    Mode * mode;
    if (mode_code == 1)
        mode = new Mode1();
    else 
        mode = new Mode2();
    
    uint32_t max = 0;
    std::cout << "good strategies are: " << std::endl;
    uint32_t max_s = (uint32_t)1 << wordlen;
    for (uint32_t i = 0; i < max_s; i++) {
        Strategy s(i, wordlen);
        uint32_t bcnt = s.countB();
        if (bcnt > max && 
                mode -> good_strat(s, wt)) {
            std::cout << s << std::endl;
            max = bcnt;
        }
    }
    std::cout << "max = " << max << std::endl;
    delete mode;
    return 0;
}
