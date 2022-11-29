/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-27 10:55:00
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-29 21:21:13
 * @FilePath: \undefinedd:\gx\c++\3.象棋项目\server\server.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include<iostream>
#include<cstdio>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/epoll.h>
#include <stdbool.h>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <time.h>

using namespace std;  

class server{
public:
    server();
    ~server();
    int server_bind();
    int server_listen();
    int server_epoll();
    int server_accept();
    int clientfd;//表示与客户端连接的套接字
    int sockfd;//TCP套接字sockfd
    struct sockaddr_in addr;//保存通信地址的结构体
    int epfd;//事件的句柄文件描述符
    struct epoll_event evt;//epoll 注册的事件
    struct epoll_event events[10];//10个事件元素，用于回传要处理的事件
//private:
};

class CList {
public:
    CList(int clientfdint,int a,int b);
	CList();
	~CList();
	void append(const int &clientfd);
	void remove(const int &clientfd);
    void revise_color(const int &clientfd, int data);
    void revise_order(const int &clientfd, int data);
    void show();
    void showsend(int a,char* buffer,int size);
    int  Judge_fdnum();
    int  Judge_allocation();
    void allocation();
    void send_allocation();
    void color_clear();
    int i;//表示除头节点外的链接数
    int clientfd;//表示连接状态的套接字
    int color;//颜色判断
    int order;//顺序判断
    //上方数据0为初始,表示未匹配未分配
	CList* next;
	CList* prev;
};