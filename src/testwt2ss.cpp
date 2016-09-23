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

std::list<std::string> goodstrat(const WordTable & wt, uint32_t strat_len, uint32_t mode_code) {
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
        if (mode -> good_strat(s, wt)) {
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
    void read(WordTable & wt, const char * path) {
        std::fstream fs(path);

        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            wt.add(buffer);
        }
    }
};

const int PATH_ID = 1;
const int STRAT_LEN_ID = 2;
const int MODE_CODE_ID = 3;

int main(int argc, char * argv[]) {
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    WordTable wt(strat_len);
    GsReader gsr;
    gsr.read(wt, argv[PATH_ID]);
    std::list<std::string> res = goodstrat(wt, strat_len, std::stoi(argv[MODE_CODE_ID]));
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
