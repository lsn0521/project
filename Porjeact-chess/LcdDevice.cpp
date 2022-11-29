#include "LcdDevice.h"
#include <linux/fb.h>
#include <fstream>
#include <cstring>
LcdDevice::LcdDevice(string devname)
{
	//打开设备
	this->fd = open(devname.c_str(), O_RDWR);
	if (this->fd < 0)
	{
		perror("open");
	}

	//获取lcd参数
	struct fb_var_screeninfo info;
	int ret = ioctl(this->fd, FBIOGET_VSCREENINFO, &info);
	if (ret < 0)
	{
		perror("ioctl");
		this->w = 800;
		this->h = 480;
		this->pix = 4;
	}
	else
	{
#ifdef PC
		this->w = info.xres_virtual;
		this->h = info.yres_virtual;
		this->pix = info.bits_per_pixel / 8;
#else
		this->w = info.xres;
		this->h = info.yres;
		this->pix = info.bits_per_pixel / 8;
#endif
	}

	//映射
	int ssize = this->w * this->h * this->pix;
	this->mptr = (unsigned int*)mmap(NULL, ssize, PROT_READ | PROT_WRITE, MAP_SHARED, this->fd, 0);
	if (this->mptr == MAP_FAILED)
	{
		perror("map");
	}
}
LcdDevice::~LcdDevice()
{
	if (this->mptr != MAP_FAILED)
	{
		int ssize = this->w * this->h * this->pix;
		munmap(this->mptr, ssize);
	}
	close(this->fd);
}
void LcdDevice::clear(unsigned int color)
{
	for (int i = 0; i < this->w * this->h; i++)
	{
		this->mptr[i] = color;
	}
}
void LcdDevice::drawRect(int x, int y, int w, int h, unsigned int color) {}
void LcdDevice::drawFill(int x, int y, int w, int h, unsigned int color)
{
	unsigned int* p = this->mptr;
	//把指针p移动到要绘制的开始位置
	p = p + x + y * this->w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			p[j] = color;
		}
		p += this->w; //移动到下一行
	}
}
void LcdDevice::drawLine(int x1, int y1, int x2, int y2) {}
void LcdDevice::drawCircle(int x, int y, int r) {}
void LcdDevice::drawRgb(int x, int y, unsigned char* rgb, int w, int h)
{

	unsigned int* p = this->mptr;
	//把指针p移动到要绘制的开始位置
	p = p + x + y * this->w;
	//根据lcd，rgb尺寸和x，y位置计算要绘制图片的宽dw，高dh
	int dw, dh;
	dw = ((x + w) > this->w) ? (this->w - x) : w;
	dh = ((y + h) > this->h) ? (this->h - y) : h;
	//绘制
	for (int i = 0; i < dh; i++)
	{
		for (int j = 0; j < dw; j++)
		{
			//从px开始位置拷贝3字节给到p开始位置,之后p和px 往后偏移j个像素
			unsigned int Rgb = 0;
			Rgb = *(rgb + j * 3 + 3) >> 16 | *(rgb + j * 3 + 2) >> 8 | *(rgb + j * 3 + 1);
			if (Rgb == 255)
				continue;
			//*(mem_p + (start_y + y) * 800 + start_x + x) = tmpbuff[y * width + x];
			memcpy(p + j, rgb + j * 3, 3);
		}
		p += this->w; // lcd绘制指针移动到下一行
		rgb += w * 3; // bmp图片指针移动到下一行
	}
}

void LcdDevice::drawRgb_area(int x, int y, unsigned char* rgb, int w, int h)
{

	unsigned int* p = this->mptr;
	//把指针p移动到要绘制的开始位置
	p = p + x + y * this->w;
	//根据lcd，rgb尺寸和x，y位置计算要绘制图片的宽dw，高dh
	int dw, dh;
	dw = ((x + w) > this->w) ? (this->w - x) : w;
	dh = ((y + h) > this->h) ? (this->h - y) : h;
	rgb = rgb + x * 3 + y * this->w * 3;
	//绘制
	for (int i = 0; i < dh; i++)
	{
		for (int j = 0; j < dw; j++)
		{
			//从px开始位置拷贝3字节给到p开始位置,之后p和px 往后偏移j个像素
			unsigned int Rgb = 0;
			Rgb = *(rgb + j * 3 + 3) >> 16 | *(rgb + j * 3 + 2) >> 8 | *(rgb + j * 3 + 1);
			if (Rgb == 255)
				continue;
			//*(mem_p + (start_y + y) * 800 + start_x + x) = tmpbuff[y * width + x];
			memcpy(p + j, rgb + j * 3, 3);
		}
		p += this->w; // lcd绘制指针移动到下一行
		rgb += this->w * 3; // bmp图片指针移动到下一行
	}
}

void LcdDevice::drawrgb(int x, int y, unsigned int rgb, int w, int h)
{

	unsigned int* p = this->mptr;
	//把指针p移动到要绘制的开始位置
	p = p + x + y * this->w;
	//根据lcd，rgb尺寸和x，y位置计算要绘制图片的宽dw，高dh
	int dw, dh;
	dw = ((x + w) > this->w) ? (this->w - x) : w;
	dh = ((y + h) > this->h) ? (this->h - y) : h;
	//绘制
	for (int i = 0; i < dh; i++)
	{
		for (int j = 0; j < dw; j++)
		{
			//从px开始位置拷贝3字节给到p开始位置,之后p和px 往后偏移j个像素
			// memcpy(p + j, rgb + j , 4);
			p[j] = rgb;
		}
		p += this->w; // lcd绘制指针移动到下一行
		// rgb += w;//bmp图片指针移动到下一行
	}
}

void LcdDevice::getptr(int x, int y, int w, int h)
{
	int dw, dh;
	dw = ((x + w) > this->w) ? (this->w - x) : w;
	dh = ((y + h) > this->h) ? (this->h - y) : h;
	this->cpptr = (unsigned int*)malloc(dw * dh * 4);
	unsigned int* p = this->mptr;
	unsigned int* ptr = this->cpptr;
	//把指针p移动到要绘制的开始位置
	p = p + x + y * this->w;

	//根据lcd，rgb尺寸和x，y位置计算要绘制图片的宽dw，高dh

	//绘制
	//memcpy(this->cpptr, p, dw * dh * 4); 

	for (int i = 0; i < dh; i++)
	{
		for (int j = 0; j < dw; j++)
		{
			//从px开始位置拷贝3字节给到p开始位置,之后p和px 往后偏移j个像素
			memcpy(ptr + j, p + j, 4);
		}
		p += this->w;  // lcd绘制指针移动到下一行
		ptr += dw; // bmp图片指针移动到下一行
	}
}

void LcdDevice::drawptr(int x, int y, int w, int h)
{
	unsigned int* ptr = this->cpptr;
	unsigned int* p = this->mptr;
	//把指针p移动到要绘制的开始位置
	p = p + x + y * this->w;
	//根据lcd，rgb尺寸和x，y位置计算要绘制图片的宽dw，高dh
	int dw, dh;
	/*memcpy(p, this->cpptr, dw * dh * 4);*/
	dw = ((x + w) > this->w) ? (this->w - x) : w;
	dh = ((y + h) > this->h) ? (this->h - y) : h;
	//绘制
	for (int i = 0; i < dh; i++)
	{
		for (int j = 0; j < dw; j++)
		{
			//从px开始位置拷贝3字节给到p开始位置,之后p和px 往后偏移j个像素
			memcpy(p + j, ptr + j, 4);
		}
		p += this->w; // lcd绘制指针移动到下一行
		ptr += dw; // bmp图片指针移动到下一行
	}
	////free(this->cpptr);
}

bool LcdDevice::djyesno(int dj_hq, int* x1, int* y1)
{
	int x = 0, y = 0, n = 0;
	*x1 = 0, * y1 = 0;
	struct input_event zb;
	while (1)
	{
		int ret = read(dj_hq, &zb, sizeof(zb));
		if (ret < 0)
		{
			return false;
		}
		if (zb.type == EV_ABS && zb.code == ABS_X)
		{
			x = zb.value;
		}
		if (zb.type == EV_ABS && zb.code == ABS_Y)
		{
			y = zb.value;
		}
		// if (x > 0 && x < 256 && y > 475 && y < 600)
		// {
		//     return 1;
		// }
		// if (x > 768 && x < 1024 && y < 600 && y > 475)
		// {
		//     return 2;
		// }
		*x1 = x * 800 / 1024;
		*y1 = y * 480 / 600;
		if (x != 0 && y != 0)
		{
			return true;
		}
	}
}

;
