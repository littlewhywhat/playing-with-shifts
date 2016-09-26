#ifndef APP_H
#define APP_H

#include <ostream>
#include <cstdint>

#include "graph2wd.h"
#include "worddata.h"
#include "graph.h"
#include "greader.h"
#include "maxbcnt.h"

class App {
  private:
    std::string m_Filename;
    const uint32_t m_WordLen;
    MaxBCnt m_MBC; 
    void readG(Graph & graph) const {
        GReader gr;
        gr.setFilename(m_Filename);
        gr.read(graph);
    }
    void readWD() {
        Graph graph;
        readG(graph);
        translate(graph);
    }
    void translate(const Graph & graph) {
        Graph2Wd g2wd(m_WordLen);
        g2wd.translate(graph, m_MBC.data());
    }
  public:
    App(const std::string & filename, const uint32_t & wordlen, const uint32_t & mode_code) : 
            m_Filename(filename), m_WordLen(wordlen) {
        m_MBC.set(mode_code, wordlen);
    }
    ~App() {}
    uint32_t run(std::ostream * out) {
        if (out)
            *out << "Building worddata..." << std::endl;
        readWD();
        if (out) 
            *out << m_MBC.data() << std::endl;
        uint32_t maxBcnt = m_MBC.compute(out);
        if (out) {
            *out << "max = " 
                  << maxBcnt
                  << std::endl;  
        }
        return maxBcnt;
    }
};

#endif
