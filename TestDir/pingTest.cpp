#include "../App.h"
#include "test.h"
int main(){
	
	test t;

	t.testThreadApp();
	t.testCycleApp();
	t.testPrivateApp();
	t.testMessageQueueClear();
	t.testMessageQueueEmpty();
	t.testMessageQueuePush();
	t.testMessageQueuePop();
	t.testThreadBall();
	t.testCycleBall();
	t.testCycleCntBall();
	t.testThreadCntBall();
	t.testUpdatePlayerListBall();
	t.testOutFileNameLogger();
	t.testInFileNameLogger();
	t.testSetDateTimeLogger();
	t.testoutLogger();
	t.testInLogger();
	t.testIDPingPong();
	t.testDestroyPingPong();

	std::cout << "success" << std::endl;

	return 0;
}

