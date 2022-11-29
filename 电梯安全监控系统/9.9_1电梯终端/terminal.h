/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-16 09:05:21
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-16 10:26:33
 * @FilePath: \gx\9.9_1电梯终端\terminal.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef BC3E93A6_8F31_4FEA_80DF_76DB12A0CCDB
#define BC3E93A6_8F31_4FEA_80DF_76DB12A0CCDB
#include <stdio.h>
#include "bmp.h"
#include "lcddevice.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include "font.h"

LcdDevice *lcd;
struct Bmp *mp ;
struct Bmp *mpbattery ;
bitmap *fmp ;
font *f ;
font *f1 ;
FILE *fd ;
FILE *file ;
int open_closedoor_num , day_num , longtime_num , barrier_num , floor_spacing ,
    run_num , runmileage_num , runtime_num , people_num , people_number ;
char buff[128];
char day_numbuff[128];
char longtime_numbuff[128];
char barrier_numbuff[128];
char open_closedoor_numbuff[128];
char floor_numbuff[128];
char run_numbuff[128];
char runmileage_numbuff[128];
char runtime_numbuff[128];
char people_numbuff[128];

void shownotice(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n);
void showtime(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n);
void showweather(LcdDevice *lcd, struct Bmp *mp, font *f, bitmap *fmp, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n);
void showdata(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, char buff[128]);
void show_news(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n);
void show_maintain(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n);
void readdata(int readfd);
#endif /* BC3E93A6_8F31_4FEA_80DF_76DB12A0CCDB */
