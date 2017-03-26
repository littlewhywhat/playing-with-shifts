//
// Created by littlewhywhat on 3/25/17.
//

#ifndef SHIFTS_APPLICATIONARGUMENTS_H
#define SHIFTS_APPLICATIONARGUMENTS_H


#include <cstdint>
#include <string>
#include <vector>
#include <map>

class ApplicationArguments {
  public:
    ApplicationArguments() {};
    ApplicationArguments(const uint32_t & argc, char * argv[]);
    bool has_tag(const std::string & tag) const;
    void add_option(const std::string & tag, const std::string & option);
    void add_tag(const std::string & tag);
    bool empty() const;
    const std::string & get_first_opt(const std::string & tag) const {
        return m_Arguments.at(tag).front();
    }
    const std::vector<std::string> & get_opts(const std::string & tag) const {
        return m_Arguments.at(tag);
    }
    friend std::map<std::string, std::vector<std::string>>::const_iterator begin(const ApplicationArguments & src) {
        return src.m_Arguments.cbegin();
    };
    friend std::map<std::string, std::vector<std::string>>::const_iterator end(const ApplicationArguments & src) {
        return src.m_Arguments.cend();
    };
  private:
    std::map<std::string, std::vector<std::string>> m_Arguments;
    bool is_tag(const std::string & val) const;
};


#endif //SHIFTS_APPLICATIONARGUMENTS_H
