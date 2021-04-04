/* Vendors would not have the source code to this file
 * This would be included as a .o binary file.
 */
#include "SmartKitchenSDK.hpp"
#include <stdio.h>
#include <cstdlib>

namespace SDK
{
    // Various Models
    enum class CommandStatus
    {
        input,
        output,
        cloudGET,
        cloudPUT,
        cloudDELETE,
        cloudPOST,
        streamVideo
    };

    /* Initializes Wifi Credentials using Phone. Sends credentials to SDK datastore. */
    Reasons SmartKitchenSDK::initPhoneViaBluetooth()
    {
        return Reasons::offline;
    }

    class RealSmartKitchenSDK : public SmartKitchenSDK
    {
        Reasons reason;
        std::string command;
        CommandStatus commandStatus;

    public:
        
        RealSmartKitchenSDK() : SmartKitchenSDK() {}
        // Checks network connection or vendor forced exit.
        bool SDKCanContinue(NetworkConnection network, Vendor &vendor)
        {
            return false;
        }

        /* Check aStream holds a command that is:
        ** Valid, Safe, etc.
        ** If error update reason stringsteam is invalid
        ** Set commandStatus to input or ouput
        */
        void checkStream(std::stringstream &aStream)
        {
            reason = Reasons::tbd; // no issue with aStream
            command = "";          // update command if aStream contains command for vendor device
        }

        // Interpret command into CoR and possible thread factory pool if video, https, cloud functions, etc.
        void processCommand(std::string)
        {
        }

        // update stream if write command from vendor and command is correct input
        void updateStream(std::stringstream aStream) {}

        // Returns vendor ID
        std::string getVendorID(Vendor &vendor) { return "123"; }

        // Log reason, network connection status by vendorID
        void log(std::string vendorID, Reasons reason, NetworkConnection networkconnection) {}

        /* Broadcast command to all devices using Secure Message Router pattern */
        void broadcastCommand(std::string) // Send command to all devices by Secure Message Router
        {
        }

        /* Runs the Real SDK. Vendor can only read/write to aStream. If aStream contains error or is 
        malicous or issue with network; return reason why run failed. */
        Reasons run(Vendor &vendor, NetworkConnection network)
        {
            std::stringstream aStream;
            // I/O commands if no conflicting reason and the SDK can continue to process commands
            while (Reasons::tbd == reason && SDKCanContinue(network, vendor))
            {
                // Validate Command
                updateStream(vendor.writeCommand());
                checkStream(aStream); // changes reason if issue with aStream, updates command if aSteam contains command for vendor device

                if (command.length()) // Process Command
                {
                    if (commandStatus == CommandStatus::input)
                        vendor.readCommand(command); // passes command to vendor.
                    else if (commandStatus == CommandStatus::output)
                        broadcastCommand(command); // Command is valid and authenticated so it is safe to broadcast
                    else
                        processCommand(command); // might I/O data by datastore, stream video,  cloud function, https GET/POST, etc.
                }
            }

            log(getVendorID(vendor), reason, network); // Log connecting, bad command, network issue, etc.

            return reason;
        }
    };

    // Passes vendor and network to the real SDK by Inversion of Control Pattern
    Reasons SmartKitchenSDK::run(Vendor &vendor, NetworkConnection network)
    {
        RealSmartKitchenSDK theSDK;
        return theSDK.run(vendor, network);
    }
}