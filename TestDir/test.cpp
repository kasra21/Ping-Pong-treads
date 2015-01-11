#include "test.h"

using std::cout;
using std::cin;
using std::endl;
using std::condition_variable;
using std::lock_guard;
using std::unique_lock;
using std::mutex;
using std::queue;
using std::thread;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;
using std::string;
using std::ifstream;
using std::ofstream;

void test::testThreadApp(){

	App app;
	app.setthreadNum(1);
	assert(app.getthreadNum() == 1);
	cout << "get/set threads App -> test Done \n";
}


void test::testCycleApp(){
	App app;
	app.settossCycles(1);
	assert(app.gettossCycles() == 1);
	cout << "get/set cycles App -> test Done \n";

}

void test::testPrivateApp(){
	App app;
	assert( app.Utest() == true);
	cout << "privates App -> test Done \n";

}

void test::testMessageQueueClear(){

	MessageQueue MQ;
	ball ball1;

	for(int i =0; i< 10; i++)
		MQ.push(&ball1);

	assert(MQ.clearQueue() == 1);
	cout << "Clear MessageQueue -> test Done \n";

}

void test::testMessageQueueEmpty(){

	MessageQueue MQ;
	void(MQ.isEmpty());
	cout << "Empty MessageQueue -> test Done \n";
}

void test::testMessageQueuePush(){
	MessageQueue MQ;
	ball ball1;
	assert(MQ.push(&ball1) == 1);
	cout << "Push MessageQueue -> test Done \n";
}

void test::testMessageQueuePop(){
	MessageQueue MQ;
	ball ball1;

	MQ.push(&ball1);
	assert(MQ.pop() == 1);
	cout << "Pop MessageQueue -> test Done \n";
}

void test::testThreadBall(){

	ball ball1;
	ball1.setThreadNumber(1);
	assert(ball1.getThreadNumber() == 1);
	cout << "get/set threads Ball -> test Done \n";
}

void test::testCycleBall(){

	ball ball1;
	ball1.setCycle(1);
	assert(ball1.getCycle() == 1);
	cout << "get/set cycles Ball -> test Done \n";
}

void test::testCycleCntBall(){

	ball ball1;
	ball1.setcycleCnt(1);
	if(ball1.getcycleCnt() == 1);
	cout << "get/set cyclesCnt Ball -> test Done \n";
}

void test::testThreadCntBall(){

	ball ball1;
	ball1.setthreadCnt(1);
	assert(ball1.getthreadCnt() == 1);
	cout << "get/set threads Cnt Ball -> test Done \n";
}

void test::testUpdatePlayerListBall(){

	ball ball1;
	assert(ball1.updatePlaylist() == 1);
	cout << "Update Player list Ball -> test Done \n";
}

void test::testOutFileNameLogger(){

	Logger log1;
	log1.setOutFileName("tenBucks.txt");
	assert(log1.getOutFileName() == "tenBucks.txt");
	cout << "Output file setting Logger -> test Done \n";
}

void test::testInFileNameLogger(){

	Logger log1;
	log1.setInfileName("tenBucks.txt");
	assert(log1.getInfileName() == "tenBucks.txt");
	cout << "Input file setting Logger -> test Done \n";
}

void test::testSetDateTimeLogger(){

	Logger log1;
	log1.setDateTime(true);
	assert(log1.getDateTime() == true);
	cout << "Log Time Logger -> test Done \n";

}

void test::testoutLogger(){

	Logger log1;
	log1.setOutFileName("tenBucks.txt");		//need to set the filename set up first
	assert(log1.out("$10") == 1);
	cout << "Output file Logger -> test Done \n";

}

void test::testInLogger(){

	int input1, input2;
	Logger log1;
	log1.setInfileName("InLog.txt");
	assert(log1.in(input1, input2) == 1);
	cout << "Input file Logger -> test Done \n";

}

void test::testIDPingPong(){

	PingPong player;
	player.setId(1);
	assert(player.getId() == 1);
	player.destroy();
	cout << "set/get id PingPong-> test Done \n";
}

void test::testDestroyPingPong(){

	PingPong player;
	assert(player.destroy() == 1);
	cout << "destroy thread PingPong-> test Done \n";

}






