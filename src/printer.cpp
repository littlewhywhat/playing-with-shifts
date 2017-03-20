//
// Created by littlewhywhat on 3/19/17.
//

#include "printer.h"

void Printer::print(const std::set<std::string> &wordset) {
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

void Printer::print_score(const Judge &judge) const {
    if (!m_OutTest)
        std::cout << "max = ";
    std::cout << judge.current_score() << std::endl;
}

void Printer::print_score(const uint32_t &score) const {
    if (!m_OutTest)
        std::cout << "max = ";
    std::cout << score << std::endl;
}

void Printer::send_to_print(const SessionResults &results) {
    for (const auto & strategy : results.get_strategies())
        send_to_print(strategy);
    send_to_print_score(results.get_score());
}
