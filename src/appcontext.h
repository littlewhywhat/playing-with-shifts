//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_APPCONTEXT_H
#define PLAYING_WITH_SHIFTS_APPCONTEXT_H


#include "languageservice.h"
#include "printer.h"
#include "gamesessionservice.h"
#include "gameroomservice.h"
#include "reallanguageservice.h"
#include "gameserverservice.h"
#include "appconfig.h"

class AppContext {
  public:
    //TODO consider exception if m_LanguageService is NULL
    const RealLanguageService & get_language_service() const {
        return m_LanguageService;
    }
    const GameSessionService & get_gamesession_service() const {
        return m_GameSessionService;
    }
    const GameRoomService & get_gameroom_service() const {
        return m_GameRoomService;
    }
    const GameServerService & get_gameserver_service() const {
        return m_GameServerService;
    }
    const Printer & get_printer() const {
        return m_Printer;
    }
    void setup(const AppConfig & config) {
        m_Printer.set_out_lang(config.get_nooutlang());
        m_Printer.set_out_game(config.get_nooutgame());
        m_Printer.set_out_score(config.get_nooutres());
        m_Printer.set_out_test(config.get_testmode());
    }
    static AppContext & get();
  private:
    RealLanguageService m_LanguageService;
    Printer m_Printer;
    GameSessionService m_GameSessionService;
    GameRoomService m_GameRoomService;
    GameServerService m_GameServerService;
    AppContext() {};
    AppContext(const AppContext & src) = delete;
    AppContext & operator = (const AppContext & src) = delete;
};

#endif //PLAYING_WITH_SHIFTS_APPCONTEXT_H
