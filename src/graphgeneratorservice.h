//
// Created by vaivorom on 3/24/17.
//

#ifndef SHIFTS_GRAPHGENERATORSERVICE_H
#define SHIFTS_GRAPHGENERATORSERVICE_H

#include <cstdint>
#include <string>

class GraphGeneratorService {
  public:
    void generate(const std::string & pathname,
                  const uint32_t & cnt_nodes,
                  const uint32_t & cnt_graphs) const;
};


#endif //SHIFTS_GRAPHGENERATORSERVICE_H
