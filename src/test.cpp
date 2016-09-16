#include <cstdint>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>

class WordTable {
  private:
      std::vector<std::string> m_Words;
  public:
    void add(const std::string & word) {
        m_Words.push_back(word);
    }
    bool has(const std::vector<std::pair<uint32_t, char>> & id_letters) const {
        for (const std::string & word : m_Words) {
            uint32_t cnt_matches = 0;
            for (auto id_lttr : id_letters) {
                uint32_t id = id_lttr.first;
                char letter = id_lttr.second;
                if (word.size() <= id || 
                        word.at(id) != letter)
                    break;
                cnt_matches++;
            }
            if (cnt_matches == id_letters.size())
                return true;
        }
        return false;
    }
};

class Strategy {
  private:
    uint32_t m_Len;
    uint64_t m_Val;
    std::vector<uint32_t> m_BIds;
  public:
    Strategy(uint64_t val, uint32_t len) : m_Len(len), m_Val(val) {
        uint64_t mask = 1;
        for (uint32_t i = 0; i < len; i++) {
            if (val & mask)
                m_BIds.push_back(i);
            val >>= 1;
        }
    }
    const std::vector<uint32_t> bids() const {
        return m_BIds;
    }
    friend std::ostream & operator << (std::ostream & out, const Strategy & s) {
        uint64_t mask = 1;
        uint64_t val = s.m_Val;
        for (uint32_t i = 0; i < s.m_Len; i++) {
            out << (val & mask);
            val >>= 1;
        }
        return out;
    }
};



bool mode1_binary(const Strategy & s, const WordTable & wt) {
    uint32_t mask = 1;
    uint32_t max = (uint32_t)1 << s.bids().size();
    for (uint32_t i = 0; i < max; i++) {
        std::vector<std::pair<uint32_t, char>> id_letters;
        uint32_t data = i;
        for (uint32_t bid : s.bids()) {
            char letter = (data & mask) + '0';
            id_letters.push_back(std::make_pair(bid, letter));
            data >>= 1;
        }
        if (!wt.has(id_letters))
            return false;
    }
    return true;
}

class GoodStrat {
  private:
    WordTable m_WT;
  public:
    GoodStrat() {}
    void addWord(const std::string & word) {
        m_WT.add(word);
    }
    std::list<std::string> goodstrat(uint32_t strat_len) {
        Strategy s(0, strat_len);
        std::list<std::string> l;
        std::stringstream ss;
        uint32_t max = (uint32_t)1 << strat_len;
        for (uint32_t i = 0; i < max; i++) {
            Strategy s(i, strat_len);
            if (mode1_binary(s, m_WT)) {
                ss << s;
                l.push_back(ss.str());
                ss.str(std::string());
                ss.clear();
            }
        }
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
//const int MODE_CODE_ID = 3;

int main(int argc, char * argv[]) {
    uint32_t strat_len = std::stoi(argv[STRAT_LEN_ID]);
    GoodStrat gs;
    GsReader gsr;
    gsr.read(gs, argv[PATH_LEN_ID]);
    std::list<std::string> res = gs.goodstrat(strat_len);
    for (const std::string & s : res) 
        std::cout << s << std::endl;
    return 0;
}
