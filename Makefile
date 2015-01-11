all: clean build run

test:
	rm -rf *o main
	rm -rf binTest
	mkdir binTest
	clang++ -c ball.cpp -pthread -std=c++11 -o binTest/ball.o
	clang++ -c Logger.cpp -pthread -std=c++11 -o binTest/Logger.o
	clang++ -c MessageQueue.cpp -pthread -std=c++11 -o binTest/MessageQueue.o
	clang++ -c PingPong.cpp -pthread -std=c++11 -o binTest/PingPong.o
	clang++ -c App.cpp -pthread -std=c++11 -o binTest/App.o
	clang++ -c TestDir/test.cpp -pthread -std=c++11 -o binTest/test.o
	clang++ TestDir/pingTest.cpp binTest/ball.o binTest/Logger.o binTest/MessageQueue.o binTest/PingPong.o binTest/App.o binTest/test.o -pthread -std=c++11 -o binTest/testmain
	binTest/./testmain

build:
	mkdir bin
	clang++ -c ball.cpp -pthread -std=c++11 -o bin/ball.o
	clang++ -c Logger.cpp -pthread -std=c++11 -o bin/Logger.o
	clang++ -c MessageQueue.cpp -pthread -std=c++11 -o bin/MessageQueue.o
	clang++ -c PingPong.cpp -pthread -std=c++11 -o bin/PingPong.o
	clang++ -c App.cpp -pthread -std=c++11 -o bin/App.o
	clang++ ping.cpp bin/ball.o bin/Logger.o bin/MessageQueue.o bin/PingPong.o bin/App.o -pthread -std=c++11 -o bin/main

run:
	bin/./main

clean:
	rm -rf bin