#ifndef ARGS_PARSER
#define ARGS_PARSER

#include <iostream>
#include <vector>
#include <string>

#include "player.h"
#include "gameserver.h"
#include "console.h"
#include "graphgen.h"

class ArgsParser {
  private:
    const std::string TAG_WORDLEN = "-w";
    const std::string TAG_GRAPH = "-g";
    const std::string TAG_BUILD = "-b";
    const std::string TAG_LANG = "-l";
    
    const std::string TAG_LANGFOLDER = "-lf";
    const std::string TAG_GRAPHFOLDER = "-gf";
    
    const std::string TAG_NUM_FILES = "-n";
    const std::string TAG_NUM_NODES = "-nn";
    const std::string TAG_GRAPHGEN = "-gg"; 
    
    const std::string TAG_MODE = "-m";
    const std::string TAG_PLAYER = "-p";
    const std::string TAG_SERVER = "-gs";
    const std::string TAG_NO_OUT_RES = "-nores";
    const std::string TAG_NO_OUT_LANG = "-nolang";
    const std::string TAG_STANDARD_PLAYER = "player";
    const std::string TAG_STANDARD_SERVER = "gameserver";

    uint32_t m_WordLen;
    std::string m_PlayerTag;
    std::string m_ServerTag;
    std::vector<GameServer *> m_Servers;
    std::vector<std::string> m_Opts;
    std::vector<uint32_t> m_GameModes;
    Console * create_console(const std::string & tag, std::ostream & out) const;
    Player * create_player(const std::string & tag) const;
    GameServer * create_server(const std::string & tag) const;
    std::string folder2console(const std::string & tag) const;
    void print_usage(uint32_t argc, char * argsv[]) const; 
    uint32_t stoi(const std::string & val) const; 
    bool find_tag(const std::string & tag) const;
    bool find_all_s_by_tag(const std::string & tag, std::vector<std::string> & opts_by_tag) const; 
    bool find_s_by_tag(const std::string & tag, std::string & val) const; 
    bool find_i_by_tag(const std::string & tag, uint32_t & val) const;
    bool find_all_i_by_tag(const std::string & tag, std::vector<uint32_t> & opts_by_tag) const;
    bool check_argc(uint32_t argc) const;
    bool is_double(const std::string & tag) const; 
    bool is_single(const std::string & tag) const; 
    bool only_gen() const; 
    bool set_graphgen() const; 
    bool set_wordlen();
    bool set_modes(); 
    bool set_player();
    void set_standard_player(); 
    bool set_game_server();
    void set_standard_server(); 
    bool set_what_single(); 
    void process_folders();
    void parse();
  public:
    ~ArgsParser(); 
    std::vector<GameServer *> & servers() { return m_Servers; }
    void parse(uint32_t argc, char * argsv[]); 
};

#endif
