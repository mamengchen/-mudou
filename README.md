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



