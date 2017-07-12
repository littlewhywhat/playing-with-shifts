//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_APPCONTEXT_H
#define PLAYING_WITH_SHIFTS_APPCONTEXT_H

#include <string>
#include "bundle.h"
#include "gamesessionservice.h"
#include "reallanguageservice.h"
#include "gameserverservice.h"
#include "gameroomservice.h"
#include "graphgen.h"
#include "graphgeneratorservice.h"

enum APP_MODE {
    GRAPH_GENERATOR,
    GAME_SERVER,
};

/*
 *  Defines context of application by
 *  services and printer parameters stored
 */

class AppContext {
  public:
    static const std::string TAG_FILTER;
    static const std::string NOOUT_LANG;
    static const std::string NOOUT_GAME;
    static const std::string NOOUT_RES;
    static const std::string TESTMODE;
    static const std::string TAG_GRAPHGEN;
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
    const GraphGen & get_graphgenerator() const {
        return m_Generator;
    }
    const GraphGeneratorService & get_graphgenerator_service() const {
        return m_GraphGeneratorService;
    }
    APP_MODE mode() const {
        return m_Mode;
    }
    void setup(const Bundle & config);
    static AppContext & get();
  private:
    RealLanguageService m_LanguageService;
    Printer m_Printer;
    GameSessionService m_GameSessionService;
    GameRoomService m_GameRoomService;
    GameServerService m_GameServerService;
    GraphGeneratorService m_GraphGeneratorService;
    GraphGen m_Generator;
    APP_MODE m_Mode;
    AppContext() {};
    AppContext(const AppContext & src) = delete;
    AppContext & operator = (const AppContext & src) = delete;
};

#endif //PLAYING_WITH_SHIFTS_APPCONTEXT_H
