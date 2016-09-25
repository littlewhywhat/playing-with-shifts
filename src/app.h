#ifndef APP_H
#define APP_H

#include <ostream>
#include <cstdint>

#include "mode.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"
#include "graph2wd.h"
#include "worddata.h"
#include "wordtable.h"
#include "wordtree.h"
#include "graph.h"
#include "greader.h"
#include "strategy.h"

class App {
  private:
    const char * m_Filename;
    const uint32_t m_WordLen;
    const uint32_t m_ModeCode;
    const Mode * create_mode() const {
        switch (m_ModeCode) {
            case 2:
               return new Mode2(); 
            case 3:
               return new Mode3();
            default:
               return new Mode1();
        }
    }
    WordData * create_data() const {
        if (m_ModeCode == 3)
            return new WordTree();
        return new WordTable(m_WordLen);
    }
    void readG(Graph & graph) const {
        GReader gr;
        gr.setFilename(m_Filename);
        gr.read(graph);
    }
    void readWD(WordData & wd) const {
        Graph graph;
        readG(graph);
        translate(graph, wd);
    }
    void translate(const Graph & graph, WordData & wd) const {
        Graph2Wd g2wd(m_WordLen);
        g2wd.translate(graph, wd);
    }
    uint32_t compute_maxBcnt(const Mode & mode, const WordData & wd, std::ostream & out) {
        uint32_t maxBcnt = 0;   
        out << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << m_WordLen;
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
        //for (uint64_t strat_val = strat_bound - 1; strat_val > 0; strat_val--) {
            Strategy strat(strat_val, m_WordLen);
            uint32_t bcnt = strat.Bcnt();
            if (bcnt > maxBcnt && wd.good_strat(strat, mode)) {
                out << strat << std::endl;
                maxBcnt = bcnt;
            }
        }
        return maxBcnt;
    }
  public:
    App(const char * filename, uint32_t wordlen, uint32_t mode_code) : 
            m_Filename(filename), m_WordLen(wordlen), m_ModeCode(mode_code) {}
    ~App() {}
    void run(std::ostream & out) {
        WordData * wd = create_data();
        const Mode * mode = create_mode();
        out << "Building worddata..." << std::endl;
        readWD(*wd);
        out << *wd << std::endl;
        out << "max = " 
              << compute_maxBcnt(*mode, *wd, out)
              << std::endl;  
        delete wd;
        delete mode;
    }
};

#endif
