#ifndef ARGS_PARSER
#define ARGS_PARSER

#include <iostream>
#include <vector>
#include <string>

#include "graphgen.h"
#include "appconfig.h"
#include "applicationarguments.h"

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
    const std::string TAG_FILTER = "-filter";
    const std::string TAG_STANDARD_PLAYER = "success";

    std::string folder2console(const std::string & tag) const;
    bool is_double(const std::string & tag) const;
    bool is_single(const std::string & tag) const; 
    void convert(const ApplicationArguments &args, AppConfig &config);
  public:
    ~ArgsParser() {};
    void parse(const ApplicationArguments & args, AppConfig & config);
};

#endif
