#pragma once

#include <cstring>
#include <iostream>
#include <unistd.h>

extern"C"
{
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <dlfcn.h>  // 动态加载动态库的头文件：dlopen()、dlsym()
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <linux/input.h>
#include <stdlib.h>
}

using namespace std;

// BMP格式头规范
struct bitmap_header
{
	int16_t type;
	int32_t size; // 图像文件大小
	int16_t reserved1;
	int16_t reserved2;
	int32_t offbits; // bmp图像数据偏移量
}__attribute__((packed));

struct bitmap_info
{
	int32_t size;   // 本结构大小	
	int32_t width;  // 图像宽
	int32_t height; // 图像高
	int16_t planes;

	int16_t bit_count; // 色深
	int32_t compression;
	int32_t size_img; // bmp数据大小，必须是4的整数倍
	int32_t X_pel;
	int32_t Y_pel;
	int32_t clrused;
	int32_t clrImportant;
}__attribute__((packed));

// 以下结构体不一定存在于BMP文件中，除非： bitmap_info.compression为真
struct rgb_quad
{
	int8_t blue;
	int8_t green;
	int8_t red;
	int8_t reserved;
}__attribute__((packed));

//结构体
struct is_qi
{
	int id, x, y, dw, qw;
	string color;
};

class XQ
{
    int fd;
    int w, h, pix;
    unsigned int* mptr;

    //把构造函数设置为私有， 那么在类外就不能通过构造函数创建对象
	XQ(const char* dev = "/dev/fb0");
	XQ(const XQ& l) {}
public:
	int num[4], in, ts_fd,n,n_1;
	is_qi kas[10][9];
	char str[32];
	//2.获取lcd参数
	struct fb_var_screeninfo vinfo;

    static XQ* createlcd();
	void keshiqu(void);
	void paddle_ts(void);
	void qi_initialize();
	void is_open(void);
	void photo_load(void);
    void clear(unsigned int color);
	int algorithm(int i, int j, int q, int w);
	int show_bmp(const char* pathname, int start_x, int start_y);
	~XQ();
};



