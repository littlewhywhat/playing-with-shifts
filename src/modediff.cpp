#include <iostream>

#include "graphgen.h"
#include "graphconsole.h"
#include "maxbcntplayer.h"

const int32_t PATH_N_NAME_ID = 1;
const int32_t CNT_NODES_ID = 2; 
const int32_t CNT_GRAPHS_ID = 3;
const int32_t MODE_CODE1_ID = 4;
const int32_t MODE_CODE2_ID = 5;
const int32_t WORDLEN_ID = 6;
const int32_t CNT_ARGS = 7;

struct ModeDiff {
    uint32_t m_Diff;
    std::string m_Filename;
    ModeDiff() : m_Diff(0), m_Filename("All the same") {}
    friend std::ostream & operator << (std::ostream & out, const ModeDiff & src) {
        out << "difference: " << src.m_Diff << std::endl
            << "filename: " << src.m_Filename << std::endl;
        return out;
    }
};

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
    try {
        GraphGen gg;
        gg.gen(pathname, cnt_nodes, cnt_graphs);
       
        ModeDiff max_diff;
        MaxBCntPlayer mbc_player;
        mbc_player.set_out_lang(false);
        mbc_player.set_out_result(false);
        GraphConsole gc(std::cout);
        for (uint32_t i = 0; i < cnt_graphs; i++) {
           std::cout << "graph " << i << std::endl;
           gc.reset();
           gc.set_graphfile(gg.getname(pathname, i));
           gc.load(mode_code1, wordlen);
           mbc_player.play(gc);
           uint32_t max1 = mbc_player.max_bcnt();
           std::cout << "max for mode " << mode_code1 << ": " << max1 << std::endl;
           gc.reset();
           gc.set_graphfile(gg.getname(pathname, i));
           gc.load(mode_code2, wordlen);
           mbc_player.play(gc);
           uint32_t max2 = mbc_player.max_bcnt();;
           std::cout << "max for mode " << mode_code2 << ": " << max2 << std::endl;
           uint32_t diff = max1 > max2 ? max1 - max2 : max2 - max1;
           if (diff > max_diff.m_Diff) {
              max_diff.m_Diff = diff;
              max_diff.m_Filename = gg.getname(pathname, i);
              std::cout << max_diff << std::endl;
           }
        }
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
    return 0;
}
