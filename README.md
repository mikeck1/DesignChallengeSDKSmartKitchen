# Smart Kitchen SDK

#### Automated Test
```	
./runTests.sh
```
#### Production test
```
./VendorProgram productionTest hostName ipaddress {optional|macAddress}
```

#### Production
```
./VendorProgram production
```

#### Vendor Instructions
Network connection is required. Change network connection 

Main will call SDK::SmartKitchenSDK::run and pass your vendor class and network connection.

Write your vendor class (Check /examples)