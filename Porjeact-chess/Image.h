#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Image {
public:
    Image();
    virtual ~Image();
    virtual void zoom(int w, int h);//虚函数
    virtual void save(string name)=0;//纯虚函数
    virtual void reverse();
    unsigned char* getData()const;
    int getw()const;
    int geth()const;
protected:
    int w, h, pix; //保存宽高，一个像素占用的字节数
    unsigned char* data; //保存rgb数据
};

