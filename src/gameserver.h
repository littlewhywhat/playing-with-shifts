#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "console.h"

class GameServer {
  private:
    Player & m_Player;
    Console & m_Console;
    const std::vector<uint32_t> & m_GameModes;
    uint32_t process_mode(const uint32_t & game_mode) {
        m_Console.reset();
        m_Console.load(game_mode);
        m_Player.play(m_Console);
        uint32_t score = m_Player.score();
        return score;
    }
 public:
    GameServer(Console & console, Player & player, const std::vector<uint32_t> & game_modes) :
        m_Console(console), m_Player(player), m_GameModes(game_modes) {}
    void launch() {
        uint32_t score_0 = process_mode(m_GameModes[0]);
        for (uint32_t i = 1; i < m_GameModes.size(); i++) { 
            uint32_t score_i = process_mode(m_GameModes[i]);
            if (score_0 != score_i) {
                uint32_t diff = score_0 > score_i ? score_0 - score_i : score_i - score_0;
                m_Console.print_info();
                std::cout << "difference: " << diff << std::endl;
            }
        }
    }
};

#endif