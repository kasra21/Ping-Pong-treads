#include "App.h"

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


int App::init(){
	log1->setInfileName("InLog.txt");
	log1->setOutFileName("OutLog.txt");	//logger init
	MQ->clearQueue();					//init message Queue

	if(log1->getInfileName() == "InLog.txt" && log1->getOutFileName() == "OutLog.txt"
	&& MQ->isEmpty() )
		return 1;
	else
		return -1;
}

int App::BallInit(){
	ball1->setThreadNumber(threadNum);		//ball init
	ball1->setthreadCnt(0);
	ball1->setCycle(tossCycles);
	ball1->setcycleCnt(tossCycles);

	if(ball1->getThreadNumber() == threadNum && ball1->getthreadCnt() == 0 &&
	ball1->getCycle() == tossCycles && ball1->getcycleCnt() == tossCycles )
		return 1;
	else 
		return -1;

}

int App::FirstKick(PingPong &FirstPlayer){

	std::unique_lock<std::mutex> lk(ball1->BallMutex);
	//ball1->BallAlarm.wait(lk);

	std::set<int>::const_iterator it(ball1->PlayerBallList.begin());
	if(ball1->PlayerBallList.size() > 0)								//the unit test helped me to fix this
		std::advance (it,rand() % ball1->PlayerBallList.size());

	ball1->idHelper  = *it;

	MQ->push(ball1);
	FirstPlayer.setId(ball1->idHelper);
	ball1->PlayerBallList.erase(FirstPlayer.getId());							//push

	PingPong::displayThreadInfo(& FirstPlayer);

	ball1->setthreadCnt(ball1->getthreadCnt() + 1);		

	ball1->BallAlarm.notify_all();

	if(ball1->idHelper >= 0 && ball1->idHelper <= ball1->PlayerBallList.size() -1 && 
		!MQ->isEmpty() )
		return 1;
	else
		return -1;


}

App::App(){
	threadNum = 0;
	tossCycles = 0;

}

//should be it
void App::run(){

	init();

	log1->in(threadNum, tossCycles);

	BallInit();
	if(!MQ->endofPro){
		srand (time(NULL));

		ball1->updatePlaylist();

		PingPong FirstPlayer;			//creates first player

		FirstKick(FirstPlayer);				
										
		players = new PingPong[ball1->getThreadNumber() - 1];

		while(ball1->getcycleCnt() != 0){} 	
	
		for(int i = 0; i < ball1->getThreadNumber() - 1; i++){
			players[i].destroy();				//distroy all created threads
		}
		FirstPlayer.destroy();
	}
	
}


int App::getthreadNum(){
	return threadNum;
}

int App::gettossCycles(){
	return tossCycles;
}

void App::setthreadNum(int t){
	threadNum = t;
}

void App::settossCycles(int t){
	tossCycles = t;
}

//test for private methods of App
bool App::Utest(){
	PingPong FirstPlayer;
	if( init() == 1 && BallInit() == 1 && FirstKick( FirstPlayer) == 1 ){
		FirstPlayer.destroy();
		return true;
	}
	else
		return false;

}