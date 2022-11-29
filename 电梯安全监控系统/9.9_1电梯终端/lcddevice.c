#include "lcddevice.h"
#include <linux/fb.h>

static LcdDevice* lcd = NULL;
void clear(unsigned int color){
    if(lcd == NULL) return;
    for(int i=0; i<lcd->w*lcd->h; i++)
    {
        lcd->mptr[i] = color;
    }
}

static void drawRect(int x, int y, int w, int h,unsigned int color){}
static void drawFill(int x, int y, int w, int h,unsigned int color){
    if(lcd == NULL) return ;
    unsigned int *p = lcd->mptr;
    //把指针p移动到要绘制的开始位置
    p = p+x+y*lcd->w;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            p[j] = color;
        }
        p+= lcd->w;//移动到下一行
    }
}

static void drawLine(int x1, int y1, int x2, int y2){}
static void drawCircle(int x, int y, int r){}

LcdDevice *getLcd(const char *dev)
{
    if(lcd == NULL) return create_lcd(dev);
    else return lcd;
}

LcdDevice* create_lcd(const char *dev)
{
    lcd = malloc(sizeof(LcdDevice));
    if(lcd == NULL) return NULL;

    //初始化函数指针
    lcd->clear = clear;
    lcd->drawRect = drawRect;
    lcd->drawLine = drawLine;
    lcd->drawCircle = drawCircle;
    lcd->drawFill = drawFill;
    //打开设备
    lcd->fd = open(dev,O_RDWR);
    if(lcd->fd < 0)
    {
        perror("open");
        goto err;
    }

    //获取lcd参数
    struct fb_var_screeninfo info;
    int ret = ioctl(lcd->fd,FBIOGET_VSCREENINFO,&info);
    if(ret < 0)
    {
        perror("ioctl");
        lcd->w = 800; 
        lcd->h = 480;
        lcd->pix = 4;
    }else
    {
        #ifdef PC
        lcd->w = info.xres_virtual; //虚拟区域（ubuntu虚拟机）
        lcd->h = info.yres_virtual;
        lcd->pix = info.bits_per_pixel/8;
        #else
        lcd->w = info.xres;
        lcd->h = info.yres;
        lcd->pix = info.bits_per_pixel/8;
        #endif
    }

    //映射
    int ssize = lcd->w*lcd->h*lcd->pix;
    lcd->mptr = (unsigned int *)mmap(NULL,ssize, PROT_READ|PROT_WRITE,MAP_SHARED,lcd->fd,0);
    if(lcd->mptr == MAP_FAILED)
    {
        perror("map");
        goto err;
    }
    return lcd;
err:
    free(lcd);
    return NULL;
}
bool destroy_lcd(LcdDevice* lcd)
{
    if(lcd != NULL)
    {
        if(lcd->mptr != MAP_FAILED)
        {
            int ssize = lcd->w*lcd->h*lcd->pix;
            munmap(lcd->mptr, ssize);
        }
        close(lcd->fd);
        free(lcd);
        return true;
    }
    return false;
}