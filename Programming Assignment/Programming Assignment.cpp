// G21328044 K.A Tharusha Lakshan Dananjaya

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "DeviceManager.hpp"

void memoryLeakCheck()
{

#ifdef _DEBUG //run only in debug mode
	_CrtDumpMemoryLeaks();
#endif

}

int main()
{
	atexit(memoryLeakCheck); // make sure memory leak check runs when the program exits

	std::unique_ptr<DeviceManager> manager = std::make_unique<DeviceManager>();

	manager->run(); // Run the device management system
} 


