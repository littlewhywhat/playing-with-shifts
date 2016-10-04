#include <iostream>

#include "maxbcnt.h"
#include "subshift.h"
#include "no3inrow.h"
#include "sub2wd.h"
#include "worddata.h"
#include "wordtable.h"
#include "maxbcnt.h"

class SubshRun {
  private:
    const uint32_t & m_Wordlen;
    Subshift * m_Sub; 
    std::vector<Subshift*> m_Subs;
    MaxBCnt m_MBC;
  public:
    SubshRun(const uint32_t & mode_code, const uint32_t & wordlen) : m_Wordlen(wordlen), m_Sub(NULL) {
        m_Subs.push_back(new No3inRow());
        m_MBC.set(mode_code, wordlen);
    }
    void set_sub(uint32_t sub_code) {
        m_Sub = m_Subs.at(sub_code);
    }
    void run(std::ostream & out) {
        Sub2Wd sub2wd;
        sub2wd.translate(m_MBC.data(), m_Wordlen, *m_Sub);
        out << "worddata:" << std::endl
            << m_MBC.data() << std::endl;
        uint32_t max = m_MBC.compute(&out);
        out << "max = " << max << std::endl;
    }
};

const uint32_t WORDLEN_ID = 1;
const uint32_t MODE_CODE_ID = 2;
const uint32_t SUB_CODE_ID = 3;
const uint32_t CNT_ARGS = 4;

void print_usage(std::ostream & out, char * argv[], const uint32_t & num_args) {
    out << "You just called: " << std::endl;
    for (uint32_t i = 0; i < num_args; i++)
        out << argv[i] << ' ';
    out << std::endl;   
    out << "Wrong number of arguments: " << num_args - 1 << std::endl
        << "instead of " << CNT_ARGS - 1<< std::endl;
    out << "Usage: " << std::endl
        << argv[0] << " wordlen mcode subsh_id" << std::endl;
}

int main(int argc, char * argv[]) {
    if (argc != CNT_ARGS) {
        print_usage(std::cout, argv, argc);
        return 1;
    }
    uint32_t sub_code = std::stoi(argv[SUB_CODE_ID]);
    uint32_t mode_code = std::stoi(argv[MODE_CODE_ID]);
    uint32_t wordlen = std::stoi(argv[WORDLEN_ID]); 
    SubshRun sr(mode_code, wordlen);
    sr.set_sub(sub_code);
    sr.run(std::cout);
    return 0;
}