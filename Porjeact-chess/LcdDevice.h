/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-21 19:43:19
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-24 11:02:38
 * @FilePath: \c++\3.象棋项目\LcdDevice.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include"Bmp.h"
#include <iostream>
#include <linux/input.h>
extern"C"
{
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdbool.h>
}

using namespace std;

class LcdDevice
{
	int fd;
	int w, h, pix;
	unsigned int* mptr;
	unsigned int* cpptr;
	LcdDevice(string devname = "/dev/fb0");
	LcdDevice(const LcdDevice& lcd) {};
public:

	static LcdDevice* getLcd() {
		static LcdDevice lcd;
		return &lcd;
	}
	~LcdDevice();
	void clear(unsigned int color = 0x00ffffff);
	void drawRect(int x, int y, int w, int h, unsigned int color);
	void drawFill(int x, int y, int w, int h, unsigned int color);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawCircle(int x, int y, int r);
	void drawRgb(int x, int y, unsigned char* rgb, int w, int h);
	void drawrgb(int x, int y, unsigned int rgb, int w, int h);
	//void showData();
	void getptr(int x, int y, int w, int h);
	void drawRgb_area(int x, int y, unsigned char* rgb, int w, int h);
	bool djyesno(int dj_hq, int* x1, int* y1);
	void drawptr(int x, int y, int w, int h);
};

