//concurrent queue to send and receive messages between thread

#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <iostream>
#include <queue>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include "ball.h"

	class MessageQueue{
	private:
		std::queue<ball*> messageList;
	public:
		static MessageQueue & getInstance();

		std::mutex MessMutex;
		std::condition_variable alarm;
		bool endofPro;		

		int push(ball * what);
		int pop();
		int clearQueue();
		bool isEmpty();

	};



#endif
