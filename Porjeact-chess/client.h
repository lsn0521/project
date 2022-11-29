#pragma once

#include <iostream>
#include <string>
#include<cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

class client {
public:
	client();//创建套接字写入服务器端信息
	~client();//关闭套接字
	int  client_connect();//向服务器端请求连接
	void client_send(char* a);//发送数据
	char* client_recv(char* a);//接收数据 
	void client_link();
	void client_first();
	void client_after();
	int color;//判断我方棋子颜色0为未分色，1为红色，2为黑色
	//int order;//判断先后手0为未判断,1为先手,2为后手
	int Limit_touch;//初始0可触摸，1不可触摸
private:
	int sockfd;//客户端的套接字
	struct sockaddr_in addr;//服务器端地址信息

};