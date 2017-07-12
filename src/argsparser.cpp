#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "argsparser.h"
#include "bundle.h"
#include "gameserverservice.h"
#include "appcontext.h"

bool ArgsParser::is_double(const std::string & tag) const {
    return tag == TAG_LANGFOLDER ||
           tag == TAG_GRAPHFOLDER ||
           tag == TAG_MODE ||
           tag == TAG_NUM_FILES ||
           tag == TAG_WORDLEN ||
           tag == TAG_PLAYER ||
           tag == TAG_GRAPHGEN ||
           tag == TAG_NN ||
           tag == TAG_FILE;
}
bool ArgsParser::is_single(const std::string & tag) const { 
    return tag == TAG_GRAPH ||
           tag == TAG_BUILD ||
           tag == TAG_LANG ||
           tag == TAG_NO_OUT_RES ||
           tag == TAG_NO_OUT_LANG ||
           tag == TAG_NO_OUT_GAME ||
           tag == TAG_TEST_MODE ||
           tag == TAG_FILTER;
}

void ArgsParser::convert(const ApplicationArguments & args, Bundle & bundle) {
    map_to_bundle(args, MAP_ARGS_TO_INTVEC,
                  [& bundle](const std::string & bundle_tag, const std::string & opt){
        // conversion to int
        bundle.push_to_intvector(bundle_tag, std::stoi(opt));
    });
    map_to_bundle(args, MAP_ARGS_TO_STRVEC,
                  [& bundle](const std::string & bundle_tag, const std::string & opt){
        // no conversion
        bundle.push_to_strvector(bundle_tag, opt);
    });
    map_to_bundle(args, MAP_ARGS_BOOLS,
        [& bundle](const std::string & bundle_tag, const std::string & opt){
        // conversion to bool
        bundle.push_to_bools(bundle_tag, true);
    });
}
void ArgsParser::parse(const ApplicationArguments & args, Bundle & bundle) {
    try {
        // simple validation
        if (args.empty())
            throw "Please provide some arguments";
        for (const auto & tag_options : args)
            if (!is_single(tag_options.first) &&
                    !is_double(tag_options.first))
                throw "Tag " + tag_options.first + " is not recognized";
        // all tags are valid
        convert(args, bundle);
    } catch (std::string const & e) {
        std::cout << e << std::endl;
        throw e;
    }
}

template<typename Func>
void ArgsParser::map_to_bundle(const ApplicationArguments &args, std::multimap<std::string, std::string> input_real_map, Func func) {
    std::multimap<std::string, std::string>::const_iterator pair_input_real = input_real_map.cbegin();
    std::string current_tag;
    while (pair_input_real != input_real_map.cend()) {
        current_tag = pair_input_real->first;
        if (args.has_tag(pair_input_real->first)) {
            const auto & opts = args.get_opts(pair_input_real->first);
            while (pair_input_real != input_real_map.cend() && pair_input_real->first == current_tag) {
                if (opts.empty())
                    func(pair_input_real->second, "");
                else
                    for (auto &opt : opts)
                        func(pair_input_real->second, opt);
                ++pair_input_real;
            }
        } else {
            while (pair_input_real != input_real_map.cend() && pair_input_real->first == current_tag) {
                ++pair_input_real;
            }
        }
    }
}

ArgsParser::ArgsParser() {
    MAP_ARGS_TO_INTVEC =
            {
                { TAG_WORDLEN, GameServerService::TAG_WORDLEN },
                { TAG_MODE, GameServerService::TAG_MODES },
                { TAG_NN, GameServerService::TAG_NUM_PATHS }
            };
    MAP_ARGS_TO_STRVEC =
            {
                { TAG_FILE, GameServerService::TAG_FILE },
                { TAG_PLAYER, GameServerService::TAG_PLAYER },
            };
    MAP_ARGS_BOOLS =
            {
                { TAG_GRAPH, GameServerService::TAG_GRAPH_PATHS },
                { TAG_LANG, GameServerService::TAG_LANG_PATHS },
                { TAG_BUILD, GameServerService::TAG_BUILD_PATHS },
                { TAG_FILTER, AppContext::TAG_FILTER },
                { TAG_NO_OUT_LANG, AppContext::NOOUT_LANG },
                { TAG_NO_OUT_RES, AppContext::NOOUT_RES },
                { TAG_NO_OUT_GAME, AppContext::NOOUT_GAME },
                { TAG_TEST_MODE, AppContext::TESTMODE }
            };
}
