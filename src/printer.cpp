//
// Created by littlewhywhat on 3/19/17.
//

#include "printer.h"
#include "gameroom.h"

void Printer::print(const Language &wordset) const {
    if (!m_OutTest)
        std::cout << "language:" << std::endl;
    for (auto & word : wordset)
        std::cout << word << std::endl;
    std::cout << std::endl;
}

void Printer::print(const Strategy &strategy) const {
    std::cout << strategy << std::endl;
}

void Printer::announce(const Judge &judge) const {
    if (!m_OutTest)
        std::cout << "good strategies are:" << std::endl;
}

void Printer::print_score(const uint32_t &score) const {
    if (!m_OutTest)
        std::cout << "max = ";
    std::cout << score << std::endl;
}

void Printer::send_to_print(const GameSession &session) const {
    const Judge &judge = session.get_judge();
    judge.announce_to(*this);
    for (const auto &strategy : session.won_history())
        send_to_print(strategy);
    send_to_print_score(judge.current_score());
}

void Printer::print(const GameRoom &room) const {
    if (m_Filter && !m_Filter -> accepts(room))
        return;
    std::cout << room.get_langid() << std::endl;
    for (auto & session : room.get_sessions())
        send_to_print(*session);
}
