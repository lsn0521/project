#include "client.h"

client::client()
{
	color = 0;
	//order = 0;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);//创建套接字
	//写入要连接的服务器端信息
	addr.sin_family = AF_INET;//通信协议
	addr.sin_port = htons(1111);//服务器端端口
	addr.sin_addr.s_addr = inet_addr("192.168.5.30");//服务器端地址
}

client::~client()
{
	cout << "关闭" << endl;
	close(sockfd);//关闭套接字
}

int client::client_connect()
{
	int ret = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));//请求连接，如果ret小于0则请求失败
	if (ret < 0)
	{
		perror("connect");
		return ret;
	}
	return ret;
}

char* client::client_recv(char* a)
{
	cout << sizeof(a) << endl;
	int size = recv(sockfd, a, 1024, 0);//接收数据
	cout << size << endl;//接收到的数据长度
	cout << "接收到数据：" << a << endl;
	Limit_touch = 0;
	return a;
}
//char* client::client_recv(char* a, int b)
//{
//	cout << sizeof(a) << endl;
//	int size = recv(sockfd, a, b, 0);//接收数据
//	cout << size << endl;//接收到的数据长度
//	cout << "接收到数据：" << a << endl;
//	Limit_touch = 0;
//	return a;
//}
void client::client_send(char* a)
{
	send(sockfd, a, strlen(a), 0);//发送数据
	cout << "发送数据: " << a << endl;
	Limit_touch = 1;
}

void client::client_link()//进行连接数据分配
{
	char a[1024] = { "link" };
	client_send(a);
	memset(a, 0, 1024);
	client_recv(a);
	cout << "确定一下a" << a << endl;
	if (strcmp(a, "read") == 0)
	{
		color = 1;
		cout << "我方棋子颜色为:" << a << endl;
	}
	else
	{
		color = 2;
		cout << "我方棋子颜色为:" << a << endl;
	}
	//memset(a,0,1024);
	////client_recv(a);
	//cout<<"确定一下a"<<a<<endl;
	//if(strcmp(a,"first") == 0)
	//{
	//    order = 1;
	//    cout<<"我方先走棋:"<<a<<endl;
	//}
	//else
	//{
	//    order = 2;
	//    cout<<"我方后走棋:"<<a<<endl;
	//}
}

void client::client_first()//先手
{
	char b[1024] = { 0 };
	cout << "请输入数据  " << endl;
	cin >> b;
	client_send(b);
	cout << "限制触摸标记：" << Limit_touch << endl;
	char a[1024] = { 0 };
	client_recv(a);
	cout << "确认数据接收是否正确：" << a << endl;
	cout << "限制触摸标记：" << Limit_touch << endl;
}

void client::client_after()//后手
{
	char a[1024] = { 0 };
	client_recv(a);
	cout << "确认数据接收是否正确：" << a << endl;
	cout << "限制触摸标记：" << Limit_touch << endl;
	char b[1024] = { 0 };
	cout << "请输入数据  " << endl;
	cin >> b;
	client_send(b);
	cout << "限制触摸标记：" << Limit_touch << endl;
}

//int main()
//{
//    client A;
//    A.client_connect();
//    while(1)
//    {
//        A.client_link();
//        if(A.order == 1)
//        {
//            cout<<"颜色"<<A.color<<endl;
//            cout<<"先后"<<A.order<<endl;
//            cout<<"正式开局:先手"<<endl;
//            A.Limit_touch = 0;
//            while(1)
//            {
//                A.client_first();
//            }
//        }
//        else if(A.order == 2)
//        {
//            cout<<"颜色"<<A.color<<endl;
//            cout<<"先后"<<A.order<<endl;
//            cout<<"正式开局:后手"<<endl;
//            A.Limit_touch = 1;
//            while(1)
//            {
//                A.client_after();
//            }
//        }
//    }
//}