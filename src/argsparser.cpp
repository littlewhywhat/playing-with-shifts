#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "argsparser.h"
#include "playerfactory.h"
#include "player.h"
#include "gameserver.h"
#include "serverfactory.h"
#include "console.h"
#include "consolefactory.h"
#include "graphgen.h"

Console * ArgsParser::create_console(const std::string & tag, std::ostream & out) const {
    Console * c = ConsoleFactory::get() -> create_instance(tag, out);
    if (c)
        return c;
    throw "Wrong console!";
}
Player * ArgsParser::create_player(const std::string & tag) const {
    Player * p = PlayerFactory::get() -> create_instance(tag);
    if (p)
        return p;
    throw "Wrong player!";
}
GameServer * ArgsParser::create_server(const std::string & tag) const {
    GameServer * gs = ServerFactory::get() -> create_instance(m_ServerTag);        if (gs)
        return gs;
    throw "Wrong server!";
} 
std::string ArgsParser::folder2console(const std::string & tag) const {
    std::string console = tag;
    console.pop_back();
    return console;
}
void ArgsParser::print_usage(uint32_t argc, char * argsv[]) const {
    std::cout << "You typed: " << std::endl;
    const std::string SPACE = " ";
    for (uint32_t i = 0; i < argc; i++)
        std::cout << argsv[i] << SPACE;
    std::cout << std::endl;
}

uint32_t ArgsParser::stoi(const std::string & val) const {
    try {
        int i = std::stoi(val);
        if (i < 0)
            throw "Number arguments can't be negative!";
        return i;
    } catch (std::invalid_argument e) {
        throw "Invalid integer option";
    }
}
bool ArgsParser::find_tag(const std::string & tag) const {
    for (auto opt : m_Opts) 
        if (opt == tag)
            return true;
    return false;
}
bool ArgsParser::find_all_s_by_tag(const std::string & tag, std::vector<std::string> & opts_by_tag) const {
    for (uint32_t i = 0; i < m_Opts.size(); i++)
        if (m_Opts[i] == tag) {
            opts_by_tag.push_back(m_Opts[i]);
            opts_by_tag.push_back(m_Opts[++i]);
        }
    return !opts_by_tag.empty();
}
bool ArgsParser::find_s_by_tag(const std::string & tag, std::string & val) const {
    std::vector<std::string> opts_by_tag;
    if (!find_all_s_by_tag(tag, opts_by_tag))
        return false;
    if (opts_by_tag.size() > 2) 
        throw "Ambiguous argument";
    val = opts_by_tag[1];
    return true;
}
bool ArgsParser::find_i_by_tag(const std::string & tag, uint32_t & val) const {
    std::string val_s;
    if (!find_s_by_tag(tag, val_s))
        return false;
    val = stoi(val_s);
    return true;
}
bool ArgsParser::find_all_i_by_tag(const std::string & tag, std::vector<uint32_t> & opts_by_tag) const {
    for (uint32_t i = 0; i < m_Opts.size(); i++) 
        if (m_Opts[i] == tag) 
            opts_by_tag.push_back(stoi(m_Opts[++i]));
    return !opts_by_tag.empty();
}
bool ArgsParser::check_argc(uint32_t argc) const {
    return (argc > 1);
}
bool ArgsParser::is_double(const std::string & tag) const {
    return tag == TAG_GRAPH ||
           tag == TAG_BUILD ||
           tag == TAG_LANG ||
           tag == TAG_LANGFOLDER ||
           tag == TAG_GRAPHFOLDER ||
           tag == TAG_MODE ||
           tag == TAG_NUM_FILES ||
           tag == TAG_WORDLEN ||
           tag == TAG_SERVER ||
           tag == TAG_PLAYER ||
           tag == TAG_GRAPHGEN ||
           tag == TAG_NUM_NODES;
}
bool ArgsParser::is_single(const std::string & tag) const { 
    return tag == TAG_NO_OUT_RES ||
           tag == TAG_NO_OUT_LANG;
}
bool ArgsParser::only_gen() const {
    return m_Opts.size() == 6;
}
bool ArgsParser::set_graphgen() const {
    std::string folder;
    uint32_t nnodes;
    uint32_t nfiles;
    bool has_gg = find_s_by_tag(TAG_GRAPHGEN, folder);
    bool has_nn = find_i_by_tag(TAG_NUM_NODES, nnodes);
    bool has_nf = find_i_by_tag(TAG_NUM_FILES, nfiles);
    if (!has_gg && !has_nn)
        return false;
    if (has_gg && has_nn && !has_nf)
        throw "Provide number of files for generator";
    if (has_gg && has_nn && has_nf) {
        GraphGen gg;
        gg.gen(folder, nnodes, nfiles);

        return true;
    }
    throw "Provide more parameters for graphgeneration"; 
}
bool ArgsParser::set_wordlen() {
    bool found = find_i_by_tag(TAG_WORDLEN, m_WordLen);
    if (m_WordLen < 0 || m_WordLen > 63)
        throw "Wrong word length!";
    return found;
}
bool ArgsParser::set_modes() {
    return find_all_i_by_tag(TAG_MODE, m_GameModes); 
}
bool ArgsParser::set_player() {
    std::string player_tag;
    if (!find_s_by_tag(TAG_PLAYER, player_tag))
        return false;
    m_PlayerTag = player_tag;
    return true;
}
void ArgsParser::set_standard_player() {
    m_PlayerTag = TAG_STANDARD_PLAYER;
}
bool ArgsParser::set_game_server() {
    std::string server_tag;
    if (!find_s_by_tag(TAG_SERVER, server_tag))
        return false;
    m_ServerTag = server_tag;
    return true;
}
void ArgsParser::set_standard_server() {
    m_ServerTag = TAG_STANDARD_SERVER;
}

bool ArgsParser::set_what_single() {
    std::vector<std::string> what_tags;
    find_all_s_by_tag(TAG_GRAPH, what_tags);
    find_all_s_by_tag(TAG_LANG, what_tags);
    find_all_s_by_tag(TAG_BUILD, what_tags);
    if (what_tags.empty())
        return false;
    for (uint32_t i = 0; i < what_tags.size(); i += 2) {
        Console * console = create_console(what_tags[i], std::cout);
        console -> set_setup(what_tags[i+1]);
        console -> set_wordlen(m_WordLen);
        Player * player = create_player(m_PlayerTag);
        player -> set_out_lang(!find_tag(TAG_NO_OUT_LANG));
        player -> set_out_result(!find_tag(TAG_NO_OUT_RES));
        GameServer * gs = create_server(m_ServerTag);
        gs -> set_console(console);
        gs -> set_player(player);
        gs -> set_modes(m_GameModes);
        m_Servers.push_back(gs);
    }
    return true;
}

void ArgsParser::process_folders() {
    std::vector<std::string> folder_tags;
    uint32_t nfiles;
    bool has_folders = find_all_s_by_tag(TAG_GRAPHGEN, folder_tags) ||
                   find_all_s_by_tag(TAG_GRAPHFOLDER, folder_tags) ||
                   find_all_s_by_tag(TAG_LANGFOLDER, folder_tags);
    bool has_nfiles = find_i_by_tag(TAG_NUM_FILES, nfiles);
    if ((!has_folders && has_nfiles) || 
            (has_folders && !has_nfiles))
        throw "Please provide missing folder or count of files!";
    for (uint32_t i = 0; i < folder_tags.size(); i+=2) {
        for (uint32_t j = 0; j < nfiles; j++) {
            m_Opts.push_back(folder2console(folder_tags[i]));
            m_Opts.push_back(GraphGen::getname(folder_tags[i+1], j));
        }
    }
}
void ArgsParser::parse() {
    if (set_graphgen() && only_gen())
        return;
    if (!set_wordlen())
        throw "Please provide wordlen!";    
    if (!set_modes())
        throw "Please provide at least one mode!";
    if (!set_player())
        set_standard_player();
    if (!set_game_server())
        set_standard_server();
    process_folders();
    if (!set_what_single())
        throw "Please provide at least one object!";
}
ArgsParser::~ArgsParser() {
    for (auto server : m_Servers)
        delete server;
}
void ArgsParser::parse(uint32_t argc, char * argsv[]) {
    try {
        if (!check_argc(argc))
            throw "Wrong number of arguments";
        uint32_t i = 1;
        while (i < argc) {
            if (is_single(argsv[i])) {
                m_Opts.push_back(argsv[i]);
                i++;
            } else if (is_double(argsv[i])) {
                m_Opts.push_back(argsv[i]);
                if (i + 1 == argc)
                    throw "Complete the tag";
                m_Opts.push_back(argsv[i+1]);
                i += 2;
            } else {
               throw "Wrong tag"; 
            }
        }
        parse();
    } catch (const char * e) {
        std::cout << e << std::endl;
        print_usage(argc, argsv);
    }
}
