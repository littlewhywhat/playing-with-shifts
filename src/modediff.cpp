#include <iostream>

#include "graphgen.h"
#include "graphconsole.h"
#include "maxbcntplayer.h"
#include "gameserver.h"

const int32_t PATH_N_NAME_ID = 1;
const int32_t CNT_NODES_ID = 2; 
const int32_t CNT_GRAPHS_ID = 3;
const int32_t MODE_CODE1_ID = 4;
const int32_t MODE_CODE2_ID = 5;
const int32_t WORDLEN_ID = 6;
const int32_t CNT_ARGS = 7;

void print_usage(std::ostream & out, char * argv[], const uint32_t & num_args) {
    out << "You just called: " << std::endl;
    for (uint32_t i = 0; i < num_args; i++)
        out << argv[i] << ' ';
    out << std::endl;   
    out << "Wrong number of arguments: " << num_args - 1 << std::endl
        << "instead of " << CNT_ARGS - 1<< std::endl;
    out << "Usage: " << std::endl
        << argv[0] << " path rcnt_nodes cnt_graph mcode1 mcode2 wordlen" << std::endl;
}


int main(int argc, char * argv[]) {
    if (argc != CNT_ARGS) {
        print_usage(std::cout, argv, argc);
        return 1;
    }
    std::string pathname = argv[PATH_N_NAME_ID];
    const uint32_t cnt_nodes = atoi(argv[CNT_NODES_ID]);
    const uint32_t cnt_graphs = atoi(argv[CNT_GRAPHS_ID]);
    const uint32_t mode_code1 = atoi(argv[MODE_CODE1_ID]);
    const uint32_t mode_code2 = atoi(argv[MODE_CODE2_ID]);
    const uint32_t wordlen = atoi(argv[WORDLEN_ID]);
    std::vector<uint32_t> modes;
    modes.push_back(mode_code1);
    modes.push_back(mode_code2);
    try {
        GraphGen gg;
        gg.gen(pathname, cnt_nodes, cnt_graphs);
       
        MaxBCntPlayer mbc_player;
        GraphConsole gc(std::cout);
        gc.set_wordlen(wordlen);
        GameServer gs(gc, mbc_player, modes);
        for (uint32_t i = 0; i < cnt_graphs; i++) {
           std::cout << "graph " << i << std::endl;
           gc.set_graphfile(gg.getname(pathname, i));
           gs.launch();
        }
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
    return 0;
}
