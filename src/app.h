#ifndef APP_H
#define APP_H

#include <ostream>
#include <cstdint>

#include "mode.h"
#include "mode1.h"
#include "mode2.h"
#include "graph2wt.h"
#include "wordtable.h"
#include "graph.h"
#include "greader.h"
#include "strategy.h"

class App {
  private:
    const Mode * mode;
    const char * m_Filename;
    const uint32_t m_Wordlen;
    void setMode(uint32_t mode_code) {
        if (mode_code == 1)
            mode = new Mode1();
        else
            mode = new Mode2();
    }
    void readG(Graph & graph) const {
        GReader gr;
        gr.setFilename(m_Filename);
        gr.read(graph);
    }
    void readWT(WordTable & wt) const {
        Graph graph;
        readG(graph);
        translate(graph, wt);
    }
    void translate(const Graph & graph, WordTable & wt) const {
        Graph2Wt g2wt(m_Wordlen);
        g2wt.translate(graph, wt);
    }
    uint32_t compute_maxBcnt(const WordTable & wt, std::ostream & out) {
        uint32_t maxBcnt = 0;   
        out << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << m_Wordlen;
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
        //for (uint64_t strat_val = strat_bound - 1; strat_val > 0; strat_val--) {
            Strategy strat(strat_val, m_Wordlen);
            uint32_t bcnt = strat.Bcnt();
            if (bcnt > maxBcnt && mode -> good_strat(strat, wt)) {
                out << strat << std::endl;
                maxBcnt = bcnt;
            }
        }
        return maxBcnt;
    }
  public:
    App(const char * filename, uint32_t wordlen, uint32_t mode_code) : 
            m_Filename(filename), m_Wordlen(wordlen) {
        setMode(mode_code);  
    }
    ~App() {
        delete mode;
    }
    void run(std::ostream & out) {
        WordTable wt(m_Wordlen);
        out << "Building wordtable..." << std::endl;
        readWT(wt);
        out << wt << std::endl;
        out << "max = " 
              << compute_maxBcnt(wt, out)
              << std::endl;  
    }
};

#endif
