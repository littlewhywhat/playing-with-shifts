//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H
#define PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H


#include "language.h"
#include "gameroom.h"
#include "appcontext.h"

class GameServer {
  public:
    GameServer(const Printer & printer) : m_Printer(printer) {}
    void launch() {
//        for (auto & room : m_Rooms)
//            run_gameroom(m_Room);
    }
    void add_room(std::vector<uint32_t> & modes, const std::string & player_tag, const uint32_t & wordlen ) {
        GameRoom * room = new GameRoom();
//        for (auto &mode : modes)
//            room->add_session(
//                    new GameSession(create_game(mode), create_player(player_tag, wordlen), new Judge(), wordlen));
//        gs->set_wordlen(m_WordLen);
//        m_Rooms.push_back(gs);
    }
  private:
    const Printer & m_Printer;

    const LanguageService & get_console() const {
        return AppContext::get().get_language_service();
    }
    void run_gameroom(const std::string & lang_id) const {
            Language lang;
//            get_console().start(lang_id, lang, m_WordLen);
//            m_Printer.send_to_print(lang);
//            GameServer room;
//            room.launch(lang, printer());
    }
};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H
