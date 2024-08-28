// #include<muduo/net/TcpServer.h>
// #include<muduo/net/EventLoop.h>
// #include<muduo/net/InetAddress.h>
// #include<muduo/net/Buffer.h>
// #include<iostream>
// #include<functional>
// using namespace std;
// using namespace muduo;
// using namespace muduo::net;
// using namespace placeholders;

// class ChatServer {
// public:
//     // 初始化TcpServer (事件循环， ip+port， 服务器的名字)
//     ChatServer(EventLoop *loop, const InetAddress &listenAddr, const string &nameArg)
//     :_listenAddr(listenAddr), _server(loop, listenAddr, nameArg), _loop(loop) {
//         // 通过绑定器设置回调函数(使用绑定器绑定回调函数，为了可以访问成员内属性)
//         _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, std::placeholders::_1));

//         _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));

//         // 设置eventloop 线程数量
//         _server.setThreadNum(4);
//     }

//     // 启动 chatServer 服务
//     void start() {
//         _server.start();
//     }
// private:
//     // tcpserver绑定的回调函数，当有新连接或连接中断时调用
//     void onConnection(const TcpConnectionPtr &con) {
//         InetAddress peer = con->p
//         if (con->connected()) {
//             cout << con->peerAddress().toIpPort() << "->" << con->localAddress().toIpPort <<
//                 "state:online" << endl;
//         } else {
//             cout << con->peerAddress().toIpPort() << "->" << con->localAddress().toIpPort <<
//                 "state:offline" << endl;
//             con->shutdown(); // close(fd);
//             _loop->quit();
//         }
//     }

//     // tcpserver 绑定的回调函数, 当有新数据时调用
//     void onMessage(const TcpConnectionPtr &con, Buffer *buf, muduo::Timestamp time) {
//         string buffer = buf->retrieveAllAsString();
//         cout << "recv data:" << buf << "time:" << time.toString() << endl;
//     }

//     TcpServer _server;
//     EventLoop *_loop;
//     InetAddress _listenAddr;
// };

// int main() {
//     EventLoop loop;
//     InetAddress addr("127,0,0,1", 6000);
//     ChatServer server(&loop, addr, "ChatServer");
//     server.start();
//     loop.loop();  // epoll_wait 以阻塞方式等待新用户连接，已连接用户的读写事件等
//     return 0;
// }

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <iostream>

using namespace muduo;
using namespace muduo::net;

class MyServer {
public:
    MyServer(EventLoop* loop, const InetAddress& listenAddr)
        : server_(loop, listenAddr, "MyServer") {
        // 绑定当前实例的 handleConnection 方法作为连接回调
        server_.setConnectionCallback(std::bind(&MyServer::handleConnection, this, std::placeholders::_1));
    }

    void start() {
        server_.start();
    }

private:
    void handleConnection(const TcpConnectionPtr& conn) {
        if (conn->connected()) {
            std::cout << "新连接来自 " << conn->peerAddress().toIpPort() << std::endl;
        } else {
            std::cout << "连接已断开" << std::endl;
        }
    }

    TcpServer server_;
};

int main() {
    EventLoop loop;
    InetAddress listenAddr("127,0,0,1",6000);
    MyServer server(&loop, listenAddr);
    server.start();
    loop.loop();
    return 0;
}
