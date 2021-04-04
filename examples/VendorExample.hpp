/*
 * Vendor would change the main file to be VendorClass name (Currently VendorExample)
 */

#ifndef VendorExample_hpp
#define VendorExample_hpp

#include "../Vendor.hpp"

namespace SDK
{
    class VendorExample : public Vendor
    {
    public:
        virtual void readCommand(std::string aCommand) {};
        virtual std::stringstream writeCommand() {};
        /* Vendor to add implimentation here */
    protected:
    };
}
#endif