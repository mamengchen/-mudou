```
这是基于一个mudou网络库的内容的Perject
mudtest: 使用一些简单的方法
selfmudou: 自己实现的一个简单网络库
Testinstallation: 测试自己安装库是否有用
```
# 前期准备

**首先安装boost库（基于ubuntu）** 

> sudo apt-get update \
> sudo apt-get install libboost-all-dev \
> 安转好之后，默认安装目录在 /usr/include/boost , 如果没有这样的软件包，使用手动下载 Boost \
> wget -O boost_1_55_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.55.0/boost_1_55_0.tar.gz/download \
> tar xzvf boost_1_55_0.tar.gz \
> cd boost_1_55_0/ \
> 获取所需的库，主要的是boost::regex支持的icu：\
> sudo apt-get update \
> sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential libbz2-dev libboost-all-dev \
> Boost的引导程序设置：./bootstrap.sh --prefix=/usr/ \
> sudo ./b2 install
---
**安装Json库（基于ubuntu）** 

1. 安装jsoncpp：
   1. > sudo apt update
   2. > sudo apt install libJsoncpp-dev
2. 安装json-c：
   1. > sudo apt update
   2. > sudo apt install libjson-c-dev 

这样编译出来Json库（其中Jsoncpp是动态库），需要用静态库就需要在下载下来重新编译

---

**安装muduo库**

muduo库的介绍就是：一个基于reactor反应堆模型的多线程C++网络库。(<font color="red">注意：需要提前安装cmake和boost环境</font>)

> git clone https://github.com/chenshuo/muduo 
> cd muduo \
> ./build.sh install \
> 再把其中头文件和静态库文件移动到相应目录下

<font color = "green"> muduo网络库给用户提供两个主要的类：\
TcpServer : 用于编写服务端程序。\
TcpClient : 用于编写客户端程序。
</font>

epoll + 线程池 \
好处：能够把网络 I/O的代码和业务代码区分开（用户的链接和断开，用户的可读写事件）

<em>基于muduo网络库开发服务器程序：
1. 组合TcpServer对象。
2. 创建EvenetLoop事件循环对象的指针。
3. 明确TcpServer构造函数需要什么参数，输出ChatServer的构造函数。
4. 在当前服务器类的构造函数当中，注册处理连接的回调函数和处理读写事件的回调函数。
5. 设置合适的服务端线程数量，muduo库会自己分配I/O线程和worker线程。</em>

   


