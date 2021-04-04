#ifndef SmartKitchenSDK_hpp
#define SmartKitchenSDK_hpp

#include "Vendor.hpp"
#include "NetworkConnection.hpp"

#include <sstream>

namespace SDK {
    

    // Indicate status of Bluetooth of Wifi connection
    // enum class NetworkStatus {online,offline,standby,notreachable};
    enum class Reasons
    {
        tbd,
        syntaxError,
        badCommand,
        authExpired,
        badAuth,
        offline,
        standby,
        notreachable
    };

    class SmartKitchenSDK {
        public:
            static const NetworkConnection network;
            // To control device from a phone, get Wifi credentials, etc.
            static Reasons initPhoneViaBluetooth();
            static Reasons run(Vendor &vendor, NetworkConnection network);
            static Reasons run(Vendor &vendor) {}
        protected:
        
    };
}

#endif