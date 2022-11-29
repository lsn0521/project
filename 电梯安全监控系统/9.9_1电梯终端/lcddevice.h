#ifndef B0502C36_30AA_4F0C_8582_97A811D4EF73
#define B0502C36_30AA_4F0C_8582_97A811D4EF73
#ifndef _LCDDEVICE_H_
#define _LCDDEVICE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdbool.h>
typedef struct LcdDevice {
    int fd;
    int w, h, pix;
    unsigned int *mptr;
    void (*clear)(unsigned int color);
    void (*drawRect)(int x, int y, int w, int h,unsigned int color);
    void (*drawFill)(int x, int y, int w, int h,unsigned int color);
    void (*drawLine)(int x1, int y1, int x2, int y2);
    void (*drawCircle)(int x, int y, int r);
}LcdDevice;
LcdDevice* create_lcd(const char *dev);
bool destroy_lcd(LcdDevice* lcd);

#endif//_LCDDEVICE_H_


#endif /* B0502C36_30AA_4F0C_8582_97A811D4EF73 */
