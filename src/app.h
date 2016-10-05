#ifndef APP_H
#define APP_H

#include <ostream>
#include <cstdint>

#include "graph2wd.h"
#include "worddata.h"
#include "graph.h"
#include "greader.h"
#include "maxbcnt.h"
#include "modefactory.h"

class App {
  private:
    std::string m_Filename;
    const uint32_t m_WordLen;
    Mode * m_Mode;
    Mode & get_mode() {
        return *m_Mode;
    }
    void readWD() {
        Graph graph;
        GReader gr;
        gr.setFilename(m_Filename);
        gr.read(graph);
        Graph2Wd g2wd(m_WordLen);
        g2wd.translate(graph, get_mode().get_wd());
    }
  public:
    App(const std::string & filename, const uint32_t & wordlen, const uint32_t & mode_code) : 
            m_Filename(filename), m_WordLen(wordlen) {
        m_Mode = ModeFactory::get() -> create_instance(mode_code, wordlen);
    }
    ~App() {}
    uint32_t run(std::ostream * out) {
        if (out)
            *out << "Building worddata..." << std::endl;
        readWD();
        MaxBCnt mbc(get_mode());
        if (out) 
            *out << get_mode().get_wd() << std::endl;

        uint32_t maxBcnt = mbc.compute(out);
        if (out) {
            *out << "max = " 
                  << maxBcnt
                  << std::endl;  
        }
        return maxBcnt;
    }
};

#endif
