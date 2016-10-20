#ifndef GRAPHGEN_H
#define GRAPHGEN_H

#include <set>
#include <cstdint>

#include "random.h"

class GraphGen {
  private:
    const char DELIM = ',';
    const Random m_R;
    uint32_t rand_not_in(uint32_t cnt_nodes, const std::set<uint32_t> & set) const; 
    void write_random(const std::string & pathname) const; 
    void write_node(std::fstream & fs, const uint32_t & r_from, 
                                       const uint32_t & r_to, 
                                       const uint32_t & lbl) const; 
    void write_edges(std::fstream & fs, const uint32_t & cnt_nodes) const;
    void write_cycles(std::fstream & fs, const uint32_t & cnt_nodes) const;
    void write_cnt_nodes(std::fstream & fs, const uint32_t & cnt_nodes) const;
  public:
    static std::string getname(const std::string & pathname, const uint32_t & i);
    void gen(const std::string & pathname, 
             const uint32_t & cnt_nodes, 
             const uint32_t & cnt_graphs) const;
};

#endif
