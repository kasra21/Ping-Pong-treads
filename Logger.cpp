#include "Logger.h"

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

Logger & Logger::getInstance(){

	static Logger instance;
	return instance;

}

void Logger::printDateTimeFile(ofstream & outFile){
	time_t now = time(0);
    struct tm tstruct;
   	char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
   	outFile << buf << endl;
}

int Logger::in(int & input1, int & input2){

	MessageQueue * MQ = &MessageQueue::getInstance();
	std::string reader;
	Infile.open(InfileName);
	if (Infile.is_open()){
		Infile >> reader;
		while(!Infile.eof()){
			if(reader == "threads:")
				Infile >> input1;
			if(input1 < 0){
				MQ->endofPro = true;	//terminate everything
			}
			if(reader == "cycles:")
				Infile >> input2;
			if(input2 < 0){
				MQ->endofPro = true;	//terminate everything
			}

			Infile >> reader;
		}
		if(MQ->endofPro == true){
				cout << "invalid input" << endl;
		}
		Infile.close();
		return 1;
	}
	else{
		return -1;
		cout << "invalid input file" << endl;
	}
}

int Logger::out(string s){
	Outfile.open(OutfileName, std::ios::app);
	if (Outfile.is_open()){

		Outfile << s;

		if(DT == true){
			printDateTimeFile(Outfile);
		}

		Outfile.close();
		return 1;
	}
	else{
		cout << "invalid output file" << endl;
		return -1;
	}

}

void Logger::setDateTime(bool DateTime){
	DT = DateTime;
}

bool Logger::getDateTime(){
	return DT;
}

void Logger::setOutFileName(char * FileName){
	int t = std::remove(FileName);		//remove existing output file to not overwrite them
	OutfileName = FileName;
}

void Logger::setInfileName(char * FileName){
	InfileName = FileName;
}

std::string Logger::getOutFileName(){
	return OutfileName;
}

std::string Logger::getInfileName(){
	return InfileName;
}