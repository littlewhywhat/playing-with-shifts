#ifndef MODEFACTORY_H
#define MODEFACTORY_H

#include <cstdint>

#include "mode.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"

class ModeFactory {
  private:
    ModeFactory() {
    	reg_mode(1, &Mode1::create);
    	reg_mode(2, &Mode2::create);
    	reg_mode(3, &Mode3::create);
    }
    ModeFactory(const ModeFactory & src) = delete;
    ModeFactory & operator = (const ModeFactory & src) = delete;
    typedef Mode* (*create_mode_fn)(const uint32_t & wordlen);
    std::map<uint32_t, create_mode_fn> mode_map;
  public:
    ~ModeFactory() {};

    static ModeFactory * get() {
        static ModeFactory singleton;
        return &singleton;
    }

    void reg_mode(const uint32_t & type, create_mode_fn func) {
    	mode_map[type] = func;
    }
    Mode * create_instance(const uint32_t & type, const uint32_t & wordlen) const {
    	auto search = mode_map.find(type);
    	if (search != mode_map.end())
    		return search -> second(wordlen);
    	return NULL;
    }
};

#endif