#pragma once
#include<iostream>
#include "LcdDevice.h"
#include"Bmp.h"
#include"client.h"
#include<fstream>
using namespace std;

class Qi
{
public:
	int id, x, y;
	string color;
	string bmp;
};

class Chess
{
public:

	Chess();
	~Chess();
	Qi str[10][9];
	Qi savestr[1][4];
	int cmp;
	int send_save_sub_x, send_save_sub_y, send_that_sub_x, send_that_sub_y, recv_save_sub_x, recv_save_sub_y, recv_that_sub_x, recv_that_sub_y;
	int isfriend;
	void getsub(int x, int y, int* sub_x, int* sub_y);
	void transub();
	void showData();
	void showData_all();
	void setdata_r(string txt);
	void setdata_b(string txt);
	void savedata(int sub_x1, int sub_y1, int sub_x2, int sub_y2, string is_save);
	void show_savedata();
	void show_send_data(string isfirst);
	void show_recv_data(string isfirst);
	void che(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void ma(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void xiang_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void xiang_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void xiang(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void shi_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void shi_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void shi(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void jiang_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void jiang_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void jiang(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void pao(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void bin_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void bin_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void bin(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1);
	void rule(int sub_x1, int sub_y1, int dj_hq1);
	void all();
};
