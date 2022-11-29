#include "bmp.h"

struct Bmp *create_bmp(const char *bmpfile)
{
    //创建申请bmp空间
    struct Bmp *bmp = malloc(sizeof(struct Bmp));
    if (bmp == NULL)
        return NULL;
    //打开bmpfile文件
    FILE *file = fopen(bmpfile, "r");
    if (file == NULL)
    {
        perror("fopen");
        free(bmp);
        return NULL;
    }
    //读取bmp头
    size_t size = fread(&bmp->header, 1, 54, file);
    if (size < 0)
    {
        fclose(file);
        free(bmp);
        return NULL;
    }

    //计算像素占用的内存空间大小
    bmp->w = bmp->header.biWidth;
    bmp->h = bmp->header.biHeight;
    bmp->pix = bmp->header.biBitCount / 8;
    unsigned int rgbsize = bmp->w * bmp->h * bmp->pix;

    //申请保存像素数据的空间
    bmp->data = (unsigned char *)malloc(rgbsize);

    //定义填充的字节数
    int pad = (bmp->w * bmp->pix % 4) ? (4 - (bmp->w * bmp->pix % 4)) : 0;

    //定义保存一行像素空间(包括填充空间)
    unsigned char tmp[bmp->w * bmp->pix + pad];

    //循环读取，一次读取一行
    for (int i = 0; i < bmp->h; i++)
    {
        //读取一行像素值（在bmp文件中一行像素占用的字节数是4的倍数）
        fread(tmp, 1, sizeof(tmp), file);
        memcpy(bmp->data + i * bmp->w * bmp->pix, tmp, bmp->w * bmp->pix); //拷贝的时候把填充部分去掉
    }
    //返回
    fclose(file);
    return bmp;
}

//销毁bmp
bool destroy_bmp(struct Bmp *mp)
{
    if (mp == NULL)
        return false;
    free(mp->data);
    free(mp);
    return true;
}

//按照给的尺寸缩放
void zoom_bmp(struct Bmp *mp, int w, int h)
{
    if (mp == NULL)
        return;

    //申请一个保存目标图片的空间
    unsigned char *destmap = malloc(w * h * mp->pix);

    //计算原图与目标图的宽，高对应的比例
    // double dw = mp->w / (double)w;
    // double dh = mp->h / (double)h;

    //从原图中拷贝数据到目标图中
    for (int i = 0; i < h; i++)
    {
        //拷贝一行
        for (int j = 0; j < w; j++)
        {
            //拷贝一个像素
            destmap[j * 3 + 0 + i * w * 3] = mp->data[(j * mp->w / w) * 3 + 0 + (i * mp->h / h) * mp->w * 3];
            destmap[j * 3 + 1 + i * w * 3] = mp->data[(j * mp->w / w) * 3 + 1 + (i * mp->h / h) * mp->w * 3];
            destmap[j * 3 + 2 + i * w * 3] = mp->data[(j * mp->w / w) * 3 + 2 + (i * mp->h / h) * mp->w * 3];
        }
    }
    mp->w = w;
    mp->h = h;
    free(mp->data);
    mp->data = destmap;
}

//反转
void reverse_bmp(struct Bmp *mp)
{
    //把最后一行放第一行第一行放最后一行， 倒数第二行与第二行进行调换
    if (mp == NULL)
        return;
    //申请一段空间存储一行像素
    int rowsize = mp->w * mp->pix;
    unsigned char tmp[mp->w * mp->pix];
    for (int i = 0; i < mp->h / 2; i++)
    {
        memcpy(tmp, mp->data + i * rowsize, rowsize);                                    //把第一行存储在tmp中
        memcpy(mp->data + i * rowsize, mp->data + (rowsize) * (mp->h - i - 1), rowsize); //把最后一行拷贝到第一行
        memcpy(mp->data + (rowsize) * (mp->h - i - 1), tmp, rowsize);
    }
}

void show_bmp(LcdDevice *lcd, int x, int y, struct Bmp *mp)
{
    //根据lcd，bmp尺寸和x，y位置计算要绘制图片的宽dw，高dh
    int dw, dh;
    //保存lcd绘制开始位置(x,y)指针
    unsigned int *p = NULL;
    //保存bmp图片数据的开始位置p指针
    unsigned char *px = NULL;
    if (x >= 0 && y >= 0)
    {
        //根据lcd，bmp尺寸和x，y位置计算要绘制图片的宽dw，高dh
        dw = ((x + mp->w) > lcd->w) ? (lcd->w - x) : mp->w;
        dh = ((y + mp->h) > lcd->h) ? (lcd->h - y) : mp->h;

        //把lcd绘图指针移动x，y位置
        p = lcd->mptr + x + y * lcd->w;
        //定义一个指针指向图片像素首地址
        px = mp->data;
    }
    //绘制
    for (int i = 0; i < dh; i++)
    {
        for (int j = 0; j < dw; j++)
        {
            //从px开始位置拷贝3字节给到p开始位置,之后p和px 往后偏移j个像素
            memcpy(p + j, px + j * 3, 3);
        }
        p += lcd->w;     // lcd绘制指针移动到下一行
        px += mp->w * 3; // bmp图片指针移动到下一行
    }
}
//保存bmp
void save_bmp(struct Bmp* mp,const char *bmpfile)
{
    if(mp == NULL) return;
    //计算图像一行数据占用的字节数
    int rowsize = mp->pix*mp->w;
    if(rowsize%4 != 0)
    {
        rowsize += 4 - rowsize%4;
    }

    //计算imagesize
    int imagesize = rowsize*mp->h;
    mp->header.biSizeImage = imagesize;//初始化头像素大小
    mp->header.bfSize = imagesize+54;//初始化文件大小
    mp->header.biHeight = mp->h;
    mp->header.biWidth = mp->w;
    mp->header.biBitCount = mp->pix*8;

    //打开文件
    FILE* file  = fopen(bmpfile,"w");
    if(file==NULL)
    {
        perror("save");
        return ;
    }

    //写文件头
    fwrite(&mp->header, 1, 54, file);
    //写rgb数据
    for(int i=0; i<mp->h; i++)
    {
        //写一行像素到文件（包括补齐的字节数）
        fwrite(mp->data+i*mp->w*mp->pix,1, rowsize, file);
    }

    //关闭文件
    fclose(file);
}

unsigned int getpix(struct Bmp *mp, int x, int y)
{
    unsigned char *da = mp->data + y * mp->pix * mp->w + x * mp->pix;
    unsigned int rgb = 0;
    rgb = rgb | (da[0] << 8);
    rgb = rgb | (da[1] << 16);
    rgb = rgb | (da[2] << 24);
    return rgb;
}
