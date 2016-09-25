#include <iostream>

#include "graphgen.h"
#include "app.h"
#include "mode.h"

const int32_t PATH_N_NAME_ID = 1;
const int32_t CNT_NODES_ID = 2; 
const int32_t CNT_GRAPHS_ID = 3;
const int32_t MODE_CODE1_ID = 4;
const int32_t MODE_CODE2_ID = 5;
const int32_t WORDLEN_ID = 6;
const int32_t CNT_ARGS = 7;

const Mode * get_mode(uint32_t mode_code) {
    switch (mode_code) {
        case 1: return new Mode1();
        case 2: return new Mode2();
        case 3: return new Mode3();
        default: throw "Invalid mode code!";
    }
}

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

int main(int argc, char * argv[]) {
    if (argc != CNT_ARGS)
        return 1;
    std::string pathname = argv[PATH_N_NAME_ID];
    const int32_t cnt_nodes = atoi(argv[CNT_NODES_ID]);
    const int32_t cnt_graphs = atoi(argv[CNT_GRAPHS_ID]);
    const int32_t mode_code1 = atoi(argv[MODE_CODE1_ID]);
    const int32_t mode_code2 = atoi(argv[MODE_CODE2_ID]);
    const int32_t wordlen = atoi(argv[WORDLEN_ID]);
    try {
        GraphGen gg;
        gg.gen(pathname, cnt_nodes, cnt_graphs);
       
        App app;
        const Mode * mode1 = get_mode(mode_code1);
        const Mode * mode2 = get_mode(mode_code2);
        ModeDiff max_diff;
        for (uint32_t i = 0; i < cnt_graphs; i++) {
           app.setFilename(gg.getname(pathname, i));
           app.setWordLen(wordlen);
           app.setModeCode(mode_code1);
           uint32_t max1 = app.run(NULL);
           app.setModeCode(mode_code2);
           uint32_t max2 = app.run(NULL);
           uint32_t diff = max1 > max2 ? max1 - max2 : max2 - max1;
           if (diff > max_diff.m_Diff) {
              max_diff.m_Diff = diff;
              max_diff.m_Filename = gg.getname(pathname, i);
           }
        }
        std::cout << max_diff << std::endl;
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
    return 0;
}
