//
// Created by littlewhywhat on 3/26/17.
//

#ifndef SHIFTS_BUNDLE_H
#define SHIFTS_BUNDLE_H

#include <string>
#include <vector>
#include <map>

class Bundle {
  private:
    std::map<std::string, std::vector<uint32_t>> m_IntVectors;
    std::map<std::string, std::vector<std::string>> m_StrVectors;
    std::map<std::string, bool> m_Bools;
  public:
    void insert_intvector(const std::string & tag, const std::vector<uint32_t> & val) {
        m_IntVectors[tag] = val;
    }
    void push_to_intvector(const std::string & tag, const uint32_t & val) {
        m_IntVectors[tag].push_back(val);
    }
    void push_to_strvector(const std::string & tag, const std::string & val) {
        m_StrVectors[tag].push_back(val);
    }
    void push_to_bools(const std::string & tag, bool val) {
        m_Bools[tag] = val;
    }
    const std::vector<uint32_t> & get_intvector(const std::string & tag) const {
        return m_IntVectors.at(tag);
    }
    const std::vector<std::string> & get_strvector(const std::string & tag) const {
        return m_StrVectors.at(tag);
    }
    bool has_tag_in_bools(const std::string & tag) const {
        return m_Bools.find(tag) != m_Bools.cend();
    }
    bool has_tag_in_strvec(const std::string & tag) const {
        return m_StrVectors.find(tag) != m_StrVectors.cend();
    }

};


#endif //SHIFTS_BUNDLE_H
