#include "ball.h"

using std::cout;
using std::cin;
using std::endl;
using std::condition_variable;
using std::lock_guard;
using std::unique_lock;
using std::mutex;
using std::thread;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

ball & ball::getInstance(){

	static ball instance;
	return instance;
}

int ball::getCycle(){
	return cycle;
}

void ball::setCycle(int c){
	cycle = c;
}

int ball::getThreadNumber(){
	return ThredTotal;
}

void ball::setThreadNumber(int n){
	ThredTotal = n;
}

int ball::getcycleCnt(){
	return cycleCnt;
}
void ball::setcycleCnt(int c){
	cycleCnt = c;
}
int ball::getthreadCnt(){
	return threadCnt;
}
void ball::setthreadCnt(int n){
	threadCnt = n;
}

int ball::updatePlaylist(){

	for(int i =0; i< ThredTotal; i++){
			PlayerBallList.insert(i);			//update the playerlist
		}

	if(!PlayerBallList.empty() && PlayerBallList.size() == ThredTotal )
		return 1;
	else
		return -1;
}