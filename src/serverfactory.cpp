#include <cstdint>

#include "serverfactory.h"
#include "gameserver.h"

ServerFactory::ServerFactory() {
    reg_server("gameserver", &GameServer::create);
}
void ServerFactory::reg_server(const std::string & type, create_server_fn func) {
    server_map[type] = func;
}
GameServer * ServerFactory::create_instance(const std::string & type) const {
    auto search = server_map.find(type);
    if (search != server_map.end())
        return search -> second();
    return NULL;
}
