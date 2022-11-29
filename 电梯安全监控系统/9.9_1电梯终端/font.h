/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-08-23 11:06:58
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-09 19:37:43
 * @FilePath: \gx\8.22\font.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-08-12 15:42:58
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-08-13 19:28:54
 * @FilePath: \gx\8.12\3.汉字显示\font.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#ifndef C543C13C_B8B1_46ED_AC60_50C67736370D
#define C543C13C_B8B1_46ED_AC60_50C67736370D
#ifndef __font_h__
#define __font_h__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include"bmp.h"
#define color u32
#define getColor(a, b, c, d) (a|b<<8|c<<16|d<<24)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef struct stbtt_fontinfo
{
   void           * userdata;
   unsigned char  * data;              // pointer to .ttf file
   int              fontstart;         // offset of start of font
   int numGlyphs;                     // number of glyphs, needed for range checking
   int loca,head,glyf,hhea,hmtx,kern; // table locations as offset from start of .ttf
   int index_map;                     // a cmap mapping for our chosen character encoding
   int indexToLocFormat;              // format needed to map from glyph index to glyph
} stbtt_fontinfo;

typedef struct{
	u32 height;
	u32 width;
	u32 byteperpixel;
	u8 *map;
}bitmap;

typedef struct{
	stbtt_fontinfo *info;
	u8 *buffer;
	float scale;
}font;



//1.初始化字库 
font *fontLoad(char *fontPath);

//2.设置字体的大小 
void fontSetSize(font *f, s32 pixels);

//3.设置字体输出框的大小
bitmap *createBitmap(u32 width, u32 height, u32 byteperpixel);

//可以指定输出框的颜色
//参数:u32 width, u32 height宽高,  byteperpixel-一个像素占用字节数, c区域初始化颜色
bitmap *createBitmapWithInit(u32 width, u32 height, u32 byteperpixel, color c);

//4.把字体输出到输出框中
//参数 f-字库, screen-绘制文字区域, x, y位置, text要绘制的文字, c文字颜色, maxwidth文字最大宽度默认0自动识别字大小
void fontPrint(font *f, bitmap *screen, s32 x, s32 y, char *text, color c, s32 maxWidth);
//设置背景颜色
void setPixel(bitmap *bm, u32 x, u32 y, color c);
//
color getPixel(bitmap *bm, u32 x, u32 y);//获取背景颜色
// 关闭字体库
void fontUnload(font *f);

// 关闭bitmap
void destroyBitmap(bitmap *bm);

//用到struct Bmp，得加相应的头文件
//设置汉字显示区域背景，当图片mp不为空时，设置图片作为背景，为空时，将col作为背景色
//w：汉字显示区域宽，h：汉字显示区域高，x，y：从x，y开始获取
void setfontPix(bitmap *font,struct Bmp* mp,int w,int h,int x,int y,unsigned int col);

void show_font(LcdDevice *lcd, int x, int y, bitmap *mp);


#endif


#endif /* C543C13C_B8B1_46ED_AC60_50C67736370D */
