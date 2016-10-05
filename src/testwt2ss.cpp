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
#include "modefactory.h"

std::list<std::string> goodstrat(const Mode & mode) {
    std::list<std::string> l;
    std::stringstream ss;
    uint32_t max = (uint32_t)1 << mode.get_wordlen();
    for (uint32_t i = 0; i < max; i++) {
        Strategy s(i, mode.get_wordlen());
        if (mode.good_strat(s)) {
            ss << s;
            l.push_back(ss.str());
            ss.str(std::string());
            ss.clear();
        }
    }
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
    Mode * mode = ModeFactory::get() -> create_instance(mode_code, strat_len);
    GsReader gsr;
    gsr.read(mode -> get_wd(), argv[PATH_ID]);
    std::list<std::string> res = goodstrat(*mode);
    delete mode;
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
