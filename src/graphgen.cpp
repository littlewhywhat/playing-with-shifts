#include <fstream>
#include <set>

#include "graphgen.h"
#include "random.h"

uint32_t GraphGen::rand_not_in(uint32_t cnt_nodes, const std::set<uint32_t> & set) const {
    uint32_t rand = m_R.randnode(cnt_nodes);
    while (set.find(rand) != set.end())
        rand = m_R.randnode(cnt_nodes);
    return rand;
}
void GraphGen::write_random(const std::string & pathname) const {
    std::fstream fs(pathname, std::ios_base::out);
    fs << m_R << std::endl;
    fs.close();
}
void GraphGen::write_node(std::fstream & fs, const uint32_t & r_from, 
                                   const uint32_t & r_to, 
                                   const uint32_t & lbl) const {
    fs << r_from << DELIM << r_to << DELIM << lbl << std::endl;
}
void GraphGen::write_cycles(std::fstream & fs, const uint32_t & cnt_nodes) const {
    std::set<uint32_t> cycled;
    for (uint32_t strt = 0; strt < cnt_nodes; strt++) { 
        if (cycled.find(strt) == cycled.end()) {
            cycled.insert(strt);
            uint32_t from = strt;
            std::set<uint32_t> ccycled;
            uint32_t to = rand_not_in(cnt_nodes, ccycled);
            while (to != strt) {
                ccycled.insert(to);
                cycled.insert(to);
                write_node(fs, from, to, m_R.randlbl());
                from = to;
                to = rand_not_in(cnt_nodes, ccycled);
            }
            write_node(fs, from, to, m_R.randlbl());
        }
    }
}
void GraphGen::write_cnt_nodes(std::fstream & fs, const uint32_t & cnt_nodes) const {
    fs << cnt_nodes << std::endl;
}
std::string GraphGen::getname(const std::string & pathname, const uint32_t & i) {
    std::string s(pathname);
    s.push_back(i + '0');
    return s;
}
void GraphGen::gen(const std::string & pathname, 
         const uint32_t & cnt_nodes, 
         const uint32_t & cnt_graphs) const {
    write_random(pathname);
    for (uint32_t i = 0; i < cnt_graphs; i++) {
        const std::string & filename = getname(pathname, i);
        std::fstream fs(filename, std::ios_base::out);
        write_cnt_nodes(fs, cnt_nodes);
        write_cycles(fs, cnt_nodes);
        fs.close();
    }
}
