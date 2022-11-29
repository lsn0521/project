#include "Bmp.h"
#include<cstdio>
#include <cstring>
Bmp::Bmp(string filename) {
	//打开bmpfile文件
	FILE* file = fopen(filename.c_str(), "r");
	if (file == NULL)
	{
		perror("fopen");
	}
	//读取bmp头
	size_t size = fread(&this->header, 1, 54, file);
	if (size < 0)
	{
		fclose(file);
	}

	//计算像素占用的内存空间大小
	this->w = this->header.biWidth;
	this->h = this->header.biHeight;
	this->pix = this->header.biBitCount / 8;
	unsigned int rgbsize = this->w * this->h * this->pix;

	//申请保存像素数据的空间
	this->data = (unsigned char*)malloc(rgbsize);

	//定义填充的字节数
	int pad = (this->w * this->pix % 4) ? (4 - (this->w * this->pix % 4)) : 0;

	//定义保存一行像素空间(包括填充空间)
	int rowsize = this->w * this->pix + pad;
	unsigned char* tmp = new  unsigned char[rowsize];

	//循环读取，一次读取一行
	for (int i = 0; i < this->h; i++)
	{
		//读取一行像素值（在bmp文件中一行像素占用的字节数是4的倍数）
		fread(tmp, 1, rowsize, file);
		memcpy(this->data + i * this->w * this->pix, tmp, this->w * this->pix);//拷贝的时候把填充部分去掉
	}
	delete[]tmp;
	//返回
	fclose(file);
}
Bmp::~Bmp() {
	free(this->data);
}
void Bmp::save(string name) {

	//计算图像一行数据占用的字节数
	int rowsize = this->pix * this->w;
	if (rowsize % 4 != 0)
	{
		rowsize += 4 - rowsize % 4;
	}

	//计算imagesize
	int imagesize = rowsize * this->h;
	this->header.biSizeImage = imagesize;//初始化头像素大小
	this->header.bfSize = imagesize + 54;//初始化文件大小
	this->header.biHeight = this->h;
	this->header.biWidth = this->w;
	this->header.biBitCount = this->pix * 8;

	//打开文件
	FILE* file = fopen(name.c_str(), "w");
	if (file == NULL)
	{
		perror("save");
		return;
	}

	//写文件头
	fwrite(&this->header, 1, 54, file);
	//写rgb数据
	for (int i = 0; i < this->h; i++)
	{
		//写一行像素到文件（包括补齐的字节数）
		fwrite(this->data + i * this->w * this->pix, 1, rowsize, file);
	}

	//关闭文件
	fclose(file);
}

int Bmp::getw() const { return this->w; }
int Bmp::geth() const { return this->h; }
