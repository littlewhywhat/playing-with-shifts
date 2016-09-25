#include <cstdint>
#include <iostream>

#include "wordtable.h"
#include "graph2wd.h"
#include "graph.h"
#include "greader.h"

const uint32_t PATH_ID = 1;
const uint32_t LEN_ID = 2;

int main(int argc, char * argsv[]) {
    GReader greader;
    greader.setFilename(argsv[PATH_ID]);
    Graph graph;
    try {
        greader.read(graph);
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }

    WordTable wt(std::stoi(argsv[LEN_ID]));
    Graph2Wd g2wd(std::stoi(argsv[LEN_ID]));
    g2wd.translate(graph, wt);
    std::cout << wt;
    return 0;
}
