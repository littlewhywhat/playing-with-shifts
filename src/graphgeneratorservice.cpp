//
// Created by vaivorom on 3/24/17.
//

#include "graphgeneratorservice.h"
#include "appcontext.h"

const std::string GraphGeneratorService::TAG_NUM_GRAPHS = "num_graphs";
const std::string GraphGeneratorService::TAG_NUM_NODES = "num_nodes";
const std::string GraphGeneratorService::TAG_FILE = "file";

void GraphGeneratorService::generate(const Bundle & bundle) const {
    const std::string & path = bundle.get_str(TAG_FILE);
    uint32_t num_nodes = bundle.get_int(TAG_NUM_NODES);
    uint32_t num_graphs = bundle.get_int(TAG_NUM_GRAPHS);
    generate(path, num_nodes, num_graphs);
}

void GraphGeneratorService::generate(const std::string &pathname, 
                                     const uint32_t &cnt_nodes,
                                     const uint32_t &cnt_graphs) const {
    AppContext::get().get_graphgenerator()
                     .gen(pathname,
                          cnt_nodes,
                          cnt_graphs);
}
