//initializes and deinits the ping pong application, and is disjoint for your main

#ifndef APP_H_
#define APP_H_

#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <string>
#include "Logger.h"
#include "ball.h"
#include "MessageQueue.h"
#include "PingPong.h"

	class App{
	private:
		int threadNum;
		int tossCycles;
		PingPong * players;
		bool loggerUse;
		ball * ball1 = &ball::getInstance();
		MessageQueue * MQ = &MessageQueue::getInstance();
		Logger * log1 = &Logger::getInstance();

		int init();
		int BallInit();
		int FirstKick(PingPong & FirstPlayer);

	public:
		App();
		void run();

		int getthreadNum();
		int gettossCycles();
		void setthreadNum(int t);
		void settossCycles(int t);

		bool Utest();
	};


#endif
