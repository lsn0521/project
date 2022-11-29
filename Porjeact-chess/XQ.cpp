#include "XQ.h"

//单例
XQ* XQ::createlcd()
{
    static XQ lcd;
    return &lcd;
}

//清屏
void XQ::clear(unsigned int color) {
    for (int i = 0; i < w * h; i++)
    {
        mptr[i] = color;
    }
}

//棋子初始化
void XQ::qi_initialize() {
	int i, j, p_x, p_y;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (i <= 4)
            {
                kas[i][j].id = 0;
                kas[i][j].dw = 0;
                kas[i][j].qw = 0;
                if (i == 0)
                {
                    if (j <= 4)
                    {
                        kas[i][j].id = j + 1;
                        kas[i][j].color = "黑";
                    }
                    else
                    {
                        kas[i][j].id = 4 - (j - 4) + 1;
                        kas[i][j].color = "黑";
                    }
                }
                if (i == 2)
                {
                    if (j == 1)
                    {
                        kas[i][j].id = 6;
                        kas[i][j].color = "黑";
                    }
                    if (j == 7)
                    {
                        kas[i][j].id = 6;
                        kas[i][j].color = "黑";
                    }
                }
                if (i == 3)
                {
                    if (j == 0)
                    {
                        kas[i][j].id = 7;
                        kas[i][j].color = "黑";
                    }
                    if (j == 2)
                    {
                        kas[i][j].id = 7;
                        kas[i][j].color = "黑";
                    }
                    if (j == 4)
                    {
                        kas[i][j].id = 7;
                        kas[i][j].color = "黑";
                    }
                    if (j == 6)
                    {
                        kas[i][j].id = 7;
                        kas[i][j].color = "黑";
                    }
                    if (j == 8)
                    {
                        kas[i][j].id = 7;
                        kas[i][j].color = "黑";
                    }
                }
            }
            else
            {
                kas[i][j].id = 0;
                kas[i][j].dw = 0;
                kas[i][j].qw = 0;
                if (i == 6)
                {
                    if (j == 0)
                    {
                        kas[i][j].id = 14;
                        kas[i][j].color = "红";
                    }
                    if (j == 2)
                    {
                        kas[i][j].id = 14;
                        kas[i][j].color = "红";
                    }
                    if (j == 4)
                    {
                        kas[i][j].id = 14;
                        kas[i][j].color = "红";
                    }
                    if (j == 6)
                    {
                        kas[i][j].id = 14;
                        kas[i][j].color = "红";
                    }
                    if (j == 8)
                    {
                        kas[i][j].id = 14;
                        kas[i][j].color = "红";
                    }
                }
                if (i == 7)
                {
                    if (j == 1)
                    {
                        kas[i][j].id = 13;
                        kas[i][j].color = "红";
                    }
                    if (j == 7)
                    {
                        kas[i][j].id = 13;
                        kas[i][j].color = "红";
                    }
                }
				if (i == 9)
				{
					if (j <= 4)
					{
						kas[i][j].id = j + 8;
						kas[i][j].color = "红";
					}
					else
					{

						kas[i][j].id = 16 - j;
						kas[i][j].color = "红";
					}
				}
            }
        }
    }
	p_y = 2;
	for (i = 0; i < 10; i++)
	{
		p_x = 193;
		for (j = 0; j < 9; j++)
		{
			kas[i][j].x = p_x;
			kas[i][j].y = p_y;
			p_x = p_x + 47;
		}
		p_y = p_y + 47;
	}
}

//逻辑算法
int XQ::algorithm(int i, int j, int q, int w)
{
	int q_i = 0;
	int num = 0;
	switch (kas[i][j].id)
	{
		//黑车
	case 1:
		//前进
		if ((q > i) && (w == j))
		{
			for (q_i = i + 1; q_i < q; q_i++)
			{
				if (kas[q_i][j].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		//后退
		else if ((q < i) && (w == j))
		{
			for (q_i = i - 1; q_i > q; q_i--)
			{
				if (kas[q_i][j].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		//右
		else if ((q == i) && (w > j))
		{
			for (q_i = j + 1; q_i < w; q_i++)
			{
				if (kas[i][q_i].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		//左
		else if ((q == i) && (w < j))
		{
			for (q_i = j - 1; q_i > w; q_i--)
			{
				if (kas[i][q_i].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		else
		{
			return 0;
		}

		//红车
	case 8:
		//前进
		if ((q > i) && (w == j))
		{
			for (q_i = i + 1; q_i < q; q_i++)
			{
				if (kas[q_i][j].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		//后退
		else if ((q < i) && (w == j))
		{
			for (q_i = i - 1; q_i > q; q_i--)
			{
				if (kas[q_i][j].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		//右
		else if ((q == i) && (w > j))
		{
			for (q_i = j + 1; q_i < w; q_i++)
			{
				if (kas[i][q_i].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		//左
		else if ((q == i) && (w < j))
		{
			for (q_i = j - 1; q_i > w; q_i--)
			{
				if (kas[i][q_i].id > 0)
				{
					return 0;
				}
			}
			return 1;
		}
		else
		{
			return 0;
		}

		//黑马
	case 2:
		if ((q != i) && (w != j))
		{
			//前进-右
			if ((i + 2) == q && (j + 1) == w && kas[i + 1][j].id == 0)
			{
				return 1;
			}
			//前进-左
			else if ((i + 2) == q && (j - 1) == w && kas[i + 1][j].id == 0)
			{
				return 1;
			}
			//后退-右
			else if ((i - 2) == q && (j + 1) == w && kas[i - 1][j].id == 0)
			{
				return 1;
			}
			//后退-左
			else if ((i - 2) == q && (j - 1) == w && kas[i - 1][j].id == 0)
			{
				return 1;
			}
			//右-前
			else if ((i + 1) == q && (j + 2) == w && kas[i][j + 1].id == 0)
			{
				return 1;
			}
			//右-后
			else if ((i - 1) == q && (j + 2) == w && kas[i][j + 1].id == 0)
			{
				return 1;
			}
			//左-前
			else if ((i + 1) == q && (j - 2) == w && kas[i][j - 1].id == 0)
			{
				return 1;
			}
			//左-后
			else if ((i - 1) == q && (j - 2) == w && kas[i][j - 1].id == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//红马
	case 9:
		if ((q != i) && (w != j))
		{
			//前进-右
			if ((i - 2) == q && (j + 1) == w && kas[i - 1][j].id == 0)
			{
				return 1;
			}
			//前进-左
			else if ((i - 2) == q && (j - 1) == w && kas[i - 1][j].id == 0)
			{
				return 1;
			}
			//后退-右
			else if ((i + 2) == q && (j + 1) == w && kas[i + 1][j].id == 0)
			{
				return 1;
			}
			//后退-左
			else if ((i + 2) == q && (j - 1) == w && kas[i + 1][j].id == 0)
			{
				return 1;
			}
			//右-前
			else if ((i - 1) == q && (j + 2) == w && kas[i][j - 1].id == 0)
			{
				return 1;
			}
			//右-后
			else if ((i + 1) == q && (j + 2) == w && kas[i][j - 1].id == 0)
			{
				return 1;
			}
			//左-前
			else if ((i - 1) == q && (j - 2) == w && kas[i][j + 1].id == 0)
			{
				return 1;
			}
			//左-后
			else if ((i + 1) == q && (j - 2) == w && kas[i][j + 1].id == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//黑相
	case 3:
		if (q <= 4)
		{
			if ((q != i) && (w != j))
			{
				//前进-右
				if ((i + 2) == q && (j + 2) == w && kas[i + 1][j + 1].id == 0)
				{
					return 1;
				}
				//前进-左
				else if ((i + 2) == q && (j - 2) == w && kas[i + 1][j - 1].id == 0)
				{
					return 1;
				}
				//后退-右
				else if ((i - 2) == q && (j + 2) == w && kas[i - 1][j + 1].id == 0)
				{
					return 1;
				}
				//后退-左
				else if ((i - 2) == q && (j - 2) == w && kas[i - 1][j - 1].id == 0)
				{
					return 1;
				}
				//右-前
				else if ((i + 2) == q && (j + 2) == w && kas[i + 1][j + 1].id == 0)
				{
					return 1;
				}
				//右-后
				else if ((i - 2) == q && (j + 2) == w && kas[i - 1][j + 1].id == 0)
				{
					return 1;
				}
				//左-前
				else if ((i + 2) == q && (j - 2) == w && kas[i + 1][j - 1].id == 0)
				{
					return 1;
				}
				//左-后
				else if ((i - 2) == q && (j - 2) == w && kas[i - 1][j - 1].id == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//红相
	case 10:
		if (q > 4)
		{
			if ((q != i) && (w != j))
			{
				//前进-右
				if ((i - 2) == q && (j + 2) == w && kas[i - 1][j + 1].id == 0)
				{
					return 1;
				}
				//前进-左
				else if ((i - 2) == q && (j - 2) == w && kas[i - 1][j - 1].id == 0)
				{
					return 1;
				}
				//后退-右
				else if ((i + 2) == q && (j + 2) == w && kas[i + 1][j + 1].id == 0)
				{
					return 1;
				}
				//后退-左
				else if ((i + 2) == q && (j - 2) == w && kas[i + 1][j - 1].id == 0)
				{
					return 1;
				}
				//右-前
				else if ((i - 2) == q && (j + 2) == w && kas[i - 1][j + 1].id == 0)
				{
					return 1;
				}
				//右-后
				else if ((i + 2) == q && (j + 2) == w && kas[i + 1][j + 1].id == 0)
				{
					return 1;
				}
				//左-前
				else if ((i - 2) == q && (j - 2) == w && kas[i - 1][j - 1].id == 0)
				{
					return 1;
				}
				//左-后
				else if ((i + 2) == q && (j - 2) == w && kas[i + 1][j - 1].id == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//黑士
	case 4:
		if (q <= 2 && w > 2 && w < 6)
		{
			if ((q != i) && (w != j))
			{
				//前进-右
				if ((i + 1) == q && (j + 1) == w)
				{
					return 1;
				}
				//前进-左
				else if ((i + 1) == q && (j - 1) == w)
				{
					return 1;
				}
				//后退-右
				else if ((i - 1) == q && (j + 1) == w)
				{
					return 1;
				}
				//后退-左
				else if ((i - 1) == q && (j - 1) == w)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
		//红士
	case 11:
		if (q >= 7 && w > 2 && w < 6)
		{
			if ((q != i) && (w != j))
			{
				//前进-右
				if ((i - 1) == q && (j + 1) == w)
				{
					return 1;
				}
				//前进-左
				else if ((i - 1) == q && (j - 1) == w)
				{
					return 1;
				}
				//后退-右
				else if ((i + 1) == q && (j + 1) == w)
				{
					return 1;
				}
				//后退-左
				else if ((i + 1) == q && (j - 1) == w)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//黑将
	case 5:
		if (q <= 2 && w > 2 && w < 6)
		{
			//前进
			if ((q > i) && (w == j) && (q - i) <= 1)
			{
				return 1;
			}
			//后退
			if ((q < i) && (w == j) && (i - q) <= 1)
			{
				return 1;
			}
			//右
			else if ((q == i) && (w > j) && (w - j) <= 1)
			{
				return 1;
			}
			//左
			else if ((q == i) && (w < j) && (j - w) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//红将
	case 12:
		if (q >= 7 && w > 2 && w < 6)
		{
			//前进
			if ((q < i) && (w == j) && (i - q) <= 1)
			{
				return 1;
			}
			//后退
			if ((q > i) && (w == j) && (q - i) <= 1)
			{
				return 1;
			}
			//右
			else if ((q == i) && (w > j) && (w - j) <= 1)
			{
				return 1;
			}
			//左
			else if ((q == i) && (w < j) && (j - w) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//黑炮
	case 6:
		num = 0;
		//前进
		if (q > i && w == j)
		{
			for (q_i = i + 1; q_i < q; q_i++)
			{
				if (kas[q_i][j].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		//后退
		else if (q < i&& w == j)
		{
			for (q_i = i - 1; q_i > q; q_i--)
			{
				if (kas[q_i][j].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		//右
		else if (q == i && w > j)
		{
			for (q_i = j + 1; q_i < w; q_i++)
			{
				if (kas[i][q_i].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		//左
		else if (q == i && w < j)
		{
			for (q_i = j - 1; q_i > w; q_i--)
			{
				if (kas[i][q_i].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//红炮
	case 13:
		num = 0;
		//后退
		if (q > i && w == j)
		{
			for (q_i = i + 1; q_i < q; q_i++)
			{
				if (kas[q_i][j].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		//前进
		else if (q < i&& w == j)
		{
			for (q_i = i - 1; q_i > q; q_i--)
			{
				if (kas[q_i][j].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		//右
		else if (q == i && w > j)
		{
			for (q_i = j + 1; q_i < w; q_i++)
			{
				if (kas[i][q_i].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		//左
		else if (q == i && w < j)
		{
			for (q_i = j - 1; q_i > w; q_i--)
			{
				if (kas[i][q_i].id > 0)
				{
					num++;
				}
			}
			if (num == 0)
			{
				return 2;
			}
			if (num == 1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		//黑兵
	case 7:
		if (i <= 4)
		{
			//前进
			if ((q > i) && (w == j) && (q - i) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (i > 4)
		{
			//前进
			if ((q > i) && (w == j) && (q - i) <= 1)
			{
				return 1;
			}
			//右
			else if ((q == i) && (w > j) && (w - j) <= 1)
			{
				return 1;
			}
			//左
			else if ((q == i) && (w < j) && (j - w) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		//红兵
	case 14:
		if (i > 4)
		{
			if ((q < i) && (w == j) && (i - q) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (i <= 4)
		{
			//前进
			if ((q < i) && (w == j) && (i - q) <= 1)
			{
				return 1;
			}
			//右
			else if ((q == i) && (w > j) && (w - j) <= 1)
			{
				return 1;
			}
			//左
			else if ((q == i) && (w < j) && (j - w) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

//构造函数
XQ::XQ(const char* dev)
{
	n = 0;
	n_1 = 0;
    //1.打开设备
    this->fd = ::open(dev, O_RDWR);
    if (this->fd < 0)
    {
        perror("open");
    }

    int ret = ioctl(this->fd, FBIOGET_VSCREENINFO, &vinfo);
    if (ret < 0)
    {
        perror("ioctl");
        w = 800;
        h = 480;
        pix = 4;
    }
    else
    {
        w = vinfo.xres;
        h = vinfo.yres;
        pix = vinfo.bits_per_pixel / 8;
    }

    //3.映射
    int ssize = w * h * pix;
    mptr = (unsigned int*)mmap(NULL,ssize*2, PROT_READ | PROT_WRITE, MAP_SHARED, this->fd, 0);
    if (mptr == MAP_FAILED)
    {
        perror("map");
    }

}

//析构函数
XQ::~XQ() {
    if (mptr != MAP_FAILED)
    {
        int ssize = w * h * pix * 2;
        munmap(mptr, ssize);
    }
    ::close(this->fd);
}

//打开
void XQ::is_open(void)
{
	//1.打开设备
	this->fd = ::open("/dev/fb0", O_RDWR);
	if (this->fd < 0)
	{
		perror("open");
	}

	//3.映射
	int ssize = w * h * pix;
	mptr = (unsigned int*)mmap(NULL, ssize * 2, PROT_READ | PROT_WRITE, MAP_SHARED, this->fd, 0);
	if (mptr == MAP_FAILED)
	{
		perror("map");
	}
}

//设置可见区
void XQ::keshiqu(void)
{
	// 将可见区设定为A区
	vinfo.xoffset = 0;
	vinfo.yoffset = 480 * (n % 2);
	ioctl(fd, FBIOPAN_DISPLAY, &vinfo);
}

//映射图片
int XQ::show_bmp(const char* pathname, int start_x, int start_y)
{
    int width, high; //图片亮度与高度
    int i, j, x, y;
    // 读取BMP格式头，获取图片信息
    struct bitmap_header header;
    struct bitmap_info info;
    struct rgb_quad quad;

    //打开图片
    int bmp_fd = open(pathname, O_RDONLY);
    if (bmp_fd == -1)
    {
        printf("open bmp fail\n");
        return -1;
    }
    // 第一、二个结构体是必有信息
    read(bmp_fd, &header, sizeof(header));
    read(bmp_fd, &info, sizeof(info));

    width = info.width;
    high = info.height;

    if (start_x + width > 800 || start_y + high > 480)
    {
        printf("图片显示溢出！\n");
        close(bmp_fd);
        return -1;
    }

    //变长数组
    unsigned char bmpbuff[width * high * 3];
    unsigned int buff[width * high];
    unsigned int tmpbuff[width * high];

    read(bmp_fd, bmpbuff, sizeof(bmpbuff));

    //图片像素点移动
    for (i = 0; i < width * high; i++)
    {
        buff[i] = bmpbuff[3 * i + 0] | bmpbuff[3 * i + 1] << 8 | bmpbuff[3 * i + 2] << 16;
    }

    //图片像素点倒置
    for (y = 0; y < high; y++)
    {
        for (x = 0; x < width; x++)
        {
            tmpbuff[(high - 1 - y) * width + x] = buff[y * width + x];
        }
    }

    //图片像素显示
    for (y = 0; y < high; y++)
    {
        for (x = 0; x < width; x++)
        {
			//遇到白色就跳过，不绘画
            if (tmpbuff[y * width + x] == 0x00ffffff)
            {
                continue;
            }
			*(mptr + ((start_y + y) * 800) + (480 * 800) * (n_1 % 2) + start_x + x) = tmpbuff[y * width + x];

        }
    }

    //关闭LCD文件
    close(bmp_fd);
    return 0;
}

//触摸屏
void XQ::paddle_ts(void)
{
    int x = 0, y = 0, xx = 0, yy = 0;
    struct input_event ts;

    ts_fd = open("/dev/input/event0", O_RDWR);

    memset(&ts, 0, sizeof(struct input_event));
    while (1)
    {
        //读触摸屏
        read(ts_fd, &ts, sizeof(struct input_event));

        in = 0;

        //决断是否为相对坐标类型
        if (ts.type == EV_ABS && ts.code == ABS_X)
        {

            x = ts.value;
        }
        //决断是否为相对坐标类型
        if (ts.type == EV_ABS && ts.code == ABS_Y)
        {

            y = ts.value;
        }
        //表示手指按下
        if (ts.type == EV_KEY && ts.code == BTN_TOUCH && ts.value == 1)
        {
            //记录起点坐标
            xx = x;
            yy = y;
        }

        //表示手指松开
        if (ts.type == EV_KEY && ts.code == BTN_TOUCH && ts.value == 0)
        {
            //坐标换算  起点坐标
            xx = xx * (800.0 / 1024.0);
            yy = yy * (480.0 / 600.0);
            //坐标换算  结束坐标
            x = x * (800.0 / 1024.0);
            y = y * (480.0 / 600.0);

            num[0] = xx;
            num[1] = yy;
            num[2] = x;
            num[3] = y;

            in = 1;

           printf("%d  %d\n", num[0], num[1]);
		   close(ts_fd);
           return;
        }
    }
}

//进度条
void XQ::photo_load(void)
{
    int x, y;

    for (y = 450; y < 465; y++)
    {
        for (x = 50; x < 750; x++)
        {
            mptr[y * 800 + x] = 0x007f7f7f;
        }
    }

    for (x = 50; x < 750; x++)
    {
        for (y = 450; y < 465; y++)
        {
            mptr[y * 800+(480*800*(n%2)) + x] = 0x003300FF;
        }
        usleep(400);
    }
}
