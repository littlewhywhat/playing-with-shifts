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

class GameRoomService;

class AppContext {
  public:
    //TODO consider exception if m_LanguageService is NULL
    RealLanguageService & get_language_service() {
        return m_LanguageService;
    }
    GameSessionService & get_gamesession_service() {
        return m_GameSessionService;
    }
    GameRoomService & get_gameroom_service() {
        return m_GameRoomService;
    }
    Printer & get_printer() {
        return m_Printer;
    }
    static AppContext & get();
  private:
    RealLanguageService m_LanguageService;
    Printer m_Printer;
    GameSessionService m_GameSessionService;
    GameRoomService m_GameRoomService;
    AppContext() {};
    AppContext(const AppContext & src) = delete;
    AppContext & operator = (const AppContext & src) = delete;
};

#endif //PLAYING_WITH_SHIFTS_APPCONTEXT_H
