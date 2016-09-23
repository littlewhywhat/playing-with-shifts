#include <iostream>
#include <fstream>
#include <ctime>

const int32_t PATH_N_NAME_ID = 1;
const int32_t CNT_NODES_ID = 2; 
const int32_t CNT_GRAPHS_ID = 3;
const int32_t CNT_ARGS = 4;
const char DELIM = ',';

uint32_t randint(uint32_t to) {
    return std::rand() % to;
}

uint32_t randint(uint32_t from, uint32_t to) {
    return randint(to - from) + from;
}

uint32_t randnode(const uint32_t & cnt_nodes) {
    return randint(cnt_nodes);
}

uint32_t randlbl() {
    return randint(1);
}

void write_node(std::fstream & fs, const uint32_t & r_from, 
                                   const uint32_t & r_to, 
                                   const uint32_t & lbl) {
    fs << r_from << DELIM << r_to << DELIM << lbl << std::endl;
}

void write_cnt_nodes(std::fstream & fs, const uint32_t & cnt_nodes) {
    fs << cnt_nodes << std::endl;
}

void write_edges(std::fstream & fs, const uint32_t & cnt_nodes) {
    uint32_t max_num_edges = (1 << cnt_nodes) - 1;
    int rcnt_edges = randint(1, max_num_edges);
    for (uint32_t i = 0; i < rcnt_edges; i++) {
        int r_from = randnode(cnt_nodes);
        int r_to = randnode(cnt_nodes);
        int r_lbl = randlbl();
        write_node(fs, r_from, r_to, r_lbl);
    }
}

std::string getname(const std::string & pathname, const uint32_t & i) {
    std::string s(pathname);
    s.push_back(i + '0');
    return s;
}

int main(int argc, char * argv[]) {
    std::srand(std::time(0));
    if (argc != CNT_ARGS)
        return 1;
    std::string pathname = argv[PATH_N_NAME_ID];
    const int32_t cnt_nodes = atoi(argv[CNT_NODES_ID]);
    const int32_t cnt_graphs = atoi(argv[CNT_GRAPHS_ID]);
    std::cout << cnt_nodes << cnt_graphs << std::endl;

    for (uint32_t i = 0; i < cnt_graphs; i++) {
        std::string filename = getname(pathname, i);
        std::fstream fs(filename, std::ios_base::out);
        write_cnt_nodes(fs, cnt_nodes);
        write_edges(fs, cnt_nodes);
        fs.close();
    }
    return 0;
}
