//a singleton, which is injected into the PingPong object
// outputting data, inputting data, and file streaming
// It has the option of printing the date/time of output
#ifndef LOGGER_H_
#define LOGGER_H_

#include <time.h>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <fstream>
#include <stdio.h>
#include "MessageQueue.h"

	class Logger{
	private:
		void printDateTimeFile(std::ofstream & outFile);

		std::ofstream Outfile;
		std::ifstream Infile;
		std::string OutfileName;
		std::string InfileName;
		bool DT;


	public:
		std::mutex logMutex;
		static Logger & getInstance();

		int in(int & input1, int & input2);

		int out(std::string s);
	
		void setDateTime(bool DateTime);
		bool getDateTime();

		void setOutFileName(char * FileName);
		std::string getOutFileName();

		void setInfileName(char * FileName);
		std::string getInfileName();

	};


#endif