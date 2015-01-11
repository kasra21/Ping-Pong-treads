#include "PingPong.h"

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
using std::string;
using std::ifstream;
using std::ofstream;

void PingPong::createThreadFunction(PingPong * obj){
	
	ball * ball1 = &ball::getInstance();
	MessageQueue * MQ = &MessageQueue::getInstance();

	while(1){

		std::unique_lock<std::mutex> lk(ball1->BallMutex);

		//while()			//busy
		if(ball1->getcycleCnt() == 0){ break;}

		/*else if(ball1->getcycleCnt() == ball1->getCycle() && ball1->getthreadCnt() == 0){
			
			MQ->pop();													//pop	

			obj->id = ball1->idHelper;
			ball1->PlayerBallList.erase(obj->id);
			MQ->push(ball1);							//push

			displayThreadInfo(obj);

			ball1->setthreadCnt(ball1->getthreadCnt() + 1);

			ball1->BallAlarm.wait(lk);
			
		}*/

		else if(ball1->getcycleCnt() == ball1->getCycle()){		//setup first cycle

			MQ->pop();											//pop

			std::set<int>::const_iterator it(ball1->PlayerBallList.begin());
			std::advance (it,rand() % ball1->PlayerBallList.size());

			ball1->idHelper  = * it;
			obj->id = ball1->idHelper;

			ball1->PlayerBallList.erase(obj->id);

			MQ->push(ball1);		//push

			displayThreadInfo(obj);

			ball1->setthreadCnt(ball1->getthreadCnt() + 1);

			if(ball1->PlayerBallList.empty()){		//once done with all threads, reinit
				ball1->updatePlaylist();
				ball1->setthreadCnt(0);
				ball1->setcycleCnt(ball1->getcycleCnt() - 1);		//cycle --

				ball1->BallAlarm.notify_all();
			
			}
			else{
				ball1->BallAlarm.wait(lk);
			}
		}
		else{				//passed the first cycle
			MQ->pop();								//pop
						
			ball1->PlayerBallList.erase(obj->id);
			MQ->push(ball1);		//push
			displayThreadInfo(obj);
			ball1->setthreadCnt(ball1->getthreadCnt() + 1);

			if(ball1->PlayerBallList.size() == 1){		//once done withh all threads, reinit
				ball1->updatePlaylist();
				ball1->setthreadCnt(0);
				ball1->setcycleCnt(ball1->getcycleCnt() - 1);		//cycle --

				ball1->BallAlarm.notify_all();
			
			}
			else{
				ball1->BallAlarm.wait(lk);
				}
			}
	}
	
}

PingPong::PingPong(){

	player = thread(createThreadFunction, this);

}

int PingPong::destroy(){	
	if(player.joinable()){			
		player.join();
		return 1;
	}
	else
		return -1;
}

int PingPong::getId(){
	return id;
}	
void PingPong::setId(int index){
	id = index;
}

void PingPong::displayThreadInfo(PingPong * obj){

	ball * ball1 = &ball::getInstance();
	Logger * log1 = &Logger::getInstance();

	if(ball1->getthreadCnt() == 0)
		log1->out("\n--------------------------------- \n beginning of cycle \n---------------------------------\n");

	if(ball1->getthreadCnt() != 0)
		log1->out("received \n");

	log1->out("player ");
	log1->out(std::to_string(obj->id));
	log1->out(" has the ball at cycle: ");
	log1->out(std::to_string( ball1->getCycle() - ball1->getcycleCnt()));
	log1->out("\n");

	if(ball1->getthreadCnt() != ball1->getThreadNumber() - 1)
		log1->out("sent \n");

	if(ball1->getcycleCnt() == 1 && ball1->getthreadCnt() == ball1->getThreadNumber() - 1){
		log1->setDateTime(true);	//diplay log time for the very last print statement
	}

	if(ball1->getthreadCnt() == ball1->getThreadNumber() - 1)
		log1->out("\n--------------------------------- \n end of cycle \n---------------------------------\n");	

}