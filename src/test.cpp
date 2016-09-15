#include <cstdint>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

#include "mode.h"
#include "mode1.h"
#include "mode2.h"
#include "strategy.h"
#include "wordtree.h"
#include "alphabet.h"


class GoodStrat {
  private:
    WordTree m_WT;
  public:
    void addWord(const std::string & word) {
        m_WT.addWord(word);
    }
    std::list<std::string> goodstrat(const Alphabet & alpha, uint32_t strat_len, uint32_t mode_code) {
        Mode * mode = NULL;
        if (mode_code == 1)
            mode = new Mode1();
        else 
            mode = new Mode2();
        Strategy s(0, strat_len);
        std::list<std::string> l;
        std::stringstream ss;
        while (!s.outOfLen()) {
            if (mode -> good_strategy(s, m_WT, alpha)) {
                ss << s;
                l.push_back(ss.str());
                ss.str(std::string());
                ss.clear();
            }
            s.incr();
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
            std::cout << "error" << std::endl;
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
    Alphabet alpha;
    alpha.add('0');
    alpha.add('1');
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    GoodStrat gs;
    GsReader gsr;
    gsr.read(gs, argv[PATH_LEN_ID]);
    std::list<std::string> res = gs.goodstrat(alpha, strat_len, std::stoi(argv[MODE_CODE_ID]));
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
