#ifndef Vendor_hpp
#define Vendor_hpp

#include <string>
#include <sstream>
namespace SDK
{
    class SmartKitchenSDK; //forward declare...

    class Vendor
    {
    public:
        virtual void readCommand(std::string aCommand);
        virtual std::stringstream writeCommand();
    protected:
        std::string command;
        std::stringstream sstream;
    };
}
#endif