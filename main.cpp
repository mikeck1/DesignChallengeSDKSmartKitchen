#include <iostream>
#include <sstream>

#include "examples/VendorExample.hpp"
#include "Vendor.hpp"
#include "SmartKitchenSDK.hpp"
#include "NetworkConnection.hpp"

SDK::VendorExample vendorExample; //Use your own Vendor class here...

size_t runNetworkOrCommandTest(SDK::Reasons aReason, SDK::NetworkConnection networkConnection, std::stringstream &aCommand)
{

    auto theResult = SDK::SmartKitchenSDK::run(vendorExample, networkConnection);
    if (aReason == theResult)
        return true;
    return false;
}

int main(int argc, const char *argv[])
{
    if (argc > 1)
    {
        const char *theStatus[] = {"FAIL", "PASS"};

        std::string temp(argv[1]);   // input prompt from user running program
        std::stringstream theStream; // command stream

        if ("compile" == temp)
        {
            std::cout << "Compile test PASS\n";
        }
        else if ("syntaxError" == temp)
        {
            SDK::NetworkConnection networkConnection = SDK::NetworkConnection("212", "123", "hi");
            bool result = runNetworkOrCommandTest(SDK::Reasons::syntaxError, networkConnection, theStream);
            std::cout << "Network:" + temp + " test " << theStatus[result] << "\n";
        }
        else if ("connection" == temp)
        {   // Should time out because no commands are sent, but connection is established
            SDK::NetworkConnection networkConnection = SDK::NetworkConnection("", "192.168.1.1", "localhost");
            bool result = runNetworkOrCommandTest(SDK::Reasons::standby, networkConnection, theStream);
            std::cout << "Network:" + temp + " test " << theStatus[result] << "\n";
        }
        else if ("productionTest" == temp)
        {
            std::string macAddress((sizeof(argv)==4) ? argv[4] : "");
            SDK::NetworkConnection networkConnection = SDK::NetworkConnection(macAddress, argv[3], argv[2]);
            SDK::SmartKitchenSDK::run(vendorExample, networkConnection);
        }
        else if ("production" == temp) 
        {
            SDK::SmartKitchenSDK::initPhoneViaBluetooth();
            SDK::SmartKitchenSDK::run(vendorExample);
        }
    }
}