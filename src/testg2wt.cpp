#include <cstdint>
#include <iostream>

#include "worddata.h"
#include "wordtable.h"
#include "wordtree.h"
#include "graph2wd.h"
#include "graph.h"
#include "greader.h"

const uint32_t PATH_ID = 1;
const uint32_t LEN_ID = 2;
const uint32_t WORDDATA_ID = 3;

const uint32_t WORDTABLE_ID = 1;
const uint32_t WORDTREE_ID = 2;

int main(int argc, char * argsv[]) {
    const char * filename = argsv[PATH_ID];
    GReader greader(filename);
    Graph graph;
    try {
        greader.read(graph);
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }
    int wordlen = std::stoi(argsv[LEN_ID]);
    int worddata_code = std::stoi(argsv[WORDDATA_ID]);
    WordData * wd;
    if (worddata_code == WORDTABLE_ID)     
        wd = new WordTable(wordlen);
    else
        wd = new WordTree();
    Graph2Wd g2wd(wordlen);
    g2wd.translate(graph, *wd);
    std::cout << *wd;
    delete wd;
    return 0;
}
