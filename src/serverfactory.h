#ifndef SERVERFACTORY_H
#define SERVERFACTORY_H

#include <cstdint>

#include "gameserver.h"

class ServerFactory {
  private:
    ServerFactory();
    ServerFactory(const ServerFactory & src) = delete;
    ServerFactory & operator = (const ServerFactory & src) = delete;
    typedef GameServer* (*create_server_fn)();
    std::map<std::string, create_server_fn> server_map;
  public:
    ~ServerFactory() {};

    static ServerFactory * get() {
        static ServerFactory singleton;
        return &singleton;
    }

    void reg_server(const std::string & type, create_server_fn func);
    GameServer * create_instance(const std::string & type) const;
};

#endif
