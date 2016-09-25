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

#include "worddata.h"
#include "wordtable.h"
#include "wordtree.h"
#include "strategy.h"
#include "mode.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"

std::list<std::string> goodstrat(const WordData & wd, uint32_t strat_len, uint32_t mode_code) {
    Mode * mode = NULL;
    switch (mode_code) {
        case 1: mode = new Mode1();
                break;
        case 2: mode = new Mode2();
                break;
        case 3: mode = new Mode3();
                break;
        default:
           throw "Wrong mode code!"; 
    }
    std::list<std::string> l;
    std::stringstream ss;
    uint32_t max = (uint32_t)1 << strat_len;
    for (uint32_t i = 0; i < max; i++) {
        Strategy s(i, strat_len);
        if (wd.good_strat(s, *mode)) {
            ss << s;
            l.push_back(ss.str());
            ss.str(std::string());
            ss.clear();
        }
    }
    delete mode;
    return l;
}

class GsReader {
  public: 
    void read(WordData & wd, const char * path) {
        std::fstream fs(path);

        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            wd.add(buffer);
        }
    }
};

const int PATH_ID = 1;
const int STRAT_LEN_ID = 2;
const int MODE_CODE_ID = 3;

int main(int argc, char * argv[]) {
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    uint32_t mode_code = std::stoi(argv[MODE_CODE_ID]);
    WordData * wd;
    if (mode_code == 3)
       wd = new WordTree();
    else
       wd = new WordTable(strat_len); 
    GsReader gsr;
    gsr.read(*wd, argv[PATH_ID]);
    std::list<std::string> res = goodstrat(*wd, strat_len, mode_code);
    delete wd;
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
