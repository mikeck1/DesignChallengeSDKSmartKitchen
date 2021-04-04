#ifndef NetworkConnection_hpp
#define NetworkConnection_hpp
#include <string>
namespace SDK {
    struct NetworkConnection {
        NetworkConnection(std::string mac, std::string ip, std::string aName) : macAddress(mac), ipAddress(ip), name(aName) {}
        std::string macAddress;
        std::string ipAddress;
        std::string name;
    };
}
#endif