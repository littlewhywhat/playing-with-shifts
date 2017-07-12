//
// Created by vaivorom on 3/24/17.
//

#ifndef SHIFTS_GRAPHGENERATORSERVICE_H
#define SHIFTS_GRAPHGENERATORSERVICE_H

#include <cstdint>
#include <string>

#include "bundle.h"

class GraphGeneratorService {
  public:
    static const std::string TAG_FILE;
    static const std::string TAG_NUM_GRAPHS;
    static const std::string TAG_NUM_NODES;

    void generate(const Bundle & bundle) const;
    void generate(const std::string & pathname,
                  const uint32_t & cnt_nodes,
                  const uint32_t & cnt_graphs) const;
};


#endif //SHIFTS_GRAPHGENERATORSERVICE_H
