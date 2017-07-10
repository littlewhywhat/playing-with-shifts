#ifndef ARGS_PARSER
#define ARGS_PARSER

#include <iostream>
#include <vector>
#include <string>

#include "applicationarguments.h"
#include "bundle.h"

/*
 *  Looks for tags t in ApplicationArguments 
 *  defined by mappings and copies their parameters 
 *  into Bundle with tags f(t)
 */
class ArgsParser {
  public:
    ArgsParser();
    ~ArgsParser() {};
    void parse(const ApplicationArguments & args, Bundle & bundle);
  private:
    const std::string TAG_WORDLEN = "-w";
    const std::string TAG_GRAPH = "-g";
    const std::string TAG_BUILD = "-b";
    const std::string TAG_LANG = "-l";

    const std::string TAG_LANGFOLDER = "-lf";
    const std::string TAG_GRAPHFOLDER = "-gf";

    const std::string TAG_NUM_FILES = "-n";
    const std::string TAG_NN = "-nn";
    const std::string TAG_GRAPHGEN = "-gg";

    const std::string TAG_MODE = "-m";
    const std::string TAG_PLAYER = "-p";
    const std::string TAG_NO_OUT_RES = "-nores";
    const std::string TAG_NO_OUT_LANG = "-nolang";
    const std::string TAG_NO_OUT_GAME = "-nogame";
    const std::string TAG_TEST_MODE = "-test";
    const std::string TAG_FILTER = "-filter";

    std::multimap<std::string, std::string> MAP_ARGS_TO_INTVEC;
    std::multimap<std::string, std::string> MAP_ARGS_TO_STRVEC;
    std::multimap<std::string, std::string> MAP_ARGS_BOOLS;

    bool is_double(const std::string & tag) const;
    bool is_single(const std::string & tag) const;
    template <typename Func>
    void map_to_bundle(const ApplicationArguments & args,
                       std::multimap<std::string, std::string> map, Func func);
    void convert(const ApplicationArguments &args, Bundle &bundle);
};

#endif
