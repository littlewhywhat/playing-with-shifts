#ifndef PLAYGRAPH_H
#define PLAYGRAPH_H

#include <ostream>
#include <cstdint>

#include "graph2wd.h"
#include "worddata.h"
#include "graph.h"
#include "greader.h"
#include "maxbcnt.h"
#include "gamefactory.h"

class PlayGraph {
  private:
    const std::string m_GraphFile;
    Game * m_Game;
    Game & game() {
        return *m_Game;
    }
    void read_graph() {
        Graph graph;
        GReader greader(m_GraphFile);
        greader.read(graph);
        Graph2Wd g2wd(game().wordlen());
        g2wd.translate(graph, game().wd());
    }
  public:
    PlayGraph(const std::string & graphfile, const uint32_t & wordlen, const uint32_t & game_mode) : 
            m_GraphFile(graphfile) {
        m_Game = GameFactory::get() -> create_instance(game_mode, wordlen);
    }
    ~PlayGraph() {
        delete m_Game;
    }
    uint32_t run(std::ostream * out) {
        if (out)
            *out << "Building worddata..." << std::endl;
        read_graph();
        MaxBCnt mbc(game());
        if (out) 
            *out << game().wd() << std::endl;

        uint32_t max_bcnt = mbc.compute(out);
        if (out) {
            *out << "max = " 
                  << max_bcnt
                  << std::endl;  
        }
        return max_bcnt;
    }
};

#endif
