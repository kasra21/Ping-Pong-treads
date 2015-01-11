#include "MessageQueue.h"

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

MessageQueue & MessageQueue::getInstance(){

	static MessageQueue instance;
	return instance;
}

int MessageQueue::clearQueue(){
	while(!messageList.empty()){
		messageList.pop();
	}
	if(messageList.empty())
		return 1;
	else
		return -1;
}

int MessageQueue::push(ball * what){

	messageList.push(what);

	if(!messageList.empty())
		return 1;
	else
		return -1;

}

//passes the ball blocks utill recieve
int MessageQueue::pop(){

	while(messageList.empty()){
		//busy wait;
		return -1;
	}

	messageList.pop();
	return 1;
}

bool MessageQueue::isEmpty(){

	if(messageList.empty())
		return true;
	else
		return false;

}

