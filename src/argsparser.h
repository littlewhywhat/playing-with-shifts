#ifndef ARGS_PARSER
#define ARGS_PARSER

#include <iostream>
#include <vector>
#include <string>

#include "graphgen.h"
#include "appconfig.h"

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
    const std::string TAG_NO_OUT_GAME = "-nogame";
    const std::string TAG_TEST_MODE = "-test";
    const std::string TAG_STANDARD_PLAYER = "success";

    std::vector<std::string> m_Opts;
    std::string folder2console(const std::string & tag) const;
    void print_usage(uint32_t argc, char * argsv[]) const; 
    uint32_t stointopt(const std::string &val) const;
    bool find_tag(const std::string & tag) const;
    bool find_all_s_by_tag(const std::string & tag, std::vector<std::string> & opts_by_tag) const; 
    bool find_s_by_tag(const std::string & tag, std::string & val) const; 
    bool find_i_by_tag(const std::string & tag, uint32_t & val) const;
    bool find_all_i_by_tag(const std::string & tag, std::vector<uint32_t> & opts_by_tag) const;
    bool check_argc(uint32_t argc) const;
    bool is_double(const std::string & tag) const; 
    bool is_single(const std::string & tag) const; 
    bool only_gen() const; 
    bool set_graphgen(AppConfig & config) const;
    bool set_wordlen(AppConfig & config);
    bool set_modes(AppConfig & config);
    bool set_player(AppConfig & config);
    void set_standard_player(AppConfig & config);
    bool set_langhostids(AppConfig & config);
    void process_folders();
    void parse(AppConfig & config);
  public:
    ~ArgsParser() {};
    void parse(uint32_t argc, char * argsv[], AppConfig & config);
};

#endif
