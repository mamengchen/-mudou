#pragma once

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include "task_queue.h"
#include <vector>
#include <thread>

using namespace muduo;
using namespace muduo::net;

class GameServer {
public:
    GameServer(EventLoop* loop, const InetAddress& listenAddr);
    ~GameServer();
    void start();

private:
    void onConnection(const TcpConnectionPtr& conn);
    void onMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp receiveTime);

    void workerThread();

    TaskQueue taskQueue_;   // 任务队列
    std::vector<std::thread> workerThreads_;  // 工作线程vector
    TcpServer server_;
    bool running_;
};