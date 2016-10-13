#ifndef ARGS_PARSER
#define ARGS_PARSER

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "playerfactory.h"
#include "player.h"
#include "gameserver.h"
#include "serverfactory.h"
#include "console.h"
#include "consolefactory.h"
#include "graphgen.h"

class ArgsParser {
  private:
    const std::string TAG_WORDLEN = "-w"; // obligatory
    const std::string TAG_GRAPH = "-g"; //  at least -> graphconsole
    const std::string TAG_BUILD = "-b"; //  one of  -> buildconsole
    const std::string TAG_LANG = "-l"; // these -> langconsole
    const std::string TAG_LANGFOLDER = "-lf"; // these -> langconsole
    const std::string TAG_GRAPHFOLDER = "-gf"; // these -> graphdconsole
    const std::string TAG_NUM_FILES = "-n";
    const std::string TAG_NUM_NODES = "-nn";
    const std::string TAG_GRAPHGEN = "-gg"; 
    const std::string TAG_MODE = "-m"; // at least one -> 1 - gameserver
                                       //                > 1 - diffserver
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
    Console * create_console(const std::string & tag, std::ostream & out) const {
        Console * c = ConsoleFactory::get() -> create_instance(tag, out);
        if (c)
            return c;
        throw "Wrong console!";
    }
    Player * create_player(const std::string & tag) const {
        Player * p = PlayerFactory::get() -> create_instance(tag);
        if (p)
            return p;
        throw "Wrong player!";
    }
    GameServer * create_server(const std::string & tag) {
        GameServer * gs = ServerFactory::get() -> create_instance(m_ServerTag);        if (gs)
            return gs;
        throw "Wrong server!";
    } 
    std::string folder2console(const std::string & tag) {
        std::string console = tag;
        console.pop_back();
        return console;
    }
    void print_usage(uint32_t argc, char * argsv[]) {
        std::cout << "You typed: " << std::endl;
        const std::string SPACE = " ";
        for (uint32_t i = 0; i < argc; i++)
            std::cout << argsv[i] << SPACE;
        std::cout << std::endl;
    }

    uint32_t stoi(const std::string & val) {
        try {
            int i = std::stoi(val);
            if (i < 0)
                throw "Number arguments can't be negative!";
            return i;
        } catch (std::invalid_argument e) {
            throw "Invalid integer option";
        }
    }
    bool find_tag(const std::string & tag) {
        for (auto opt : m_Opts) 
            if (opt == tag)
                return true;
        return false;
    }
    bool find_all_s_by_tag(const std::string & tag, std::vector<std::string> & opts_by_tag) {
        for (uint32_t i = 0; i < m_Opts.size(); i++)
            if (m_Opts[i] == tag) {
                opts_by_tag.push_back(m_Opts[i]);
                opts_by_tag.push_back(m_Opts[++i]);
            }
        return !opts_by_tag.empty();
    }
    bool find_s_by_tag(const std::string & tag, std::string & val) {
        std::vector<std::string> opts_by_tag;
        if (!find_all_s_by_tag(tag, opts_by_tag))
            return false;
        if (opts_by_tag.size() > 2) 
            throw "Ambiguous argument";
        val = opts_by_tag[1];
        return true;
    }
    bool find_i_by_tag(const std::string & tag, uint32_t & val) {
        std::string val_s;
        if (!find_s_by_tag(tag, val_s))
            return false;
        val = stoi(val_s);
        return true;
    }
    bool find_all_i_by_tag(const std::string & tag, std::vector<uint32_t> & opts_by_tag) {
        for (uint32_t i = 0; i < m_Opts.size(); i++) 
            if (m_Opts[i] == tag) 
                opts_by_tag.push_back(stoi(m_Opts[++i]));
        return !opts_by_tag.empty();
    }
    bool check_argc(uint32_t argc) {
        return (argc > 1);
    }
    bool is_double(const std::string & tag) {
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
    bool is_single(const std::string & tag) { 
        return tag == TAG_NO_OUT_RES ||
               tag == TAG_NO_OUT_LANG;
    }
    bool only_gen() {
        return m_Opts.size() == 6;
    }
    bool set_graphgen() {
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
    bool set_wordlen() {
        bool found = find_i_by_tag(TAG_WORDLEN, m_WordLen);
        if (m_WordLen < 0 || m_WordLen > 63)
            throw "Wrong length!";
        return found;
    }
    bool set_modes() {
        return find_all_i_by_tag(TAG_MODE, m_GameModes); 
    }
    bool set_player() {
        std::string player_tag;
        if (!find_s_by_tag(TAG_PLAYER, player_tag))
            return false;
        m_PlayerTag = player_tag;
        return true;
    }
    void set_standard_player() {
        m_PlayerTag = TAG_STANDARD_PLAYER;
    }
    bool set_game_server() {
        std::string server_tag;
        if (!find_s_by_tag(TAG_SERVER, server_tag))
            return false;
        m_ServerTag = server_tag;
        return true;
    }
    void set_standard_server() {
        m_ServerTag = TAG_STANDARD_SERVER;
    }
    
    bool set_what_single() {
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

    void process_folders() {
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
    // set wordlen
    // first - modes and player
    // second - gameserver type
    // then - all graphs, subshs or whatever - create GameServers
    // first singular
    // second folder and number of graphs, languages
    void parse() {
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
  public:
    ~ArgsParser() {
        for (auto server : m_Servers)
            delete server;
    }
    std::vector<GameServer *> & servers() {
        return m_Servers;
    }
    void parse(uint32_t argc, char * argsv[]) {
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
};

#endif
