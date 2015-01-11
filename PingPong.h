//will create a thread and dependency inject any singleton objects into it.

#ifndef PINGPONG_H_
#define PINGPONG_H_

#include <time.h>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <pthread.h>
#include <algorithm>
#include "Logger.h"
#include "ball.h"
#include "MessageQueue.h"

	class PingPong{
	private:
		int id;
		std::thread player;
		Logger * logger;
		static void createThreadFunction(PingPong * obj);
	public:
		PingPong();
		static void displayThreadInfo(PingPong * obj);

		int destroy();
		
		int getId();	
		void setId(int index);
	};


#endif
