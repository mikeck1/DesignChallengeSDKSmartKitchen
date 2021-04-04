#include "VendorExample.hpp"

namespace SDK
{
    void VendorExample::readCommand(std::string aCommand) { command = aCommand; }

    std::stringstream VendorExample::writeCommand()
    {
        // deviceID1 deviceID2 command
        sstream << "123456789 987654321 playSound doorbell";
    }
    /* Vendor to add implimentation here */
}