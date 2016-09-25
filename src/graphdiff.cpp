#include <iostream>

#include "graphgen.h"

const int32_t PATH_N_NAME_ID = 1;
const int32_t CNT_NODES_ID = 2; 
const int32_t CNT_GRAPHS_ID = 3;
const int32_t CNT_ARGS = 4;

int main(int argc, char * argv[]) {
    if (argc != CNT_ARGS)
        return 1;
    std::string pathname = argv[PATH_N_NAME_ID];
    const int32_t cnt_nodes = atoi(argv[CNT_NODES_ID]);
    const int32_t cnt_graphs = atoi(argv[CNT_GRAPHS_ID]);

    GraphGen gg;
    gg.gen(pathname, cnt_nodes, cnt_graphs);
    
    return 0;
}
