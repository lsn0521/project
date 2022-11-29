#include "server.h"
//服务器端
server::server() //创建tcp套接字,写入服务器信息
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //创建TCP套接字sockfd
	int on = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)); //服务器关闭重启后直接再次使用该端口
	//清空保存服务器的信息结构体，写入信息
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;				  //通信协议
	addr.sin_addr.s_addr = htonl(INADDR_ANY); //服务器的地址
	addr.sin_port = htons(1111);			  //服务器端口号
}
server::~server() //关闭文件描述符
{
	close(sockfd); //关闭文件描述符
	close(epfd);   //关闭文件描述符
}
int server::server_bind() //绑定地址信息
{
	int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)); //绑定
	if (ret < 0)
	{
		perror("bind");
		return -1;
	}
	return 0;
}
int server::server_listen() //监听
{
	int ret = listen(sockfd, 4); //服务器进入监听状态，请求连接队列一次性允许4个客户端排队连接
	if (ret < 0)
	{
		perror("listen");
		return -1;
	}
	return 0;
}
int server::server_epoll() //创建epoll句柄，写入事件属性，告知事件类型并监听服务器活动
{
	epfd = epoll_create(1); //创建一个epoll实例返回一个文件描述符
	if (epfd < 0)
	{
		perror("epoll create");
		return -1;
	}
	evt.events = EPOLLIN; //表示对应的文件描述符可以读
	evt.data.fd = sockfd; //监听标准输入
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &evt);
	//为 epoll 注册事件告知事件类型.
	if (ret < 0)
	{
		perror("add error");
		return -1;
	}
	return 0;
}
int server::server_accept() //接受客户端连接
{
	struct sockaddr_in caddr;									//保存地址信息的结构体
	socklen_t len = sizeof(caddr);								//该结构体长度
	clientfd = accept(sockfd, (struct sockaddr *)&caddr, &len); //接受连接返回表示连接的描述符
	if (clientfd < 0)
	{
		perror("accept");
		return -1;
	}
	return clientfd;
}

CList::CList(int clientfd, int a = 0, int b = 0) : clientfd(clientfd), color(a), order(b) //创建节点
{
	this->next = this->prev = this;
}
CList::CList() //创建节点
{
	this->next = this->prev = this;
}
CList::~CList()
{
}
void CList::append(const int &clientfd) //添加数据
{
	CList *clist = new CList(clientfd);
	clist->next = this->next;
	clist->prev = this;
	this->next->prev = clist;
	this->next = clist;
}
void CList::remove(const int &clientfd) //删除相关链
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == clientfd)
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			delete p;
		}
		p = p->next;
	}
}
void CList::show() //显示数据
{
	CList *p = this->next;
	while (p != this)
	{
		cout << p->clientfd << endl;
		cout << p->color << endl;
		cout << p->order << endl;
		cout << "/////////////" << endl;
		p = p->next;
	}
}
void CList::showsend(int a, char *buffer, int size) //发送数据
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd != a)
		{
			send(p->clientfd, buffer, size, 0);
		}
		p = p->next;
	}
}
void CList::revise_color(const int &clientfd, int data) //修改颜色
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == clientfd)
		{
			p->color = data;
		}
		p = p->next;
	}
}
void CList::revise_order(const int &clientfd, int data) //修改先后顺序
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == clientfd)
		{
			p->order = data;
		}
		p = p->next;
	}
}
int CList::Judge_fdnum() //判断连接数
{
	CList *p = this->next;
	i = 0;
	while (p != this)
	{
		i++;
		p = p->next;
	}
	return i;
}
int CList::Judge_allocation() //判断是否分配先后和颜色
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->color == 0 || p->order == 0) //当有颜色或顺序参数等于0时,表示未分配
		{
			return -1;
		}
		p = p->next;
	}
	return 0;
}
void CList::allocation() //分配颜色和先后
{
	CList *p = this->next;
	srand((int)time(0)); // 产生随机种子
	int i = rand() % 100;
	int j = rand() % 100;
	if (i % 2 != 0)
	{
		revise_color(p->clientfd, 1);		// 1红
		revise_color(p->next->clientfd, 2); // 2黑
	}
	else
	{
		revise_color(p->clientfd, 2);		// 2黑
		revise_color(p->next->clientfd, 1); // 1红
	}
	if (j % 2 != 0)
	{
		revise_order(p->clientfd, 1);		// 1先
		revise_order(p->next->clientfd, 2); // 2后
	}
	else
	{
		revise_order(p->clientfd, 2);		// 2后
		revise_order(p->next->clientfd, 1); // 1先
	}
}
void CList::send_allocation() //发送分配
{
	//先分配颜色
	CList *p = this->next;
	while (p != this)
	{
		char a[10] = "read";  //红
		char b[10] = "black"; //黑
		// char c[10]="first";//先
		// char d[10]="after";//后
		if (p->color == 1)
		{
			send(p->clientfd, a, strlen(a), 0);
		}
		else
		{
			send(p->clientfd, b, strlen(b), 0);
		}
		/*  if(p->order == 1)
		  {
			  send(p->clientfd,c,strlen(c),0);
		  }
		  else
		  {
			  send(p->clientfd,d,strlen(d),0);
		  }*/
		p = p->next;
	}
}
void CList::color_clear()
{
	CList *p = this->next;
	while (p != this)
	{
		revise_color(p->clientfd, 0);
		p = p->next;
	}
}
int main()
{
	server run_server;
	run_server.server_bind();
	run_server.server_listen();
	run_server.server_epoll();
	CList clist;
	while (1)
	{
		int num = epoll_wait(run_server.epfd, run_server.events, 10, -1);
		if (num < 0)
		{
			perror("epoll wait");
			continue;
		}
		for (int i = 0; i < num; i++)
		{
			if (run_server.events[i].events == EPOLLIN && run_server.events[i].data.fd == run_server.sockfd)
			{
				run_server.server_accept();
				if (run_server.clientfd == -1)
				{
					continue;
				}
				clist.append(run_server.clientfd); //向clist链表中添加元素
				// struct epoll_event evt;//epoll 注册的事件
				run_server.evt.events = EPOLLIN;			  //表示对应的文件描述符可以读
				run_server.evt.data.fd = run_server.clientfd; //监听标准输入
				int ret = epoll_ctl(run_server.epfd, EPOLL_CTL_ADD, run_server.clientfd, &run_server.evt);
				//为 epoll 注册事件告知事件类型，在文件描述符epfd所引用的epoll实例上注册目标文件描述符fd，并将事件事件与内部文件链接到fd
				if (ret < 0)
				{
					perror("add error");
					continue;
				}
			}
			else if (run_server.events[i].events == EPOLLIN) //如果该事件可读
			{
				char buffer[128] = {0}; //接收的数据
				int size = recv(run_server.events[i].data.fd, buffer, 128, 0);
				//读取数据
				if (size <= 0) //出错或连接关闭
				{
					int ret = epoll_ctl(run_server.epfd, EPOLL_CTL_DEL, run_server.events[i].data.fd, &run_server.events[i]);
					//从epfd引用的epoll实例中删除（注销）目标文件描述符fd
					if (ret < 0)
					{
						perror("del error");
					}
					clist.color_clear();
					close(run_server.events[i].data.fd);		//若没有关闭成功则主动关闭关闭该描述符
					clist.remove(run_server.events[i].data.fd); //从链表中删除与该元素相关数据
					continue;									//返回while处阻塞,等待活跃
				}
				if (strcmp(buffer, "exit") == 0)
				{
					clist.color_clear();
					continue;
				}
				int ret = clist.Judge_fdnum();
				if (ret < 2) //连接小于2时不满足分配条件                {
				{
					continue; //返回while处阻塞,等待活跃
				}
				ret = clist.Judge_allocation();
				if (ret < 0) //小于0时未分配颜色和先后
				{
					clist.allocation();		 //随机分配
					clist.send_allocation(); //发送分配
					continue;				 //返回while处阻塞,等待活跃
				}
				cout << "服务器发送前" << endl;
				clist.showsend(run_server.events[i].data.fd, buffer, size);
			}
		}
	}
}

/* int CList:: judgment_ip(int data)//判断ip如果ip不为0说明有获取到ip
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == data)
		{
			if(p->linkip == 0)
			{
				return -1;
			}
		}
		p = p->next;
	}
	return 0;
}

int CList:: judgment_color(int data)//判断color如果color不为0说明有分配到color
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == data)
		{
			if(p->color == 0)
			{
				return -1;
			}
		}
		p = p->next;
	}
	return 0;
}

int CList:: judgment_order(int data)//判断order如果order不为0说明有分配到order
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == data)
		{
			if(p->order == 0)
			{
				return -1;
			}
		}
		p = p->next;
	}
	return 0;
}

int CList:: judgment_order(int data)//判断是否匹配
{
	CList *p = this->next;
	while (p != this)
	{
		if (p->clientfd == data)
		{
			if(p->linkip != getaddress(p->linkfd))
			{
				return -1;
			}
		}
		p = p->next;
	}
	return 0;
}

int CList:: getaddress(int data)//获取对应客户端ip信息
{
	socklen_t addrlen = sizeof(caddr);//获取结构体大小
	int ret=getpeername(data,(struct sockaddr*)&caddr,&addrlen);//获取客户端信息
	if(ret != 0)
	{
		perror("getsockname");
		return -1;
	}
	return caddr.sin_addr.s_addr
}

/* {
	int ret = judgment_ip(run_server.events[i].data.fd)
	if(ret !=0)
	{
		char buffer[1024]={0};//存储数据的数组
		sprintf(buffer,"%d",getaddress(run_server.events[i].data.fd));//转换ip的数据格式为字符串型
		int size = strlen(buffer);//该数据长度
		showend(run_server.events[i].data.fd,buffer,size);//向除了自己以外的所有已连接服务器的客户端发送自己的ip
	}

} */

/*
 int CList:: judgment_order(int data)//判断order如果order不为0说明有分配到order
	{
		CList *p = this->next;
		i=0;
		while (p != this)
		{
			if (p->clientfd == data)
			{
				if(p->order == 0)
				{
					return -1;
				}
			}
			p = p->next;
		}
		return 0;
	}



{
	if(buffer == "LINK")//如果数据等于表示进行匹配
	{

	}

} */