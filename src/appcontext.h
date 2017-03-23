//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_APPCONTEXT_H
#define PLAYING_WITH_SHIFTS_APPCONTEXT_H


#include "languageservice.h"
#include "languageservicefactory.h"
#include "printer.h"
#include "gamesessionservice.h"
#include "gameroomservice.h"

class GameRoomService;

class AppContext {
  public:
    //TODO consider exception if name is not found
    void set_console(std::string & name) {
        m_Console = LanguageServiceFactory::get()->create_instance(name);
    }
    //TODO consider exception if m_Console is NULL
    LanguageService & get_language_service() {
        return *m_Console;
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
    LanguageService * m_Console;
    Printer m_Printer;
    GameSessionService m_GameSessionService;
    GameRoomService m_GameRoomService;
    AppContext() : m_Console(NULL) {};
    AppContext(const AppContext & src) = delete;
    AppContext & operator = (const AppContext & src) = delete;
};

#endif //PLAYING_WITH_SHIFTS_APPCONTEXT_H
