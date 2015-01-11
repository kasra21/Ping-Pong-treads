//atomic data structure that contains information about the “ping ping ball.”

#ifndef BALL_H_
#define BALL_H_

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <string>
#include <set>

	class ball{
	private:
		int cycle;
		int ThredTotal;
		int cycleCnt;
		int threadCnt;

	public:
		std::mutex BallMutex;
		std::condition_variable BallAlarm;
		std::set <int> PlayerBallList;				//list of players who already got the ball
		static ball & getInstance();				//unique ball

		int getCycle();
		void setCycle(int c);
		int getThreadNumber();
		void setThreadNumber(int n);

		int getcycleCnt();
		void setcycleCnt(int c);
		int getthreadCnt();
		void setthreadCnt(int n);

		int updatePlaylist();

		int idHelper;

	};

#endif