#include "server.h"
#include <unistd.h>

GameServer::GameServer(EventLoop* loop, const InetAddress& listenAddr) : server_(loop, listenAddr, "GameServer"),running_(true) {
    server_.setConnectionCallback(std::bind(&GameServer::onConnection, this, std::placeholders::_1));

    server_.setMessageCallback(std::bind(&GameServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置线程数
    server_.setThreadNum(4);
    for (int i = 0; i < 4; i++)
    {
        workerThreads_.emplace_back(&GameServer::workerThread, this);
    }
    
}

// 析构函数
GameServer::~GameServer() {
    running_ = false;
    for (auto & thread : workerThreads_) {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}

void GameServer::start() {
    server_.start();
}

void GameServer::onConnection(const TcpConnectionPtr& conn){
    LOG_ERROR << "[onConnection]Thread ID: " << gettid();
    if (conn->connected())
    {
        LOG_INFO << "Client connected: " << conn->peerAddress().toIpPort();
    } else {
        LOG_INFO << "Client disconnected: " << conn->peerAddress().toIpPort();
    }
    
}

void GameServer::onMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp receiveTime) {
    LOG_ERROR << "[onMessage]Thread ID: " << gettid();
    std::string msg = buffer->retrieveAllAsString();
    LOG_INFO << "Received message: " << msg;

    // 将任务加入队列，延迟处理
    taskQueue_.push([conn, msg](){conn->send("Processed: " + msg);}); 
}

// 线程工作
void GameServer::workerThread() {
    while (running_)
    {
        TaskQueue::Task task = taskQueue_.pop();
        task();
    }
}