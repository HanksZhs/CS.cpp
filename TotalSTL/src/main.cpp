// memory leak check.
#if defined(_MSC_VER) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// with detail description of memory leak.
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)
void turnOnMemroyCheck() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
#endif

#include "inc.h"
#include "gtest/gtest.h"
#include "util/FileReader.h"

void dummyExitFunction() {
    elloop::FileReader::getInstance()->purege();

	char c = getchar();
}



int main(int argc, char** argv) {

#if defined(_MSC_VER) && defined(_DEBUG)
	// make program stop when debug.
	atexit(dummyExitFunction);
	turnOnMemroyCheck();
#endif

    //_CrtSetBreakAlloc(2443); // break at 2443th memory alloc.

	// use gtest.
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}