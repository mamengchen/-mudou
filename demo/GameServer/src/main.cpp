
#include "server.h"

int main() {
    EventLoop loop;
    InetAddress listenAddr(8080);
    GameServer server(&loop, listenAddr);

    server.start();
    loop.loop();
    return 0;
}