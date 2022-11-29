#include <iostream>
#include "XQ.h"
#include <dirent.h>
#include"LcdDevice.h"
#include"Image.h"
#include"Bmp.h"
#include"LcdDevice.h"
#include"Chess.h"
#include<cstdio>
#include <linux/input.h>
#include"client.h"

using namespace std;

//函数声明
void refresh(XQ* lcd);
void bendi(XQ* lcd);
int dir_search(const char* pathname, const char* format);

//定义全局变量
/*
	keykey当用户点击了退出游戏，二次确认点了是还是否的标志变量
	huiqi上一回合是否悔棋了
	huiqi1, huiqi2, huiqi3, saven, huiqi = 0, r, r_1, r_2, r_3, r_4, r_5, r_6, r_7,当点了退出游戏，二次确认又点了否的，保存数据用的
	Qi save1[2][2]，string r_8[3]，保存数据
*/
int key_key = 0, huiqi1, huiqi2, huiqi3, saven, huiqi = 0, r, r_1, r_2, r_3, r_4, r_5, r_6, r_7;
is_qi save1[2][2];
string r_8[3];

//主函数
int main(void)
{
	//定义一个类变量
	XQ* lcd = XQ::createlcd();
	Chess all;

	//缓冲区的切换
	lcd->keshiqu();
	//绘画图片
	lcd->show_bmp("./photo/rj.bmp", 0, 0);

	while (1)
	{
		//等待用户点击
		lcd->paddle_ts();
		if (lcd->num[0] > 30 && lcd->num[0] < 110 && lcd->num[1] > 30 && lcd->num[1] < 110)
		{
			//缓冲区的切换
			lcd->keshiqu();
			//绘画图片
			lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);
			//进度条
			lcd->photo_load();
			//缓冲区的切换
			lcd->keshiqu();
			//绘画图片
			lcd->show_bmp("./photo/jiemian.bmp", 0, 0);

			while (1)
			{	
				//等待用户点击
				lcd->paddle_ts();
				//判断是否点击了本地按钮
				if (lcd->num[0] > 280 && lcd->num[0] < 510 && lcd->num[1] > 110 && lcd->num[1] < 210)
				{
					//关闭触摸屏
					close(lcd->ts_fd);
					//关闭lcd和映射
					lcd->~XQ();
					//打开lcd、映射和触摸屏
					lcd->is_open();
					//棋子初始化
					lcd->qi_initialize();
					//缓冲区的切换
					lcd->keshiqu();
					//绘画图片
					lcd->show_bmp("./photo/bendi.bmp", 0, 0);
					//延迟，1s=1000000us
					usleep(200000);
					//刷新
					refresh(lcd);
					//调用本地玩法接口
					bendi(lcd);
				}

				//判断是否点击了联机按钮
				if (lcd->num[0] > 280 && lcd->num[0] < 510 && lcd->num[1] > 260 && lcd->num[1] < 350)
				{
					lcd->n = 0;
					lcd->n_1 = 0;
					//缓冲区的切换
					lcd->keshiqu();
					//关闭lcd和映射
					lcd->~XQ();
					//联机接口
					all.all();

					//打开lcd、映射
					lcd->is_open();

					//缓冲区的切换
					lcd->keshiqu();
					//绘画图片
					lcd->show_bmp("./photo/jiemian.bmp", 0, 0);
				}
			}
		}
	}
	return 0;
}


//重新绘制图标
void refresh(XQ* lcd)
{
	lcd->n_1++;
	int p_x, p_y, qw_x, qw_y;
	lcd->show_bmp("./photo/qipan.bmp", 0, 0);
	p_y = 2;
	qw_y = 3;
	for (int i = 0; i < 10; i++)
	{
		p_x = 193;
		qw_x = 194;
		for (int j = 0; j < 9; j++)
		{
			if (lcd->kas[i][j].id > 0)
			{
				memset(lcd->str, 0, sizeof(lcd->str));
				sprintf(lcd->str, "./photo/%d.bmp", lcd->kas[i][j].id);
				lcd->show_bmp(lcd->str, p_x, p_y);
				//定位图标绘画
				if (lcd->kas[i][j].dw == 1)
				{
					lcd->show_bmp("./photo/dw.bmp", p_x, p_y);
				}
			}

			if (lcd->kas[i][j].id == 0)
			{
				//前位图标绘画
				if (lcd->kas[i][j].qw == 1)
				{
					lcd->show_bmp("./photo/qw.bmp", qw_x, qw_y);
				}
			}
			if (j == 3)
			{
				qw_x = qw_x + 1;
			}
			if (j == 4)
			{
				qw_x = qw_x + 1;
			}
			if (j == 5)
			{
				qw_x = qw_x + 1;
			}
			if (j == 6)
			{
				qw_x = qw_x + 1;
			}
			p_x = p_x + 47;
			qw_x = qw_x + 47;
		}
		if (i == 3)
		{
			qw_y = qw_y + 1;
		}
		if (i == 4)
		{
			qw_y = qw_y + 1;
		}
		if (i == 7)
		{
			qw_y = qw_y + 1;
		}
		if (i == 8)
		{
			qw_y = qw_y + 2;
		}
		p_y = p_y + 47;
		qw_y = qw_y + 47;
	}
	lcd->n++;
	lcd->keshiqu();
}


//本地玩法接口
void bendi(XQ* lcd)
{
	//定义局部变量
	/*
	i和j遍历循环用的
	n = n_1 % 2,一方n_1确认后+1;n用来判断当前执行方为什么颜色的棋子
	ws用来接收算法函数的返回值
	one_x, one_y, tow_x, tow_y,用来保存第一次点击的位置，和第二次点击的位置
	key用来判断是否已点击了第一次，这样子才可以进入点击第二次
	save_n实现第一次点击数据和第二次点击数据的切换
	huiqi1每回合一次+1，大于第二回合才可以解锁悔棋功能
	huiqi2判断该回合只是单纯行走还是吃了对方棋子
	huiqi3悔棋的功能判断辅助
	num_is,num,num_1判断双方的将领是否都存活
	save[2][2]保存最后一次操作和最后一次操作的前一次操作的第一次点击数据和第二次点击数据
	color[2],存字符串 "红" "黑"
	*/
	int i, j, n, n_1, ws, one_x, one_y, tow_x, tow_y, key, save_n, huiqi_1, huiqi_2, huiqi_3, num_is = 1, num, num_1;
	is_qi save[2][2];
	string color[2], one_color;


	//初始化
	if (key_key == 0)
	{
		for (int u = 0; u < 2; u++)
		{
			for (int u_1 = 0; u_1 < 2; u_1++)
			{
				save[u][u_1].color = "无";
				save[u][u_1].dw = 0;
				save[u][u_1].id = 0;
				save[u][u_1].qw = 0;
				save[u][u_1].x = 0;
				save[u][u_1].y = 0;
			}
		}
		color[0] = "红";
		color[1] = "黑";
		one_color = "无";
		i = 0, j = 0, n_1 = 0, n = 0, one_x = 0, one_y = 0, tow_x = 0, tow_y = 0, ws = 0, save_n = 0, huiqi_1 = 1, huiqi_2, huiqi_3 = 0;
		cout << "该 红  棋操作" << endl;
	}

	//把上次的数据赋值给当前
	if (key_key == 1)
	{
		n = r;
		n_1 = r_1;
		ws = r_2;
		one_x = r_3;
		one_y = r_4;
		tow_x = r_5;
		tow_y = r_6;
		key = r_7;
		color[0] = r_8[0];
		color[1] = r_8[1];
		one_color = r_8[2];
		huiqi_1 = huiqi1;
		huiqi_2 = huiqi2;
		huiqi_3 = huiqi3;
		save_n = saven;
		for (int u = 0; u < 2; u++)
		{
			for (int u_1 = 0; u_1 < 2; u_1++)
			{
				save[u][u_1].color = save1[u][u_1].color;
				save[u][u_1].dw = save1[u][u_1].dw;
				save[u][u_1].id = save1[u][u_1].id;
				save[u][u_1].qw = save1[u][u_1].qw;
				save[u][u_1].x = save1[u][u_1].x;
				save[u][u_1].y = save1[u][u_1].y;
			}
		}
	}

	while (1)
	{
		//等待用户点击
		lcd->paddle_ts();
		key = 0;
		key_key = 0;
		//判断第一次点击
		if (num_is == 1 && lcd->num[0] > 193 && lcd->num[0] < 616 && lcd->num[1] > 2 && lcd->num[1] < 472)
		{
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < 9; j++)
				{
					n = n_1 % 2;
					if ((lcd->num[0] > lcd->kas[i][j].x) && (lcd->num[0] < (lcd->kas[i][j].x + 47)) && (lcd->num[1] > lcd->kas[i][j].y) && (lcd->num[1] < (lcd->kas[i][j].y + 47)) && lcd->kas[i][j].id > 0)
					{
						if (lcd->kas[i][j].color == color[n])
						{
							//定位图标绘画
							lcd->kas[i][j].dw = 1;
							//刷新
							refresh(lcd);
							//完成第一次点击判断进入第二次点击判断
							while (key == 0)
							{
								//等待用户点击
								lcd->paddle_ts();
								if ((lcd->num[0] < lcd->kas[i][j].x) || (lcd->num[0] > (lcd->kas[i][j].x + 47)) || (lcd->num[1] < lcd->kas[i][j].y) || (lcd->num[1] > (lcd->kas[i][j].y + 47)))
								{
									for (int q = 0; q < 10; q++)
									{
										for (int w = 0; w < 9; w++)
										{
											if ((lcd->num[0] > lcd->kas[q][w].x) && (lcd->num[0] < (lcd->kas[q][w].x + 47)) && (lcd->num[1] > lcd->kas[q][w].y) && (lcd->num[1] < (lcd->kas[q][w].y + 47)))
											{
												if (lcd->kas[q][w].id == 0)
												{
													ws = 0;
													//调用算法
													ws = lcd->algorithm(i, j, q, w);

													if (ws == 1 || ws == 2)
													{
														//悔棋
														if (huiqi == 1 && huiqi_3 > 1)
														{
															lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].qw = 0;
															lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].dw = 0;
															if (save[(save_n % 2)][0].x == i && save[(save_n % 2)][0].y == j)
															{
																lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].qw = 1;
															}
															huiqi = 0;
														}
														save[(save_n % 2)][0].color = lcd->kas[i][j].color;
														save[(save_n % 2)][1].color = lcd->kas[q][w].color;
														save[(save_n % 2)][0].dw = lcd->kas[i][j].dw;
														save[(save_n % 2)][1].dw = lcd->kas[q][w].dw;
														save[(save_n % 2)][0].id = lcd->kas[i][j].id;
														save[(save_n % 2)][1].id = lcd->kas[q][w].id;
														save[(save_n % 2)][0].qw = lcd->kas[i][j].qw;
														save[(save_n % 2)][1].qw = lcd->kas[q][w].qw;
														save[(save_n % 2)][0].x = i;
														save[(save_n % 2)][1].x = q;
														save[(save_n % 2)][0].y = j;
														save[(save_n % 2)][1].y = w;

														save_n++;
														huiqi_3++;
														if (huiqi_3 > 2)
														{
															huiqi_1 = 0;
														}

														lcd->kas[q][w].id = lcd->kas[i][j].id;
														lcd->kas[q][w].color = lcd->kas[i][j].color;
														lcd->kas[i][j].color = "NULL";
														lcd->kas[i][j].id = 0;
														lcd->kas[q][w].dw = 1;
														lcd->kas[i][j].dw = 0;
														lcd->kas[i][j].qw = 1;

														lcd->kas[one_x][one_y].qw = 0;
														lcd->kas[tow_x][tow_y].dw = 0;

														one_x = i;
														one_y = j;
														tow_x = q;
														tow_y = w;

														one_color = lcd->kas[i][j].color;

														//刷新
														refresh(lcd);
														n_1++;
														cout << "该 " << color[(n_1 % 2)] << "  棋操作" << endl;
														cout << endl;
														key = 1;

														huiqi_2 = 1;

													}
												}
												if (lcd->kas[q][w].id > 0 && lcd->kas[q][w].color == color[((n_1 + 1) % 2)])
												{
													ws = 0;
													//调用算法
													ws = lcd->algorithm(i, j, q, w);

													if (ws == 1 || ws == 3)
													{
														//悔棋
														if (huiqi == 1 && huiqi_3 > 1)
														{
															lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].qw = 0;
															lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].dw = 0;

															if (save[(save_n % 2)][0].x == i && save[(save_n % 2)][0].y == j)
															{
																lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].qw = 1;
															}
															huiqi = 0;
														}
														save[(save_n % 2)][0].color = lcd->kas[i][j].color;
														save[(save_n % 2)][1].color = lcd->kas[q][w].color;
														save[(save_n % 2)][0].dw = lcd->kas[i][j].dw;
														save[(save_n % 2)][1].dw = lcd->kas[q][w].dw;
														save[(save_n % 2)][0].id = lcd->kas[i][j].id;
														save[(save_n % 2)][1].id = lcd->kas[q][w].id;
														save[(save_n % 2)][0].qw = lcd->kas[i][j].qw;
														save[(save_n % 2)][1].qw = lcd->kas[q][w].qw;
														save[(save_n % 2)][0].x = i;
														save[(save_n % 2)][1].x = q;
														save[(save_n % 2)][0].y = j;
														save[(save_n % 2)][1].y = w;

														save_n++;
														huiqi_3++;
														if (huiqi_3 > 2)
														{
															huiqi_1 = 0;
														}

														lcd->kas[q][w].id = lcd->kas[i][j].id;
														lcd->kas[q][w].color = lcd->kas[i][j].color;
														lcd->kas[i][j].color = "NULL";
														lcd->kas[i][j].id = 0;
														lcd->kas[q][w].dw = 1;
														lcd->kas[i][j].dw = 0;
														lcd->kas[i][j].qw = 1;

														lcd->kas[one_x][one_y].qw = 0;
														lcd->kas[tow_x][tow_y].dw = 0;
														one_x = i;
														one_y = j;
														tow_x = q;
														tow_y = w;

														one_color = lcd->kas[i][j].color;

														//刷新
														refresh(lcd);

														n_1++;
														cout << "该 " << color[(n_1 % 2)] << "  棋操作" << endl;
														cout << endl;
														key = 1;
														huiqi_2 = 2;

														//判断将军在不在
														num = 0;
														num_1 = 0;
														for (int i = 0; i < 3; i++)
														{
															for (int j = 4; j < 7; j++)
															{
																if (lcd->kas[i][j].id == 5)
																{
																	num++;
																}
															}
														}
														if (num == 0)
														{
															cout << "红棋获胜" << endl;
															num_is = 0;

															lcd->keshiqu();
															lcd->show_bmp("./photo/heijian.bmp", 200, 120);
															usleep(1200000);
															lcd->keshiqu();
															lcd->show_bmp("./photo/over-hong.bmp", 0, 0);

															while (1)
															{
																lcd->paddle_ts();
																//退出事件
																if (lcd->num[0] > 5 && lcd->num[0] < 65 && lcd->num[1] > 5 && lcd->num[1] < 65)
																{
																	lcd->keshiqu();
																	lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);
																	lcd->keshiqu();
																	lcd->photo_load();
																	lcd->keshiqu();
																	lcd->show_bmp("./photo/jiemian.bmp", 0, 0);
																	return;
																}
															}
														}

														for (int i = 7; i < 10; i++)
														{
															for (int j = 4; j < 7; j++)
															{
																if (lcd->kas[i][j].id == 12)
																{
																	num_1++;
																}
															}
														}
														if (num_1 == 0)
														{
															cout << "黑棋获胜" << endl;
															num_is = 0;

															lcd->keshiqu();
															lcd->show_bmp("./photo/honjian.bmp", 200, 120);
															usleep(1200000);
															lcd->keshiqu();
															lcd->show_bmp("./photo/over-hei.bmp", 0, 0);

															while (1)
															{
																lcd->paddle_ts();
																//退出事件
																if (lcd->num[0] > 5 && lcd->num[0] < 65 && lcd->num[1] > 5 && lcd->num[1] < 65)
																{
																	lcd->keshiqu();
																	lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);
																	lcd->keshiqu();
																	lcd->photo_load();
																	lcd->keshiqu();
																	lcd->show_bmp("./photo/jiemian.bmp", 0, 0);

																	return;
																}
															}
														}

														if (color[((n_1-1)%2)] == "红")
														{
															//吃字效果
															lcd->keshiqu();
															lcd->show_bmp("./photo/honci-1.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-2.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-3.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-4.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-5.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-6.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-7.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-8.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-9.bmp", 650, 50);
															usleep(80000);
															lcd->show_bmp("./photo/honci-10.bmp", 650, 50);
															usleep(80000);
														}
														if (color[((n_1 - 1) % 2)] == "黑")
														{
															//吃字效果
															lcd->keshiqu();
															lcd->show_bmp("./photo/heici-1.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-2.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-3.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-4.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-5.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-6.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-7.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-8.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-9.bmp", 50, 330);
															usleep(80000);
															lcd->show_bmp("./photo/heici-10.bmp", 50, 330);
															usleep(80000);
														}
														
													}
												}
												if (lcd->kas[q][w].id > 0 && lcd->kas[q][w].color == color[n])
												{
													lcd->kas[i][j].dw = 0;
													lcd->kas[q][w].dw = 1;
													i = q;
													j = w;

													//刷新
													refresh(lcd);
												}
											}
										}
									}
								}
								//退出事件
								if (num_is == 1 && lcd->num[0] > 5 && lcd->num[0] < 65 && lcd->num[1] > 5 && lcd->num[1] < 65)
								{
									lcd->keshiqu();
									lcd->show_bmp("./photo/tc.bmp", 205, 120);
									while (1)
									{
										lcd->paddle_ts();
										//二次确认点了是
										if (lcd->num[0] > 250 && lcd->num[0] < 350 && lcd->num[1] > 280 && lcd->num[1] < 335)
										{
											lcd->keshiqu();
											lcd->show_bmp("./photo/tc1.bmp", 250, 120);
											usleep(200000);
											lcd->keshiqu();
											lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);

											lcd->photo_load();
											lcd->keshiqu();
											lcd->show_bmp("./photo/rj.bmp", 0, 0);

											while (1)
											{
												lcd->paddle_ts();
												if (lcd->num[0] > 30 && lcd->num[0] < 110 && lcd->num[1] > 30 && lcd->num[1] < 110)
												{
													lcd->keshiqu();
													lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);

													lcd->photo_load();

													lcd->keshiqu();
													lcd->show_bmp("./photo/jiemian.bmp", 0, 0);

													return;
												}
											}
										}
										//二次确认点了否
										if (lcd->num[0] > 420 && lcd->num[0] < 520 && lcd->num[1] > 280 && lcd->num[1] < 335)
										{
											lcd->kas[i][j].dw = 0;
											r = n;
											r_1 = n_1;
											r_2 = ws;
											r_3 = one_x;
											r_4 = one_y;
											r_5 = tow_x;
											r_6 = tow_y;
											r_7 = key;
											r_8[0] = color[0];
											r_8[1] = color[1];
											r_8[2] = one_color;
											huiqi1 = huiqi_1;
											huiqi2 = huiqi_2;
											huiqi3 = huiqi_3;
											saven = save_n;
											for (int u = 0; u < 2; u++)
											{
												for (int u_1 = 0; u_1 < 2; u_1++)
												{
													save1[u][u_1].color = save[u][u_1].color;
													save1[u][u_1].dw = save[u][u_1].dw;
													save1[u][u_1].id = save[u][u_1].id;
													save1[u][u_1].qw = save[u][u_1].qw;
													save1[u][u_1].x = save[u][u_1].x;
													save1[u][u_1].y = save[u][u_1].y;
												}
											}
											lcd->keshiqu();
											lcd->show_bmp("./photo/tc2.bmp", 205, 120);
											usleep(200000);
											//刷新
											refresh(lcd);
											key_key = 1;
											bendi(lcd);
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//黑棋悔棋事件
		if (huiqi_1 == 0 && num_is == 1 && lcd->num[0] > 30 && lcd->num[0] < 170 && lcd->num[1] > 120 && lcd->num[1] < 210)
		{
			save_n--;
			//行走
			if (huiqi_2 == 1)
			{
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].id = save[(save_n % 2)][0].id;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].color = save[(save_n % 2)][0].color;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].dw = 0;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].qw = save[(save_n % 2)][0].qw;

				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].id = 0;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].color = "无";
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].dw = 0;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].qw = 0;

				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].id = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].color = "无";
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].dw = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].qw = 1;

				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].id = save[((save_n - 1) % 2)][0].id;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].color = save[((save_n - 1) % 2)][0].color;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].dw = save[((save_n - 1) % 2)][0].dw;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].qw = save[((save_n - 1) % 2)][0].qw;
			}
			//吃子
			if (huiqi_2 == 2)
			{
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].id = save[(save_n % 2)][0].id;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].color = save[(save_n % 2)][0].color;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].dw = 0;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].qw = save[(save_n % 2)][0].qw;

				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].id = save[(save_n % 2)][1].id;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].color = save[(save_n % 2)][1].color;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].dw = save[(save_n % 2)][1].dw;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].qw = save[(save_n % 2)][1].qw;

				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].id = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].color = "无";
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].dw = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].qw = 1;

				cout << ((save_n - 1) % 2) << endl;
				cout << "" << endl;
				cout << "" << endl;
				cout << "" << endl;

				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].id = save[((save_n - 1) % 2)][0].id;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].dw = save[((save_n - 1) % 2)][0].dw;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].qw = save[((save_n - 1) % 2)][0].qw;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].color = save[((save_n - 1) % 2)][0].color;
			}
			huiqi_1 = 1;
			n_1--;
			huiqi_3--;
			huiqi = 1;
			//刷新
			refresh(lcd);

		}
		//红旗悔棋事件
		if (huiqi_1 == 0 && num_is == 1 && lcd->num[0] > 630 && lcd->num[0] < 770 && lcd->num[1] > 270 && lcd->num[1] < 370)
		{
			save_n--;
			//行走
			if (huiqi_2 == 1)
			{
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].id = save[(save_n % 2)][0].id;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].color = save[(save_n % 2)][0].color;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].dw = 0;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].qw = save[(save_n % 2)][0].qw;

				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].id = 0;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].color = "无";
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].dw = 0;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].qw = 0;

				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].id = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].color = "无";
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].dw = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].qw = 1;

				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].id = save[((save_n - 1) % 2)][0].id;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].color = save[((save_n - 1) % 2)][0].color;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].dw = save[((save_n - 1) % 2)][0].dw;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].qw = save[((save_n - 1) % 2)][0].qw;
			}
			//吃子
			if (huiqi_2 == 2)
			{
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].id = save[(save_n % 2)][0].id;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].color = save[(save_n % 2)][0].color;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].dw = 0;
				lcd->kas[save[(save_n % 2)][0].x][save[(save_n % 2)][0].y].qw = save[(save_n % 2)][0].qw;

				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].id = save[(save_n % 2)][1].id;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].color = save[(save_n % 2)][1].color;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].dw = save[(save_n % 2)][1].dw;
				lcd->kas[save[(save_n % 2)][1].x][save[(save_n % 2)][1].y].qw = save[(save_n % 2)][1].qw;

				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].id = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].color = "无";
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].dw = 0;
				lcd->kas[save[((save_n - 1) % 2)][0].x][save[((save_n - 1) % 2)][0].y].qw = 1;

				cout << ((save_n - 1) % 2) << endl;
				cout << "" << endl;
				cout << "" << endl;
				cout << "" << endl;

				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].id = save[((save_n - 1) % 2)][0].id;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].dw = save[((save_n - 1) % 2)][0].dw;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].qw = save[((save_n - 1) % 2)][0].qw;
				lcd->kas[save[((save_n - 1) % 2)][1].x][save[((save_n - 1) % 2)][1].y].color = save[((save_n - 1) % 2)][0].color;
			}
			huiqi_1 = 1;
			n_1--;
			huiqi_3--;
			huiqi = 1;
			//刷新
			refresh(lcd);
		}
		//退出事件
		if (num_is == 1 && lcd->num[0] > 5 && lcd->num[0] < 65 && lcd->num[1] > 5 && lcd->num[1] < 65)
		{
			lcd->keshiqu();
			lcd->show_bmp("./photo/tc.bmp", 205, 120);
			while (1)
			{
				lcd->keshiqu();
				lcd->paddle_ts();
				if (lcd->num[0] > 250 && lcd->num[0] < 350 && lcd->num[1] > 280 && lcd->num[1] < 335)
				{
					lcd->keshiqu();
					lcd->show_bmp("./photo/tc1.bmp", 205, 120);
					usleep(200000);
					lcd->keshiqu();
					lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);
					//进度条
					lcd->photo_load();
					lcd->keshiqu();
					lcd->show_bmp("./photo/rj.bmp", 0, 0);

					while (1)
					{
						lcd->paddle_ts();
						if (lcd->num[0] > 30 && lcd->num[0] < 110 && lcd->num[1] > 30 && lcd->num[1] < 110)
						{
							lcd->keshiqu();
							lcd->show_bmp("./photo/jiazai0.bmp", 0, 0);
							lcd->photo_load();

							lcd->keshiqu();
							lcd->show_bmp("./photo/jiemian.bmp", 0, 0);
							return;
						}
					}
				}
				if (lcd->num[0] > 420 && lcd->num[0] < 520 && lcd->num[1] > 280 && lcd->num[1] < 335)
				{
					r = n;
					r_1 = n_1;
					r_2 = ws;
					r_3 = one_x;
					r_4 = one_y;
					r_5 = tow_x;
					r_6 = tow_y;
					r_7 = key;
					r_8[0] = color[0];
					r_8[1] = color[1];
					r_8[2] = one_color;
					huiqi1 = huiqi_1;
					huiqi2 = huiqi_2;
					huiqi3 = huiqi_3;
					saven = save_n;
					for (int u = 0; u < 2; u++)
					{
						for (int u_1 = 0; u_1 < 2; u_1++)
						{
							save1[u][u_1].color = save[u][u_1].color;
							save1[u][u_1].dw = save[u][u_1].dw;
							save1[u][u_1].id = save[u][u_1].id;
							save1[u][u_1].qw = save[u][u_1].qw;
							save1[u][u_1].x = save[u][u_1].x;
							save1[u][u_1].y = save[u][u_1].y;
						}
					}
					lcd->keshiqu();
					lcd->show_bmp("./photo/tc2.bmp", 205, 120);
					usleep(200000);
					//刷新
					refresh(lcd);
					key_key = 1;
					bendi(lcd);
					return;
				}
			}
		}
	}
}


