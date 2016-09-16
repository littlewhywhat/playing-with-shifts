#include <cstdint>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>

#include "wordtable.h"
#include "strategy.h"
#include "mode.h"
#include "mode1.h"
#include "mode2.h"

class GoodStrat {
  private:
    WordTable m_WT;
  public:
    GoodStrat() {}
    void addWord(const std::string & word) {
        m_WT.add(word);
    }
    std::list<std::string> goodstrat(uint32_t strat_len, uint32_t mode_code) {
        Mode * mode = NULL;
        if (mode_code == 1)
            mode = new Mode1();
        else 
            mode = new Mode2();
        std::list<std::string> l;
        std::stringstream ss;
        uint32_t max = (uint32_t)1 << strat_len;
        for (uint32_t i = 0; i < max; i++) {
            Strategy s(i, strat_len);
            if (mode -> good_strat(s, m_WT)) {
                ss << s;
                l.push_back(ss.str());
                ss.str(std::string());
                ss.clear();
            }
        }
        delete mode;
        return l;
    }
};

class GsReader {
  public: 
    void read(GoodStrat & gs, const char * path) {
        std::fstream fs(path);

        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            gs.addWord(buffer);
        }
    }
};

const int PATH_LEN_ID = 1;
const int STRAT_LEN_ID = 2;
const int MODE_CODE_ID = 3;

int main(int argc, char * argv[]) {
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    GoodStrat gs;
    GsReader gsr;
    gsr.read(gs, argv[PATH_LEN_ID]);
    std::list<std::string> res = gs.goodstrat(strat_len, std::stoi(argv[MODE_CODE_ID]));
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
