#ifndef GRAPHGEN_H
#define GRAPHGEN_H

#include <fstream>

#include "random.h"

class GraphGen {
  private:
    const char DELIM = ',';
    const Random m_R;
    void write_node(std::fstream & fs, const uint32_t & r_from, 
                                       const uint32_t & r_to, 
                                       const uint32_t & lbl) const {
        fs << r_from << DELIM << r_to << DELIM << lbl << std::endl;
    }
    void write_edges(std::fstream & fs, const uint32_t & cnt_nodes) const{
        uint32_t max_num_edges = (1 << cnt_nodes) - 1;
        int rcnt_edges = m_R.randint(1, max_num_edges);
        for (uint32_t i = 0; i < rcnt_edges; i++) {
            int r_from = m_R.randnode(cnt_nodes);
            int r_to = m_R.randnode(cnt_nodes);
            int r_lbl = m_R.randlbl();
            write_node(fs, r_from, r_to, r_lbl);
        }
    }
    void write_cnt_nodes(std::fstream & fs, const uint32_t & cnt_nodes) const {
        fs << cnt_nodes << std::endl;
    }
  public:
    std::string getname(const std::string & pathname, const uint32_t & i) const {
        std::string s(pathname);
        s.push_back(i + '0');
        return s;
    }
    void gen(const std::string & pathname, 
             const uint32_t & cnt_nodes, 
             const uint32_t & cnt_graphs) const {
        for (uint32_t i = 0; i < cnt_graphs; i++) {
            const std::string & filename = getname(pathname, i);
            std::fstream fs(filename, std::ios_base::out);
            write_cnt_nodes(fs, cnt_nodes);
            write_edges(fs, cnt_nodes);
            fs.close();
        }
    }
};

#endif
