#include "Image.h"

Image::Image() {}
Image::~Image() {}
void Image::zoom(int w, int h) {
    //申请一个保存目标图片的空间
    unsigned char* destmap = (unsigned char *)malloc(w * h * this->pix);
    //计算原图与目标图的宽，高对应的比例
    //double dw = jp->w / (double)w;
    //double dh = jp->h / (double)h;
    //从原图中拷贝数据到目标图中
    for (int i = 0; i < h; i++)
    {
        //拷贝一行
        for (int j = 0; j < w; j++)
        {
            //拷贝一个像素
            destmap[j * 3 + 0 + i * w * 3] = this->data[(j * this->w / w) * 3 + 0 + (i * this->h / h) * this->w * 3];
            destmap[j * 3 + 1 + i * w * 3] = this->data[(j * this->w / w) * 3 + 1 + (i * this->h / h) * this->w * 3];
            destmap[j * 3 + 2 + i * w * 3] = this->data[(j * this->w / w) * 3 + 2 + (i * this->h / h) * this->w * 3];
        }
    }
    this->w = w;
    this->h = h;
    free(this->data);
    this->data = destmap;
}
void Image::reverse() {
    //申请一段空间存储一行像素
    int rowsize = this->w * this->pix;
    unsigned char *tmp = new unsigned char[this->w * this->pix];
    for (int i = 0; i < this->h / 2; i++)
    {
        memcpy(tmp, this->data + i * rowsize, rowsize); //把第一行存储在tmp中
        memcpy(this->data + i * rowsize, this->data + (rowsize) * (this->h - i - 1), rowsize); //把最后一行拷贝到第一行
        memcpy(this->data + (rowsize) * (this->h - i - 1), tmp, rowsize);
    }

    delete[]tmp;
}
unsigned char* Image::getData()const
{
    return this->data;
}

int Image::getw() const { return this->w; }
int Image::geth() const { return this->h; };