//
// Created by vaivorom on 3/24/17.
//

#ifndef SHIFTS_APPCONFIG_H
#define SHIFTS_APPCONFIG_H


#include <vector>
#include <cstdint>
#include <string>

class AppConfig {
  private:
    bool m_NoOutLang;
    bool m_NoOutGame;
    bool m_NoOutRes;
    bool m_TestMode;
    std::vector<uint32_t> m_GameModes;
    std::vector<std::string> m_LangHostIds;
    std::string m_PlayerTag;
    uint32_t m_Wordlen;
  public:
    bool get_nooutlang() const { return m_NoOutLang; }
    bool get_nooutgame() const { return m_NoOutGame; }
    bool get_nooutres() const { return m_NoOutRes; }
    bool get_testmode() const { return m_TestMode; }
    const std::vector<uint32_t> & get_gamemodes() const { return m_GameModes; }
    const std::vector<std::string> & get_langhostids() const { return m_LangHostIds; }
    const std::string & get_playertag() const { return m_PlayerTag; }
    const uint32_t & get_wordlen() const { return m_Wordlen; }

    void set_nooutlang(bool val) { m_NoOutLang = val; }
    void set_nooutgame(bool val) { m_NoOutGame = val; }
    void set_nooutres(bool val) { m_NoOutRes = val; }
    void set_testmode(bool val) { m_TestMode = val; }
    std::vector<uint32_t> & get_gamemodes() { return m_GameModes; }
    std::vector<std::string> & get_langhostids() { return m_LangHostIds; }
    void set_playertag(const std::string & playertag) { m_PlayerTag = playertag; }
    void set_wordlen(const uint32_t & wordlen) { m_Wordlen = wordlen; }

    bool defines_server() const {
        return !m_GameModes.empty() && !m_LangHostIds.empty()
               && m_Wordlen != 0 && !m_PlayerTag.empty();
    }
};


#endif //SHIFTS_APPCONFIG_H
