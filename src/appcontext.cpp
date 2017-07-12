//
// Created by vaivorom on 3/23/17.
//

#include "appcontext.h"

const std::string AppContext::TAG_FILTER = "filter";
const std::string AppContext::NOOUT_LANG = "out_lang";
const std::string AppContext::NOOUT_GAME = "out_game";
const std::string AppContext::NOOUT_RES = "out_res";
const std::string AppContext::TESTMODE = "test mode";
const std::string AppContext::TAG_GRAPHGEN = "graphgen";

AppContext & AppContext::get() {
    static AppContext context;
    return context;
}

void AppContext::setup(const Bundle &config) {
    if (config.has_tag_in_bools(TAG_GRAPHGEN)) 
        m_Mode = GRAPH_GENERATOR;
    else
        m_Mode = GAME_SERVER;
    if (config.has_tag_in_bools(TAG_FILTER))
        m_Printer.set_filter(new PlayedSessionFilter());
    m_Printer.set_out_lang(!config.has_tag_in_bools(NOOUT_LANG));
    m_Printer.set_out_game(!config.has_tag_in_bools(NOOUT_GAME));
    m_Printer.set_out_score(!config.has_tag_in_bools(NOOUT_RES));
    m_Printer.set_out_test(config.has_tag_in_bools(TESTMODE));
}
