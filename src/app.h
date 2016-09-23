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
    std::ostream & m_Out;
    Mode * mode;
    const char * m_Filename;
    const uint32_t m_Wordlen;
    void setMode(uint32_t mode_code) {
        if (mode_code == 1)
            mode = new Mode1();
        else
            mode = new Mode2();
    }
    void readG(Graph & graph) {
        GReader gr;
        gr.setFilename(m_Filename);
        gr.read(graph);
    }
    void readWT(WordTable & wt) {
        Graph graph;
        readG(graph);
        translate(graph, wt);
    }
    void translate(const Graph & graph, WordTable & wt) {
        Graph2Wt g2wt(m_Wordlen);
        m_Out << "Building wordtable..." << std::endl;
        g2wt.translate(graph, wt);
        m_Out << wt << std::endl;
    }
    uint32_t compute_maxBcnt(const WordTable & wt) {
        uint32_t maxBcnt = 0;   
        m_Out << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << m_Wordlen;
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
        //for (uint64_t strat_val = strat_bound - 1; strat_val > 0; strat_val--) {
            Strategy strat(strat_val, m_Wordlen);
            uint32_t bcnt = strat.Bcnt();
            if (bcnt > maxBcnt && 
                    mode -> good_strat(strat, wt)) {
                m_Out << strat << std::endl;
                maxBcnt = bcnt;
            }
        }
        return maxBcnt;
    }
  public:
    App(std::ostream & out, const char * filename, 
            uint32_t wordlen, uint32_t mode_code) : m_Out(out), 
            m_Filename(filename), m_Wordlen(wordlen) {
        setMode(mode_code);  
    }
    ~App() {
        delete mode;
    }
    void run() {
        WordTable wt(m_Wordlen);
        readWT(wt);
        m_Out << "max = " 
              << compute_maxBcnt(wt)
              << std::endl;  
    }
};

#endif
