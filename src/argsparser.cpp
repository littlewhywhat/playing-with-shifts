#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "argsparser.h"

std::string ArgsParser::folder2console(const std::string & tag) const {
    std::string console = tag;
    console.pop_back();
    return console;
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
           tag == TAG_NO_OUT_LANG ||
           tag == TAG_NO_OUT_GAME ||
           tag == TAG_TEST_MODE ||
           tag == TAG_FILTER;
}

void ArgsParser::convert(const ApplicationArguments & args, AppConfig &config) {
    config.set_wordlen(std::stoi(args.get_first_opt(TAG_WORDLEN)));
    for (const auto & mode : args.get_opts(TAG_MODE))
        config.get_gamemodes().push_back(std::stoi(mode));
    if (args.has_tag(TAG_PLAYER))
        config.set_playertag(args.get_first_opt(TAG_PLAYER));
    else
        config.set_playertag(TAG_STANDARD_PLAYER);
    std::vector<std::string> source_tags = { TAG_GRAPH, TAG_LANG, TAG_BUILD };
    for (auto & tag : source_tags) {
        if (!args.has_tag(tag))
            continue;
        for (auto &path : args.get_opts(tag)) {
            config.get_langhostids().push_back(tag);
            config.get_langhostids().push_back(path);
        }
    }
    std::vector<std::string> folder_tags = { TAG_GRAPHFOLDER, TAG_LANGFOLDER };
    if (args.has_tag(TAG_NUM_FILES)) {
        uint32_t num_files = std::stoi(args.get_first_opt(TAG_NUM_FILES));
        for (auto &tag : folder_tags) {
            if (!args.has_tag(tag))
                continue;
            for (auto &path : args.get_opts(tag)) {
                for (uint32_t i = 0; i < num_files; i++) {
                    config.get_langhostids().push_back(folder2console(tag));
                    config.get_langhostids().push_back(path);
                }
            }
        }
    }
    config.set_nooutlang(!args.has_tag(TAG_NO_OUT_LANG));
    config.set_nooutgame(!args.has_tag(TAG_NO_OUT_GAME));
    config.set_nooutres(!args.has_tag(TAG_NO_OUT_RES));
    config.set_testmode(args.has_tag(TAG_TEST_MODE));
    config.set_filter(args.has_tag(TAG_FILTER));
}
void ArgsParser::parse(const ApplicationArguments & args, AppConfig & config) {
    try {
        // simple validation
        if (args.empty())
            throw "Please provide some arguments";
        for (const auto & tag_options : args)
            if (!is_single(tag_options.first) &&
                    !is_double(tag_options.first))
                throw "Tag " + tag_options.first + " is not recognized";
        convert(args, config);
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
}
