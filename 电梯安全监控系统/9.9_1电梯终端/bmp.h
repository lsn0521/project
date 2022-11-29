/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-08-12 21:01:00
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-08-27 20:54:38
 * @FilePath: \gx\8.12\3.汉字显示\bmp.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#ifndef C4AF38C5_DF3C_4489_9354_7E35AA96C161
#define C4AF38C5_DF3C_4489_9354_7E35AA96C161
#ifndef FF3B3CB8_41DA_4E6B_96D0_EA377D19F9C5
#define FF3B3CB8_41DA_4E6B_96D0_EA377D19F9C5
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lcddevice.h"
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#pragma pack(1) //设置1字节对齐
typedef struct BitFileHeader
{
	uint16 bfType; //位图类别，根据不同的操作系统而不同，在Windows中，此字段的值总为‘BM’BMP
	uint32 bfSize; // BMP图像文件的大小
	uint16 bfReserved1;
	uint16 bfReserved2;
	uint32 bfOffBits; // BMP图像数据的地址
	uint32 biSize;	  //表示本结构的大小
	uint32 biWidth;	  //位图的宽度
	uint32 biHeight;  //位图的高度
	uint16 biPlanes;
	uint16 biBitCount;		// BMP图像的色深，即一个像素用多少位表示，常见有1、4、8、16、24和32，分别对应单色、16色、256色、16位高彩色、24位真彩色和32位增强型真彩色
	uint32 biCompression;	//压缩方式，0表示不压缩，1表示RLE8压缩，2表示RLE4压缩，3表示每个像素值由指定的掩码决定
	uint32 biSizeImage;		// BMP图像数据大小，必须是4的倍数，图像数据大小不是4的倍数时用0填充补足
	uint32 biXPelsPerMeter; //水平分辨率，单位像素/m
	uint32 biYPelsPerMeter; //垂直分辨率，单位像素/m
	uint32 biClrUsed;		// BMP图像使用的颜色，0表示使用全部颜色，对于256色位图来说，此值为100h=256
	uint32 biClrImportant;	//重要的颜色数，此值为0时所有颜色都重要，对于使用调色板的BMP图像来说，当显卡不能够显示所有颜色时，此值将辅助驱动程序显示颜色
} BitHeader;
#pragma pack(0) //设置为默认字节对齐

struct Bmp
{
	int w, h, pix;		 //保存宽高，一个像素占用的字节数
	unsigned char *data; //保存rgb数据
	BitHeader header;	 //保存bmp头
};
//创建bmp对象
struct Bmp *create_bmp(const char *bmpfile);
//销毁BMP对象
bool destroy_bmp(struct Bmp *mp);
//按照w，h尺寸缩放mp
void zoom_bmp(struct Bmp *mp, int w, int h);
//把mp保存到文件
void save_bmp(struct Bmp *mp, const char *bmpfile);
//把bmp图片反转
void reverse_bmp(struct Bmp *mp);
void show_bmp(LcdDevice *lcd, int x, int y, struct Bmp *mp);

unsigned int getpix(struct Bmp *mp, int x, int y);

#endif /* FF3B3CB8_41DA_4E6B_96D0_EA377D19F9C5 */

#endif /* C4AF38C5_DF3C_4489_9354_7E35AA96C161 */
