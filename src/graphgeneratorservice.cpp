//
// Created by vaivorom on 3/24/17.
//

#include "graphgeneratorservice.h"
#include "appcontext.h"

void GraphGeneratorService::generate(const std::string &pathname, const uint32_t &cnt_nodes,
                                     const uint32_t &cnt_graphs) const {
    AppContext::get().get_graphgenerator()
            .gen(pathname,
                 cnt_nodes,
                 cnt_graphs);
}
