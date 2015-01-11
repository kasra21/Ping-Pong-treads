#ifndef TEST_H_
#define TEST_H_

#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <string>
#include "../Logger.h"
#include "../ball.h"
#include "../MessageQueue.h"
#include "../PingPong.h"
#include "../App.h"
#include <assert.h>

    class test{
    public:
        void testThreadApp();
        void testCycleApp();
        void testPrivateApp();
        void testMessageQueueClear();
        void testMessageQueueEmpty();
        void testMessageQueuePush();
        void testMessageQueuePop();
        void testThreadBall();
        void testCycleBall();
        void testCycleCntBall();
        void testThreadCntBall();
        void testUpdatePlayerListBall();
        void testOutFileNameLogger();
        void testInFileNameLogger();
        void testSetDateTimeLogger();
        void testoutLogger();
        void testInLogger();
        void testIDPingPong();
        void testDestroyPingPong();

    };


#endif