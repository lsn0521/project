#include "Chess.h"
#include <iostream>

using namespace std;

Chess::Chess() {
	send_save_sub_x = -1, send_save_sub_y = -1, send_that_sub_x = -1, send_that_sub_y = -1, recv_save_sub_x = -1, recv_save_sub_y = -1, recv_that_sub_x = -1, recv_that_sub_y = -1;
	for (int i = 0; i < 4; i++)
	{
		savestr[0][i].id == -1;
	}
};
Chess::~Chess() {};

void Chess::getsub(int x, int y, int* sub_x, int* sub_y)
{
	int  _x = 0, _y = 0;
	for (int i = 2; i <= 425 + 47; i += 47)
	{
		for (int j = 193; j < 569 + 47; j += 47)
		{
			if (x >= j && x < j + 47 && y >= i && y < i + 47)
			{
				*sub_x = _x;
				*sub_y = _y;

			};
			_y++;
		}
		_y = 0;
		_x++;
	}
}

void Chess::transub()
{
	this->recv_save_sub_x = 9 - this->recv_save_sub_x;
	this->recv_save_sub_y = 8 - this->recv_save_sub_y;
	this->recv_that_sub_x = 9 - this->recv_that_sub_x;
	this->recv_that_sub_y = 8 - this->recv_that_sub_y;
};

void Chess::show_send_data(string isfirst)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp bmp_back("./checkerboard.bmp"); bmp_back.reverse();
	Bmp bmp_send_end(this->str[this->send_that_sub_x][this->send_that_sub_y].bmp); bmp_send_end.reverse();
	Bmp bmp_on("./parts/pitch_on.bmp"); bmp_on.reverse();
	Bmp bmp_off("./parts/pitch_off.bmp"); bmp_off.reverse();
	cout << "send_save_sub_x " << send_save_sub_x << " send_save_sub_y=" << send_save_sub_y << " send_that_sub_x=" << send_that_sub_x << " send_that_sub_y=" << send_that_sub_y << endl;
	if (isfirst == "yes")
	{
		lcd->drawRgb_area(this->str[send_save_sub_x][send_save_sub_y].x - 24, this->str[send_save_sub_x][send_save_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb(this->str[send_save_sub_x][send_save_sub_y].x - 24, this->str[send_save_sub_x][send_save_sub_y].y - 24, bmp_off.getData(), 48, 48);
		lcd->drawRgb(this->str[send_that_sub_x][send_that_sub_y].x - 24, this->str[send_that_sub_x][send_that_sub_y].y - 24, bmp_send_end.getData(), 48, 48);
		lcd->drawRgb(this->str[send_that_sub_x][send_that_sub_y].x - 24, this->str[send_that_sub_x][send_that_sub_y].y - 24, bmp_on.getData(), 48, 48);
	}
	else
	{
		Bmp	bmp_recv_end(this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp); bmp_recv_end.reverse();
		cout << "bmp_send=" << this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp << endl;
		lcd->drawRgb_area(this->str[recv_save_sub_x][this->recv_save_sub_y].x - 24, this->str[recv_save_sub_x][this->recv_save_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb_area(this->str[recv_that_sub_x][this->recv_that_sub_y].x - 24, this->str[recv_that_sub_x][this->recv_that_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_that_sub_x][this->recv_that_sub_y].x - 24, this->str[recv_that_sub_x][this->recv_that_sub_y].y - 24, bmp_recv_end.getData(), 48, 48);

		lcd->drawRgb_area(this->str[send_save_sub_x][send_save_sub_y].x - 24, this->str[send_save_sub_x][send_save_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb(this->str[send_save_sub_x][send_save_sub_y].x - 24, this->str[send_save_sub_x][send_save_sub_y].y - 24, bmp_off.getData(), 48, 48);
		lcd->drawRgb(this->str[send_that_sub_x][send_that_sub_y].x - 24, this->str[send_that_sub_x][send_that_sub_y].y - 24, bmp_send_end.getData(), 48, 48);
		lcd->drawRgb(this->str[send_that_sub_x][send_that_sub_y].x - 24, this->str[send_that_sub_x][send_that_sub_y].y - 24, bmp_on.getData(), 48, 48);
	}
}
void Chess::show_recv_data(string isfirst)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp bmp_back("./checkerboard.bmp"); bmp_back.reverse();
	Bmp bmp_on("./parts/pitch_on.bmp"); bmp_on.reverse();
	Bmp bmp_off("./parts/pitch_off.bmp"); bmp_off.reverse();
	cout << "recv_save_sub_x " << recv_save_sub_x << " send_save_sub_y=" << recv_save_sub_y << " send_that_sub_x=" << recv_that_sub_x << " send_that_sub_y=" << recv_that_sub_y << endl;
	Bmp bmp_revc_end(this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp); bmp_revc_end.reverse();
	cout << " bmp_revc=" << this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp << endl;
	if (isfirst == "yes")
	{
		lcd->drawRgb_area(this->str[recv_save_sub_x][this->recv_save_sub_y].x - 24, this->str[recv_save_sub_x][this->recv_save_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_save_sub_x][this->recv_save_sub_y].x - 24, this->str[recv_save_sub_x][this->recv_save_sub_y].y - 24, bmp_off.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_that_sub_x][this->recv_that_sub_y].x - 24, this->str[recv_that_sub_x][this->recv_that_sub_y].y - 24, bmp_revc_end.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_that_sub_x][this->recv_that_sub_y].x - 24, this->str[recv_that_sub_x][this->recv_that_sub_y].y - 24, bmp_on.getData(), 48, 48);
	}
	else
	{
		Bmp	bmp_send_end(this->str[this->send_that_sub_x][this->send_that_sub_y].bmp); bmp_send_end.reverse();
		cout << "bmp_send=" << this->str[this->send_that_sub_x][this->send_that_sub_y].bmp << endl;
		lcd->drawRgb_area(this->str[send_save_sub_x][this->send_save_sub_y].x - 24, this->str[send_save_sub_x][this->send_save_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb_area(this->str[send_that_sub_x][this->send_that_sub_y].x - 24, this->str[send_that_sub_x][this->send_that_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb(this->str[send_that_sub_x][this->send_that_sub_y].x - 24, this->str[send_that_sub_x][this->send_that_sub_y].y - 24, bmp_send_end.getData(), 48, 48);

		lcd->drawRgb_area(this->str[recv_save_sub_x][this->recv_save_sub_y].x - 24, this->str[recv_save_sub_x][this->recv_save_sub_y].y - 24, bmp_back.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_save_sub_x][this->recv_save_sub_y].x - 24, this->str[recv_save_sub_x][this->recv_save_sub_y].y - 24, bmp_off.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_that_sub_x][this->recv_that_sub_y].x - 24, this->str[recv_that_sub_x][this->recv_that_sub_y].y - 24, bmp_revc_end.getData(), 48, 48);
		lcd->drawRgb(this->str[recv_that_sub_x][this->recv_that_sub_y].x - 24, this->str[recv_that_sub_x][this->recv_that_sub_y].y - 24, bmp_on.getData(), 48, 48);
	}
}

void Chess::show_savedata()
{
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp back_bmp("./checkerboard.bmp");
	back_bmp.reverse();
	for (int i = 0; i < 4; i++)
	{
		cout << " bmp=" << this->savestr[0][i].bmp << " id=" << this->savestr[0][i].id << " color=" << this->savestr[0][i].color << endl;
		if (this->savestr[0][i].id == -1)
		{
			lcd->drawRgb_area(this->savestr[0][i].x - 24, this->savestr[0][i].y - 24, back_bmp.getData(), 48, 48);
		}
		else
		{
			lcd->drawRgb_area(this->savestr[0][i].x - 24, this->savestr[0][i].y - 24, back_bmp.getData(), 48, 48);
			Bmp bmp(this->savestr[0][i].bmp);
			bmp.reverse();
			lcd->drawRgb(this->savestr[0][i].x - 24, this->savestr[0][i].y - 24, bmp.getData(), 48, 48);
		}
	}
	this->str[this->send_save_sub_x][this->send_save_sub_y].bmp = this->savestr[0][0].bmp;
	this->str[this->send_save_sub_x][this->send_save_sub_y].id = this->savestr[0][0].id;
	this->str[this->send_save_sub_x][this->send_save_sub_y].color = this->savestr[0][0].color;
	this->str[this->send_save_sub_x][this->send_save_sub_y].x = this->savestr[0][0].x;
	this->str[this->send_save_sub_x][this->send_save_sub_y].y = this->savestr[0][0].y;

	this->str[this->send_that_sub_x][this->send_that_sub_y].bmp = this->savestr[0][1].bmp;
	this->str[this->send_that_sub_x][this->send_that_sub_y].id = this->savestr[0][1].id;
	this->str[this->send_that_sub_x][this->send_that_sub_y].color = this->savestr[0][1].color;
	this->str[this->send_that_sub_x][this->send_that_sub_y].x = this->savestr[0][1].x;
	this->str[this->send_that_sub_x][this->send_that_sub_y].y = this->savestr[0][1].y;

	this->str[this->recv_save_sub_x][this->recv_save_sub_y].bmp = this->savestr[0][2].bmp;
	this->str[this->recv_save_sub_x][this->recv_save_sub_y].id = this->savestr[0][2].id;
	this->str[this->recv_save_sub_x][this->recv_save_sub_y].color = this->savestr[0][2].color;
	this->str[this->recv_save_sub_x][this->recv_save_sub_y].x = this->savestr[0][2].x;
	this->str[this->recv_save_sub_x][this->recv_save_sub_y].y = this->savestr[0][2].y;

	this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp = this->savestr[0][3].bmp;
	this->str[this->recv_that_sub_x][this->recv_that_sub_y].id = this->savestr[0][3].id;
	this->str[this->recv_that_sub_x][this->recv_that_sub_y].color = this->savestr[0][3].color;
	this->str[this->recv_that_sub_x][this->recv_that_sub_y].x = this->savestr[0][3].x;
	this->str[this->recv_that_sub_x][this->recv_that_sub_y].y = this->savestr[0][3].y;
}

void Chess::setdata_r(string txt)
{

	ifstream in(txt.c_str(), std::ios::in);
	char ch[32] = { 0 };
	char data[32] = { 0 };
	int x, y;
	int id;
	in >> ch;
	while (!in.eof())
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> ch;
				sscanf(ch, "%d,%d,%[^,],%d", &x, &y, data, &id);
				string b = data;
				str[i][j].color = "black";
				str[i][j].id = id;
				str[i][j].x = x;
				str[i][j].y = y;
				str[i][j].bmp = "./Rpieces/B" + b;
			}
		}
		for (int i = 5; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> ch;
				sscanf(ch, "%d,%d,%[^,],%d", &x, &y, data, &id);
				string b = data;
				str[i][j].color = "red";
				str[i][j].id = id;
				str[i][j].x = x;
				str[i][j].y = y;
				str[i][j].bmp = "./Fpieces/R" + b;
			}
		}

	}
}

void Chess::setdata_b(string txt)
{

	ifstream in(txt.c_str(), std::ios::in);
	char ch[32] = { 0 };
	char data[32] = { 0 };
	int x, y;
	int id;
	in >> ch;
	while (!in.eof())
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> ch;
				sscanf(ch, "%d,%d,%[^,],%d", &x, &y, data, &id);
				string b = data;
				str[i][j].color = "red";
				str[i][j].id = id;
				str[i][j].x = x;
				str[i][j].y = y;
				str[i][j].bmp = "./Rpieces/R" + b;
			}
		}
		for (int i = 5; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> ch;
				sscanf(ch, "%d,%d,%[^,],%d", &x, &y, data, &id);
				string b = data;
				str[i][j].color = "black";
				str[i][j].id = id;
				str[i][j].x = x;
				str[i][j].y = y;
				str[i][j].bmp = "./Fpieces/B" + b;
			}
		}

	}
}

void Chess::savedata(int sub_x1, int sub_y1, int sub_x2, int sub_y2, string is_save)
{
	if (is_save == "save")
	{
		this->send_save_sub_x = sub_x1;
		this->send_save_sub_y = sub_y1;
		this->send_that_sub_x = sub_x2;
		this->send_that_sub_y = sub_y2;

		cout << this->send_save_sub_x << " " << this->send_save_sub_y << " " << this->send_that_sub_x << " " << this->send_that_sub_y << endl;
		this->savestr[0][0].color = this->str[sub_x1][sub_y1].color;
		this->savestr[0][0].id = this->str[sub_x1][sub_y1].id;
		this->savestr[0][0].x = this->str[sub_x1][sub_y1].x;
		this->savestr[0][0].y = this->str[sub_x1][sub_y1].y;
		this->savestr[0][0].bmp = this->str[sub_x1][sub_y1].bmp;

		this->savestr[0][1].color = this->str[sub_x2][sub_y2].color;
		this->savestr[0][1].id = this->str[sub_x2][sub_y2].id;
		this->savestr[0][1].x = this->str[sub_x2][sub_y2].x;
		this->savestr[0][1].y = this->str[sub_x2][sub_y2].y;
		this->savestr[0][1].bmp = this->str[sub_x2][sub_y2].bmp;

		str[sub_x2][sub_y2].color = str[sub_x1][sub_y1].color;
		str[sub_x2][sub_y2].bmp = str[sub_x1][sub_y1].bmp;
		str[sub_x2][sub_y2].id = str[sub_x1][sub_y1].id;
		str[sub_x1][sub_y1].id = -1;

		if (this->savestr[0][1].id == this->savestr[0][0].id && this->savestr[0][1].id != 5)
		{
			this->savestr[0][1].id = -1;
		}

	}
	else
	{
		this->recv_save_sub_x = sub_x1;
		this->recv_save_sub_y = sub_y1;
		this->recv_that_sub_x = sub_x2;
		this->recv_that_sub_y = sub_y2;
		this->transub();
		cout << this->recv_save_sub_x << " " << this->recv_save_sub_y << " " << this->recv_that_sub_x << " " << this->recv_that_sub_y << endl;
		this->savestr[0][2].color = this->str[this->recv_save_sub_x][this->recv_save_sub_y].color;
		this->savestr[0][2].id = this->str[this->recv_save_sub_x][this->recv_save_sub_y].id;
		this->savestr[0][2].x = this->str[this->recv_save_sub_x][this->recv_save_sub_y].x;
		this->savestr[0][2].y = this->str[this->recv_save_sub_x][this->recv_save_sub_y].y;
		this->savestr[0][2].bmp = this->str[this->recv_save_sub_x][this->recv_save_sub_y].bmp;
		cout << this->savestr[0][2].color << " " << this->savestr[0][2].id << " " << this->savestr[0][2].bmp << endl;


		this->savestr[0][3].color = this->str[this->recv_that_sub_x][this->recv_that_sub_y].color;
		this->savestr[0][3].id = this->str[this->recv_that_sub_x][this->recv_that_sub_y].id;
		this->savestr[0][3].x = this->str[this->recv_that_sub_x][this->recv_that_sub_y].x;
		this->savestr[0][3].y = this->str[this->recv_that_sub_x][this->recv_that_sub_y].y;
		this->savestr[0][3].bmp = this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp;
		cout << this->savestr[0][3].color << " " << this->savestr[0][3].id << " " << this->savestr[0][3].bmp << endl;

		if (this->savestr[0][2].id == this->savestr[0][3].id && this->savestr[0][2].id != 5)
		{
			this->savestr[0][3].id = -1;
		}

		this->str[this->recv_save_sub_x][this->recv_save_sub_y].color = this->savestr[0][3].color;
		this->str[this->recv_save_sub_x][this->recv_save_sub_y].id = -1;
		//this->str[this->recv_save_sub_x][this->recv_save_sub_y].x = this->savestr[0][2].x;
		//this->str[this->recv_save_sub_x][this->recv_save_sub_y].y = this->savestr[0][2].y;
		this->str[this->recv_save_sub_x][this->recv_save_sub_y].bmp = this->savestr[0][3].bmp;

		cout << "3" << endl;
		this->str[this->recv_that_sub_x][this->recv_that_sub_y].color = this->savestr[0][2].color;
		this->str[this->recv_that_sub_x][this->recv_that_sub_y].id = this->savestr[0][2].id;
		/*	this->str[this->recv_that_sub_x][this->recv_that_sub_y].x = this->savestr[0][3].x;
			this->str[this->recv_that_sub_x][this->recv_that_sub_y].y = this->savestr[0][3].y;*/
		this->str[this->recv_that_sub_x][this->recv_that_sub_y].bmp = this->savestr[0][2].bmp;



	}
}

void Chess::showData()
{
	LcdDevice* lcd = LcdDevice::getLcd();
	/*Bmp bmp_1("./checkerboard.bmp");
	this->drawRgb(0, 0, bmp_1.getData(), 800, 480);*/
	int x = 0, y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (str[i][j].id != -1)
			{
				string mp = str[i][j].bmp;
				x = str[i][j].x - 24;
				y = str[i][j].y - 24;
				Bmp bmp(mp);
				bmp.reverse();
				lcd->drawRgb(x, y, bmp.getData(), 48, 48);
			}
			/*else
			{
				x = str[i][j].x - 24;
				y = str[i][j].y - 24;
				Bmp bmp("./checkerboard.bmp");
				bmp.reverse();
				lcd->drawRgb_area(str[i][j].x - 24, str[i][j].y - 24, bmp.getData(), 48, 48);
			}*/
		}
	}
}

void Chess::showData_all()
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x = 0, y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (str[i][j].id != -1)
			{
				string mp = str[i][j].bmp;
				x = str[i][j].x - 24;
				y = str[i][j].y - 24;
				Bmp bmp(mp);
				bmp.reverse();
				lcd->drawRgb(x, y, bmp.getData(), 48, 48);
			}
			else
			{
				x = str[i][j].x - 24;
				y = str[i][j].y - 24;
				Bmp bmp("./checkerboard.bmp");
				bmp.reverse();
				lcd->drawRgb_area(str[i][j].x - 24, str[i][j].y - 24, bmp.getData(), 48, 48);
			}
		}
	}
}

void Chess::che(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	while (1)
	{
		if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			//获取点击的坐标，且判断是否超出棋盘范围
		{
			cout << "x2=" << x2 << " y2=" << y2 << endl;
			getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
			cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
			if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
			{
				cout << "点击自己" << endl;
			}
			else {
				cout << "不是点击自己" << endl;
				//第二次点击的id为0，没有棋子
				if (str[*sub_x2][*sub_y2].id == -1)
				{
					cout << "无id" << endl;
					//判断规则
					if (sub_x1 == *sub_x2 || sub_y1 == *sub_y2)
					{
						cout << "无棋-满足规则" << endl;
						//符合规则，车直线行走
						//横行
						if (sub_x1 == *sub_x2)
						{
							int is_resist = 0;
							//循环直线，判断直线走是否有阻挡
							for (int i = ((sub_y1 < *sub_y2) ? sub_y1 : *sub_y2) + 1; i < ((sub_y1 > *sub_y2) ? sub_y1 : *sub_y2); i++)
							{
								//有阻挡，返回
								if (str[sub_x1][i].id != -1)
								{
									is_resist = -1;
									cout << "有阻挡" << endl;
									break;
								}
							}
							//吃子，交换数据,退出
							if (is_resist == 0)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								cout << "横走没棋-交换" << endl;
								return;
							}
						}
						//竖行
						if (sub_y1 == *sub_y2)
						{
							int is_resist = 0;
							//循环横行，判断横走是否有阻挡
							for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
							{
								//有阻挡，返回
								if (str[i][sub_y1].id != -1)
								{
									is_resist = -1;
									cout << "有阻挡" << endl;
									break;
								}
							}
							//吃子，交换数据，退出
							if (is_resist == 0)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								cout << "竖走没棋-交换" << endl;
								return;
							}
						}
					}

				}
				//第二次点击，有棋子
				else
				{
					cout << "有id" << endl;
					//同伙，棋子选择更换
					if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
					{

						cout << "同伙" << endl;
						this->isfriend = 1;
						return;
					}
					else
					{
						//不是同伙，判断是否符合行走规则
						cout << "不是同伙" << endl;
						if (sub_x1 == *sub_x2 || sub_y1 == *sub_y2)
						{
							//符合规则，车直线行走
							//横行
							if (sub_x1 == *sub_x2)
							{
								int is_resist = 0;
								//循环直线，判断直线走是否有阻挡
								for (int i = ((sub_y1 < *sub_y2) ? sub_y1 : *sub_y2) + 1; i < ((sub_y1 > *sub_y2) ? sub_y1 : *sub_y2); i++)
								{
									//有阻挡，返回
									if (str[sub_x1][i].id != -1)
									{
										is_resist = -1;
										cout << "有阻挡" << endl;
										break;
									}
								}
								//吃子，交换数据,退出
								if (is_resist == 0)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									cout << "横走有棋-交换-吃" << endl;
									return;
								}
							}
							//竖行
							if (sub_y1 == *sub_y2)
							{
								int is_resist = 0;
								//循环横行，判断横走是否有阻挡
								for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
								{
									//有阻挡，返回
									if (str[i][sub_y1].id != -1)
									{
										is_resist = -1;
										cout << "有阻挡" << endl;
										break;
									}
								}
								//吃子，交换数据，退出
								if (is_resist == 0)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									cout << "竖走有棋-交换-吃" << endl;
									return;
								}
							}
						}
					}
				}
			}
			cout << "不满足规则" << endl;
		}
	}
	cout << "endl" << endl;
}

void Chess::ma(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	while (1)
	{
		/**/
		if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			//获取点击的坐标，且判断是否超出棋盘范围
		{
			cout << "x2=" << x2 << " y2=" << y2 << endl;
			getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
			cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
			if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
			{
				cout << "点击自己" << endl;
			}
			else {
				cout << "不是点击自己" << endl;
				//第二次点击的id为-1，没有棋子
				if (str[*sub_x2][*sub_y2].id == -1)
				{
					cout << "无id" << endl;
					//判断规则
					if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
						(sub_x1 - 1 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
						(sub_x1 + 1 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
						(sub_x1 + 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
						(sub_x1 + 2 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
						(sub_x1 + 1 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
						(sub_x1 - 1 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
						(sub_x1 - 2 == *sub_x2 && sub_y1 - 1 == *sub_y2))
					{
						cout << "无棋-满足规则" << endl;
						//符合规则，车直线行走
						//横行
						if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) || (sub_x1 - 2 == *sub_x2 && sub_y1 - 1 == *sub_y2))
						{
							int is_resist = 0;
							//判断是否卡马脚，不卡则行走
							if (str[sub_x1 - 1][sub_y1].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								cout << "横走没棋-交换" << endl;
								return;
							}
							//卡马脚，不能行走
						}

						if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 2 == *sub_y2) || (sub_x1 + 1 == *sub_x2 && sub_y1 + 2 == *sub_y2))
						{
							int is_resist = 0;
							//判断是否卡马脚，不卡则行走
							if (str[sub_x1][sub_y1 + 1].id == -1)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								//吃子，交换数据,退出
								str[*sub_x2][*sub_y2].color = str[sub_x1][sub_y1].color;
								str[*sub_x2][*sub_y2].bmp = str[sub_x1][sub_y1].bmp;
								str[*sub_x2][*sub_y2].id = str[sub_x1][sub_y1].id;
								str[sub_x1][sub_y1].id = -1;

								cout << "横走没棋-交换" << endl;
								return;
							}
							//卡马脚，不能行走
						}

						if ((sub_x1 + 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) || (sub_x1 + 2 == *sub_x2 && sub_y1 - 1 == *sub_y2))
						{
							int is_resist = 0;
							//判断是否卡马脚，不卡则行走
							if (str[sub_x1 + 1][sub_y1].id == -1)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								//吃子，交换数据,退出
								cout << "横走没棋-交换" << endl;
								return;
							}
							//卡马脚，不能行走
						}

						if ((sub_x1 + 1 == *sub_x2 && sub_y1 - 2 == *sub_y2) || (sub_x1 - 1 == *sub_x2 && sub_y1 - 2 == *sub_y2))
						{
							int is_resist = 0;
							//判断是否卡马脚，不卡则行走
							if (str[sub_x1][sub_y1 - 1].id == -1)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								//吃子，交换数据,退出
								cout << "横走没棋-交换" << endl;
								return;
							}
							//卡马脚，不能行走
						}

					}
				}
				//第二次点击，有棋子
				else
				{
					cout << "有id" << endl;
					//同伙，棋子选择更换
					if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
					{
						cout << "同伙" << endl;
						this->isfriend = 1;
						return;
					}
					else
					{
						//不是同伙，判断是否符合行走规则
						cout << "不是同伙" << endl;
						if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
							(sub_x1 - 1 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
							(sub_x1 + 1 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
							(sub_x1 + 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
							(sub_x1 + 2 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
							(sub_x1 + 1 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
							(sub_x1 - 1 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
							(sub_x1 - 2 == *sub_x2 && sub_y1 - 1 == *sub_y2))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，车直线行走
							//横行
							if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) || (sub_x1 - 2 == *sub_x2 && sub_y1 - 1 == *sub_y2))
							{
								int is_resist = 0;
								//判断是否卡马脚，不卡则行走
								if (str[sub_x1 - 1][sub_y1].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
								//卡马脚，不能行走
							}

							if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 2 == *sub_y2) || (sub_x1 + 1 == *sub_x2 && sub_y1 + 2 == *sub_y2))
							{
								int is_resist = 0;
								//判断是否卡马脚，不卡则行走
								if (str[sub_x1][sub_y1 + 1].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
								//卡马脚，不能行走
							}

							if ((sub_x1 + 2 == *sub_x2 && sub_y1 + 1 == *sub_y2) || (sub_x1 + 2 == *sub_x2 && sub_y1 - 1 == *sub_y2))
							{
								int is_resist = 0;
								//判断是否卡马脚，不卡则行走
								if (str[sub_x1 + 1][sub_y1].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
								//卡马脚，不能行走
							}

							if ((sub_x1 + 1 == *sub_x2 && sub_y1 - 2 == *sub_y2) || (sub_x1 - 1 == *sub_x2 && sub_y1 - 2 == *sub_y2))
							{
								int is_resist = 0;
								//判断是否卡马脚，不卡则行走
								if (str[sub_x1][sub_y1 - 1].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
								//卡马脚，不能行走
							}

						}
					}
				}
			}
			cout << "不满足规则" << endl;
		}
	}
	cout << "endl" << endl;
}

void Chess::pao(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	while (1)
	{
		/**/
		if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			//获取点击的坐标，且判断是否超出棋盘范围
		{
			cout << "x2=" << x2 << " y2=" << y2 << endl;
			getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
			cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
			if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
			{
				cout << "点击自己" << endl;
			}
			else {
				cout << "不是点击自己" << endl;
				//第二次点击的id为-1，没有棋子
				if (str[*sub_x2][*sub_y2].id == -1)
				{
					cout << "无id" << endl;
					//判断规则
					if (sub_x1 == *sub_x2 || sub_y1 == *sub_y2)
					{
						cout << "无棋-满足规则" << endl;
						//符合规则，车直线行走
						//横行
						if (sub_x1 == *sub_x2)
						{
							int is_resist = 0;
							//循环直线，判断直线走是否有阻挡
							for (int i = ((sub_y1 < *sub_y2) ? sub_y1 : *sub_y2) + 1; i < ((sub_y1 > *sub_y2) ? sub_y1 : *sub_y2); i++)
							{
								//有阻挡，返回
								if (str[sub_x1][i].id != -1)
								{
									is_resist = -1;
									cout << "有阻挡" << endl;
									break;
								}
							}
							//吃子，交换数据,退出
							if (is_resist == 0)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								cout << "横走没棋-交换" << endl;
								return;
							}
						}
						//竖行
						if (sub_y1 == *sub_y2)
						{
							int is_resist = 0;
							//循环横行，判断横走是否有阻挡
							for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
							{
								//有阻挡，返回
								if (str[i][sub_y1].id != -1)
								{
									is_resist = -1;
									cout << "有阻挡" << endl;
									break;
								}
							}
							//吃子，交换数据，退出
							if (is_resist == 0)
							{
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
								cout << "竖走没棋-交换" << endl;
								return;
							}
						}
					}

				}
				//第二次点击，有棋子
				else
				{
					cout << "有id" << endl;
					//同伙，棋子选择更换
					if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
					{
						cout << "同伙" << endl;
						this->isfriend = 1;
						return;
					}
					else
					{
						//不是同伙，判断是否符合行走规则
						cout << "不是同伙" << endl;
						if (sub_x1 == *sub_x2 || sub_y1 == *sub_y2)
						{
							//符合规则，车直线行走
							//横行
							if (sub_x1 == *sub_x2)
							{
								int is_resist = 0;
								//循环直线，判断直线走是否有阻挡
								for (int i = ((sub_y1 < *sub_y2) ? sub_y1 : *sub_y2) + 1; i < ((sub_y1 > *sub_y2) ? sub_y1 : *sub_y2); i++)
								{
									//有阻挡，返回
									if (str[sub_x1][i].id != -1)
									{
										is_resist++;
									}
								}
								//吃子，交换数据,退出
								if (is_resist == 1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									cout << "横走有棋-交换-吃" << endl;
									return;
								}
							}
							//竖行
							if (sub_y1 == *sub_y2)
							{
								int is_resist = 0;
								//循环横行，判断横走是否有阻挡
								for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
								{
									//有阻挡，返回
									if (str[i][sub_y1].id != -1)
									{
										is_resist++;
									}
								}
								//吃子，交换数据，退出
								if (is_resist == 1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
									cout << "竖走有棋-交换-吃" << endl;
									return;
								}
							}
						}
					}
				}
			}
			cout << "不满足规则" << endl;
		}
	}
	cout << "endl" << endl;
}

void Chess::xiang_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{

	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp* bmp = new Bmp("./checkerboard.bmp");
	bmp->reverse();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 193 && x2 <= 616 && y2 >= 240 && y2 <= 472) || str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
						//return;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
								(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，象(相)飞田
								//右上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//右下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//左下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//左上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{

								cout << "同伙" << endl;

								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
									(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，车直线行走
									//右上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											//吃子，交换数据,退出

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//右下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											//吃子，交换数据,退出

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											//吃子，交换数据,退出

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											//吃子，交换数据,退出

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 264) || str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
						//return;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
								(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，象(相)飞田
								//右上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//右下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//左下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//左上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										//吃子，交换数据,退出

										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{

								cout << "同伙" << endl;

								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
									(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，车直线行走
									//右上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											//吃子，交换数据,退出

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//右下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
}
void Chess::xiang_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 264) || str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
						//return;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
								(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，象(相)飞田
								//右上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
									{
										//吃子，交换数据,退出
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										cout << "横走没棋-交换" << endl;

										return;
									}
									//卡象(相)脚，不能行走
								}
								//右下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
									{
										//吃子，交换数据,退出
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										cout << "横走没棋-交换" << endl;

										return;
									}
									//卡象(相)脚，不能行走
								}
								//左下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
									{
										//吃子，交换数据,退出
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										cout << "横走没棋-交换" << endl;

										return;
									}
									//卡象(相)脚，不能行走
								}
								//左上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
									{
										//吃子，交换数据,退出
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
										cout << "横走没棋-交换" << endl;

										return;
									}
									//卡象(相)脚，不能行走
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
									(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，车直线行走
									//右上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//右下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
										{
											//吃子，交换数据,退出
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 193 && x2 <= 616 && y2 >= 240 && y2 <= 472) || str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
						//return;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
								(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
								(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，象(相)飞田
								//右上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//右下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//左下
								if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}
								//左上
								if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
								{
									int is_resist = 0;
									//判断是否卡象(相)脚，不卡则行走
									if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
									{
										this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
										cout << "横走没棋-交换" << endl;
										return;
									}
									//卡象(相)脚，不能行走
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2) ||
									(sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2) ||
									(sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，车直线行走
									//右上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 + 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//右下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 + 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 + 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左下
									if (sub_x1 + 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 + 1][sub_y1 - 1].id == -1)
										{

											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");	//吃子，交换数据,退出
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
									//左上
									if (sub_x1 - 2 == *sub_x2 && sub_y1 - 2 == *sub_y2)
									{
										int is_resist = 0;
										//判断是否卡象(相)脚，不卡则行走
										if (str[sub_x1 - 1][sub_y1 - 1].id == -1)
										{
											this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
											cout << "横走没棋-交换" << endl;
											return;
										}
										//卡象(相)脚，不能行走
									}
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
}
void Chess::xiang(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	if (this->cmp == 0)//判断是哪边的棋盘-》红方
	{
		this->xiang_red(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	else//判断是哪边的棋盘-》黑方
	{
		this->xiang_black(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	cout << "endl" << endl;
}

void Chess::shi_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 336 && x2 <= 456 + 24 && y2 >= 336 && y2 <= 456 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1))
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 360 - 24 && x2 <= 456 + 24 && y2 >= 24 - 24 && y2 <= 120 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1))
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
};
void Chess::shi_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 360 - 24 && x2 <= 456 + 24 && y2 >= 24 - 24 && y2 <= 120 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1))
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");	//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 336 && x2 <= 456 + 24 && y2 >= 336 && y2 <= 456 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1))
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 - 1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走	
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
};
void Chess::shi(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	if (this->cmp == 0)//判断是哪边的棋盘-》红方
	{
		this->shi_red(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	else//判断是哪边的棋盘-》黑方
	{
		this->shi_black(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	cout << "endl" << endl;
}

void Chess::jiang_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	int x2, y2;
	LcdDevice* lcd = LcdDevice::getLcd();
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 336 && x2 <= 456 + 24 && y2 >= 336 && y2 <= 456 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1) ||
					str[sub_x1][sub_y1].id == str[*sub_x2][*sub_y2].id)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								int is_resist = 0;
								//判断点击是否是
								if (sub_y1 == *sub_y2)
								{
									is_resist = 1;
									for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
									{
										if (str[i][sub_y1].id != -1)
										{
											is_resist = -1;
											cout << "有阻挡" << endl;
											break;
										}
									}
								}
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) || is_resist == 1
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 360 - 24 && x2 <= 456 + 24 && y2 >= 24 - 24 && y2 <= 120 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1) ||
					str[sub_x1][sub_y1].id == str[*sub_x2][*sub_y2].id)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{
								cout << "同伙" << endl;
								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								int is_resist = 0;
								//判断点击是否是
								if (sub_y1 == *sub_y2)
								{
									is_resist = 1;
									for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
									{
										if (str[i][sub_y1].id != -1)
										{
											is_resist = -1;
											cout << "有阻挡" << endl;
											break;
										}
									}
								}
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) || is_resist == 1
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");//吃子，交换数据,退出
									cout << "横走没棋-交换" << endl;
									return;
								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
};
void Chess::jiang_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	int x2, y2;
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp* bmp = new Bmp("./checkerboard.bmp");
	bmp->reverse();
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 360 - 24 && x2 <= 456 + 24 && y2 >= 24 - 24 && y2 <= 120 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1) ||
					str[sub_x1][sub_y1].id == str[*sub_x2][*sub_y2].id)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									//吃子，交换数据,退出
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

									cout << "横走没棋-交换" << endl;

									return;
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{

								cout << "同伙" << endl;

								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								int is_resist = 0;
								//判断点击是否是
								if (sub_y1 == *sub_y2)
								{
									is_resist = 1;
									for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
									{
										if (str[i][sub_y1].id != -1)
										{
											is_resist = -1;
											cout << "有阻挡" << endl;
											break;
										}
									}
								}
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) || is_resist == 1
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走

										//吃子，交换数据,退出
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

									cout << "横走没棋-交换" << endl;

									return;


								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
			{
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				if ((x2 >= 336 && x2 <= 456 + 24 && y2 >= 336 && y2 <= 456 + 24) || (str[*sub_x2][*sub_y2].color == str[sub_x1][sub_y1].color && str[*sub_x2][*sub_y2].id != -1) ||
					str[sub_x1][sub_y1].id == str[*sub_x2][*sub_y2].id)
					//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
				{
					cout << "x2=" << x2 << " y2=" << y2 << endl;
					getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
					cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
					if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
					{
						cout << "点击自己" << endl;
					}
					else {
						cout << "不是点击自己" << endl;
						//第二次点击的id为-1，没有棋子
						if (str[*sub_x2][*sub_y2].id == -1)
						{
							cout << "无id" << endl;
							//判断规则
							if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
								(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2)
								)
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，仕斜走
								if (str[*sub_x2][*sub_y2].id == -1)
								{
									//吃子，交换数据,退出
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

									cout << "横走没棋-交换" << endl;

									return;
								}

							}

						}
						//第二次点击,有棋子
						else
						{
							cout << "有id" << endl;
							//同伙，棋子选择更换
							if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
							{

								cout << "同伙" << endl;

								this->isfriend = 1;
								return;
							}
							else
							{
								//不是同伙，判断是否符合行走规则
								cout << "不是同伙" << endl;
								int is_resist = 0;
								//判断点击是否是
								if (sub_y1 == *sub_y2)
								{
									is_resist = 1;
									for (int i = ((sub_x1 < *sub_x2) ? sub_x1 : *sub_x2) + 1; i < ((sub_x1 > *sub_x2) ? sub_x1 : *sub_x2); i++)
									{
										if (str[i][sub_y1].id != -1)
										{
											is_resist = -1;
											cout << "有阻挡" << endl;
											break;
										}
									}
								}
								if ((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2) ||
									(sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) || is_resist == 1
									)
								{
									cout << "无棋-满足规则" << endl;
									//符合规则，仕斜走

										//吃子，交换数据,退出
									this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

									cout << "横走没棋-交换" << endl;

									return;


								}
							}
						}
						cout << "不满足规则" << endl;
					}
				}
			}
		}
	}
};
void Chess::jiang(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	if (this->cmp == 0)//判断是哪边的棋盘-》红方
	{
		this->jiang_red(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	else//判断是哪边的棋盘-》黑方
	{
		this->jiang_black(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	cout << "endl" << endl;
}

void Chess::bin_red(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp* bmp = new Bmp("./checkerboard.bmp");
	bmp->reverse();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
				//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
			{
				cout << "x2=" << x2 << " y2=" << y2 << endl;
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
				if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
				{
					cout << "点击自己" << endl;
				}
				else {
					cout << "不是点击自己" << endl;
					//第二次点击的id为-1，没有棋子
					if (str[*sub_x2][*sub_y2].id == -1)
					{
						cout << "无id" << endl;
						//判断规则
						if (sub_x1 >= 5 && (sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
								//吃子，交换数据,退出
							this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

							cout << "横走没棋-交换" << endl;

							return;
						}
						if (sub_x1 < 5 &&
							((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
							if (str[*sub_x2][*sub_y2].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;
							}
						}

					}
					//第二次点击,有棋子
					else
					{
						cout << "有id" << endl;
						//同伙，棋子选择更换
						if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
						{

							cout << "同伙" << endl;

							this->isfriend = 1;
							return;
						}
						else
						{
							//不是同伙，判断是否符合行走规则
							cout << "不是同伙" << endl;
							if (sub_x1 >= 5 && (sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，
									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;

							}
							if (sub_x1 < 5 &&
								((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，
									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;
							}
						}
					}
					cout << "不满足规则" << endl;
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
				//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
			{
				cout << "x2=" << x2 << " y2=" << y2 << endl;
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
				if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
				{
					cout << "点击自己" << endl;
				}
				else {
					cout << "不是点击自己" << endl;
					//第二次点击的id为-1，没有棋子
					if (str[*sub_x2][*sub_y2].id == -1)
					{
						cout << "无id" << endl;
						//判断规则
						if (sub_x1 < 5 && (sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
							if (str[*sub_x2][*sub_y2].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;
							}
						}
						if (sub_x1 >= 5 &&
							((sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
							if (str[*sub_x2][*sub_y2].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;
							}
						}

					}
					//第二次点击,有棋子
					else
					{
						cout << "有id" << endl;
						//同伙，棋子选择更换
						if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
						{

							cout << "同伙" << endl;

							this->isfriend = 1;
							return;
						}
						else
						{
							//不是同伙，判断是否符合行走规则
							cout << "不是同伙" << endl;
							if (sub_x1 < 5 && (sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，

									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;

							}
							if (sub_x1 >= 5 &&
								((sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，

									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;

							}
						}
					}
					cout << "不满足规则" << endl;
				}
			}
		}
	}
}
void Chess::bin_black(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp* bmp = new Bmp("./checkerboard.bmp");
	bmp->reverse();
	int x2, y2;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	if (str[sub_x1][sub_y1].color == "red")
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
				//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
			{
				cout << "x2=" << x2 << " y2=" << y2 << endl;
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
				if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
				{
					cout << "点击自己" << endl;
				}
				else {
					cout << "不是点击自己" << endl;
					//第二次点击的id为-1，没有棋子
					if (str[*sub_x2][*sub_y2].id == -1)
					{
						cout << "无id" << endl;
						//判断规则
						if (sub_x1 < 5 && (sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
							if (str[*sub_x2][*sub_y2].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;
								return;
							}
						}
						if (sub_x1 >= 5 &&
							((sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
							if (str[*sub_x2][*sub_y2].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;
								return;
							}
						}

					}
					//第二次点击,有棋子
					else
					{
						cout << "有id" << endl;
						//同伙，棋子选择更换
						if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
						{

							cout << "同伙" << endl;

							this->isfriend = 1;
							return;
						}
						else
						{
							//不是同伙，判断是否符合行走规则
							cout << "不是同伙" << endl;
							if (sub_x1 < 5 && (sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，

									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;
								return;

							}
							if (sub_x1 >= 5 &&
								((sub_x1 + 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，

									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;
								return;

							}
						}
					}
					cout << "不满足规则" << endl;
				}
			}
		}
	}
	else
	{
		while (1)
		{
			if (lcd->djyesno(dj_hq1, &x2, &y2) && x2 >= 193 && x2 <= 616 && y2 >= 2 && y2 <= 472)
				//获取点击的坐标，且判断是否超出棋盘范围->判断所属方，可以行走的距离
			{
				cout << "x2=" << x2 << " y2=" << y2 << endl;
				getsub(x2, y2, &*sub_x2, &*sub_y2);//获取第二次点击的坐标在结构体数组中的下标
				cout << "*sub_x2=" << *sub_x2 << " *sub_y2=" << *sub_y2 << " id=" << str[*sub_x2][*sub_y2].id << endl;
				if (sub_x1 == *sub_x2 && sub_y1 == *sub_y2)//判断是否点击自己，不是就进行下一步
				{
					cout << "点击自己" << endl;
				}
				else {
					cout << "不是点击自己" << endl;
					//第二次点击的id为-1，没有棋子
					if (str[*sub_x2][*sub_y2].id == -1)
					{
						cout << "无id" << endl;
						//判断规则
						if (sub_x1 >= 5 && (sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
								//吃子，交换数据,退出
							this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

							cout << "横走没棋-交换" << endl;

							return;
						}
						if (sub_x1 < 5 &&
							((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
								(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
						{
							cout << "无棋-满足规则" << endl;
							//符合规则，
							if (str[*sub_x2][*sub_y2].id == -1)
							{
								//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;
							}
						}

					}
					//第二次点击,有棋子
					else
					{
						cout << "有id" << endl;
						//同伙，棋子选择更换
						if (str[sub_x1][sub_y1].color == str[*sub_x2][*sub_y2].color)
						{

							cout << "同伙" << endl;

							this->isfriend = 1;
							return;
						}
						else
						{
							//不是同伙，判断是否符合行走规则
							cout << "不是同伙" << endl;
							if (sub_x1 >= 5 && (sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，
									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;

							}
							if (sub_x1 < 5 &&
								((sub_x1 - 1 == *sub_x2 && sub_y1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 - 1 == *sub_y2) ||
									(sub_x1 == *sub_x2 && sub_y1 + 1 == *sub_y2)))
							{
								cout << "无棋-满足规则" << endl;
								//符合规则，
									//吃子，交换数据,退出
								this->savedata(sub_x1, sub_y1, *sub_x2, *sub_y2, "save");

								cout << "横走没棋-交换" << endl;

								return;
							}
						}
					}
					cout << "不满足规则" << endl;
				}
			}
		}
	}
}
void Chess::bin(int sub_x1, int sub_y1, int* sub_x2, int* sub_y2, int dj_hq1)
{
	if (this->cmp == 0)//判断是哪边的棋盘-》红方
	{
		this->bin_red(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	else//判断是哪边的棋盘-》黑方
	{
		this->bin_black(sub_x1, sub_y1, sub_x2, sub_y2, dj_hq1);
	}
	cout << "endl" << endl;
}


void Chess::rule(int sub_x1, int sub_y1, int dj_hq1)
{
	Bmp bmp2("./parts/pitch_on.bmp");
	LcdDevice* lcd = LcdDevice::getLcd();
	Bmp* bmp = new Bmp("./checkerboard.bmp");
	bmp->reverse();
	lcd->drawRgb(str[sub_x1][sub_y1].x - 24,
		str[sub_x1][sub_y1].y - 24, bmp2.getData(), 48, 48);
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << endl;
	this->isfriend = 0;
	int sub_x2 = -1, sub_y2 = -1, n = 0;
	cout << "id=" << str[sub_x1][sub_y1].id << endl;
	cout << "sub_x1=" << sub_x1 << " sub_y1=" << sub_y1 << " color=" << str[sub_x1][sub_y1].color << endl;
	switch (str[sub_x1][sub_y1].id)
	{
	case 1:
		che(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	case 2:
		ma(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	case 3:
		xiang(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	case 4:
		shi(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	case 5:
		jiang(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	case 6:
		pao(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	case 7:
		bin(sub_x1, sub_y1, &sub_x2, &sub_y2, dj_hq1);
		break;
	default:
		break;
	}
	if (this->isfriend == 1)
	{
		lcd->drawRgb_area(str[sub_x1][sub_y1].x - 24, str[sub_x1][sub_y1].y - 24, bmp->getData(), 48, 48);
		cout << " " << endl << "友方-换棋子" << endl << " " << endl;
		this->showData();
		rule(sub_x2, sub_y2, dj_hq1);
	}
}

void Chess::all()
{
	client A;//客户端类
	A.client_connect();//
	A.client_link();
	//红方=======================================================================
	if (A.color == 1)
	{
		LcdDevice* lcd = LcdDevice::getLcd();
		Chess chess;
		chess.cmp = 0;
		int x = 0, y = 0, sub_x = -1, sub_y = -1, n = 0;
		Bmp bmp("./checkerboard.bmp");
		bmp.reverse();
		lcd->drawRgb(0, 0, bmp.getData(), 800, 480);
		chess.setdata_r("./zuobiao.txt");
		chess.showData();
		string isfirst = "yes";
		char q[1024] = { 0 };
		char p[1024] = { 0 };

		while (1)
		{
			int dj_hq = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
			x = 0, y = 0;

			while (true)
			{
				if (lcd->djyesno(dj_hq, &x, &y))
				{
					if (x >= 193 && x <= 616 && y >= 2 && y <= 472)
					{
						chess.getsub(x, y, &sub_x, &sub_y);
						if (chess.str[sub_x][sub_y].color == "red" && chess.str[sub_x][sub_y].id != -1)
						{
							memset(p, 0, 1024);
							sprintf(p, "%d", 0);
							A.client_send(p);
							cout << endl << "红方等待发送" << endl << endl;
							chess.rule(sub_x, sub_y, dj_hq);
							memset(p, 0, 1024);
							sprintf(p, "%d-%d-%d-%d", chess.send_save_sub_x, chess.send_save_sub_y, chess.send_that_sub_x, chess.send_that_sub_y);
							A.client_send(p);
							close(dj_hq);
							cout << endl << "红方发送" << endl << endl;
							chess.show_send_data(isfirst);
							isfirst = "no";
							break;
						}
					}
					//请求悔棋
					if (x >= 622 && x <= 622 + 160 && y >= 89 && y <= 86 + 96
						&& (chess.send_save_sub_x != -1 || chess.send_that_sub_x != -1)
						&& (chess.recv_save_sub_x != -1 || chess.recv_save_sub_x != -1))
					{
						cout << "我方请求悔棋" << endl;

						Bmp back_bmp("./parts/hqsqec.bmp");
						back_bmp.reverse();
						lcd->getptr(200, 120, 400, 240);
						lcd->drawRgb(200, 120, back_bmp.getData(), 400, 240);
						while (1)
						{
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 54 && y >= 120 + 160 && x <= 200 + 163 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsqecy.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								memset(p, 0, 1024);
								sprintf(p, "%d", 1);
								A.client_send(p);

								memset(q, 0, 1024);
								A.client_recv(q);
								if (strcmp(q, "yes") == 0)
								{
									Bmp yes_argee("./parts/yes_agree.bmp");
									yes_argee.reverse();
									lcd->drawRgb(200, 120, yes_argee.getData(), 400, 240);
									sleep(1);
									lcd->drawptr(200, 120, 400, 240);
									cout << "对方同意悔棋" << endl;
									chess.show_savedata();
									isfirst = "yes";
									break;
								}
								if (strcmp(q, "yes") != 0)
								{
									Bmp yes_argee("./parts/no_agree.bmp");
									yes_argee.reverse();
									lcd->drawRgb(200, 120, yes_argee.getData(), 400, 240);
									sleep(1);
									lcd->drawptr(200, 120, 400, 240);
									break;
								}
							}
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 225 && y >= 120 + 160 && x <= 200 + 334 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsqecn.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								lcd->drawptr(200, 120, 400, 240);
								break;
							}
						}
					}

					//退出
					if (x >= 0 && x <= 60 && y >= 0 && y <= 60)
					{
						Bmp quit_bmp("./parts/tcyx.bmp");
						quit_bmp.reverse();
						lcd->getptr(200, 120, 400, 240);
						lcd->drawRgb(200, 120, quit_bmp.getData(), 400, 240);

						while (1)
						{
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 54 && y >= 120 + 160 && x <= 200 + 163 && y <= 120 + 200)
							{
								Bmp yes_quit("./parts/tcyxs.bmp");
								yes_quit.reverse();
								lcd->drawRgb(200, 120, yes_quit.getData(), 400, 240);
								memset(p, 0, 1024);
								sprintf(p, "%d", 2);
								A.client_send(p);
								sleep(1);
								return;
							}
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 225 && y >= 120 + 160 && x <= 200 + 334 && y <= 120 + 200)
							{
								Bmp no_quit("./parts/tcyxf.bmp");
								no_quit.reverse();
								lcd->drawRgb(200, 120, no_quit.getData(), 400, 240);
								sleep(1);
								lcd->drawptr(200, 120, 400, 240);
								break;
							}
						}

					}
				}

			}
			//我方将军对面
			if (chess.savestr[0][1].id == 5)
			{
				Bmp yes_back("./parts/jr.bmp");
				yes_back.reverse();
				lcd->drawRgb(320, 192, yes_back.getData(), 160, 96);
				sleep(1);
				memset(p, 0, 1024);
				sprintf(p, "%s", "exit");
				A.client_send(p);
				A.color = 0;
				cout << "敌方(黑方)将军已经死了，游戏结束" << endl;
				return;
			}
			while (1)
			{
				cout << endl << "红方等待黑方发送数据" << endl << endl;

				memset(q, 0, 1024);
				A.client_recv(q);
				//无其他操作 ，退出循环
				if (strcmp(q, "0") == 0)
				{
					break;
				}
				//是否同意对方悔棋
				if (strcmp(q, "1") == 0)
				{
					int dj_hq = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
					cout << "对方想悔棋,是否同意悔棋" << endl;
					Bmp isagree_bmp("./parts/hqsq1.bmp");
					isagree_bmp.reverse();
					lcd->getptr(200, 120, 400, 240);
					lcd->drawRgb(200, 120, isagree_bmp.getData(), 400, 240);
					while (1)
					{

						if (lcd->djyesno(dj_hq, &x, &y))
						{
							if (x >= 200 + 54 && y >= 120 + 160 && x <= 200 + 163 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsq2.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								sleep(1);
								cout << "同意悔棋" << endl;
								memset(p, 0, 1024);
								sprintf(p, "%s", "yes");
								A.client_send(p);
								lcd->drawptr(200, 120, 400, 240);
								chess.show_savedata();
								isfirst = "yes";
								break;
							}
							if (x >= 200 + 225 && y >= 120 + 160 && x <= 200 + 334 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsq3.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								sleep(1);
								cout << "不同意悔棋" << endl;
								memset(p, 0, 1024);
								sprintf(p, "%s", "no");
								A.client_send(p);
								lcd->drawptr(200, 120, 400, 240);
								break;
							}
						}
					}
					close(dj_hq);
				}
				if (strcmp(q, "2") == 0)
				{
					Bmp yes_back("./parts/dftc.bmp");
					yes_back.reverse();
					lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
					sleep(1);
					return;
				}
			}


			memset(q, 0, 1024);
			A.client_recv(q);
			sscanf(q, "%d-%d-%d-%d", &chess.recv_save_sub_x, &chess.recv_save_sub_y, &chess.recv_that_sub_x, &chess.recv_that_sub_y);
			cout << chess.recv_save_sub_x << ":" << chess.recv_save_sub_y << " " << chess.recv_that_sub_x << ":" << chess.recv_that_sub_y << endl;
			chess.savedata(chess.recv_save_sub_x, chess.recv_save_sub_y, chess.recv_that_sub_x, chess.recv_that_sub_y, "recv");
			cout << " 接收" << endl;
			chess.show_recv_data(isfirst);
			isfirst = "no";

			if (chess.savestr[0][3].id == 5)
			{
				Bmp yes_back("./parts/jh.bmp");
				yes_back.reverse();
				lcd->drawRgb(320, 192, yes_back.getData(), 160, 96);
				sleep(1);
				memset(p, 0, 1024);
				sprintf(p, "%s", "exit");
				A.client_send(p);
				A.color = 0;
				cout << "我方将军已经死了，游戏结束" << endl;
				return;
			}
		}
		cout << endl << "红方接收完毕" << endl << endl;

	}

	//黑方-----------------------------------------------------------------------
	else
	{
		LcdDevice* lcd = LcdDevice::getLcd();//获取LCD，单例
		Chess chess;//棋子类对象

		int x = 0, y = 0, sub_x = -1, sub_y = -1, n = 0;
		Bmp bmp("./checkerboard.bmp");//创建图片类对象，读取图片数据，并保存
		bmp.reverse();//图片反转
		lcd->drawRgb(0, 0, bmp.getData(), 800, 480);//显示背景图片
		chess.setdata_b("./zuobiao.txt");//进入函数中使用文件流读取文本
		chess.showData();//显示棋子数据
		string isfirst = "yes";
		char q[1024] = { 0 };
		char p[1024] = { 0 };
		chess.cmp = 1;
		while (1)
		{
			x = 0, y = 0;
			//接收操作代号，进行操作，0正常走棋，1投降
			while (1)
			{
				cout << "黑方等待红方发送数据" << endl;
				memset(q, 0, 1024);
				A.client_recv(q);//等待接收数据，阻塞
				cout << "A.client_recv(q)=" << q << endl;

				if (strcmp(q, "0") == 0)
				{
					break;
				}
				//是否同意对方悔棋
				if (strcmp(q, "1") == 0)
				{
					int dj_hq = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);//非阻塞打开触摸屏
					cout << "对方想悔棋,是否同意悔棋" << endl;
					Bmp isagree_bmp("./parts/hqsq1.bmp");
					isagree_bmp.reverse();
					lcd->getptr(200, 120, 400, 240);
					lcd->drawRgb(200, 120, isagree_bmp.getData(), 400, 240);
					while (1)
					{

						if (lcd->djyesno(dj_hq, &x, &y))
						{
							if (x >= 200 + 54 && y >= 120 + 160 && x <= 200 + 163 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsq2.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								sleep(1);
								cout << "同意悔棋" << endl;
								memset(p, 0, 1024);
								sprintf(p, "%s", "yes");//格式化输出，把yes存放输出到p中，作为协议发送给对方
								A.client_send(p);
								isfirst = "yes";
								lcd->drawptr(200, 120, 400, 240);
								chess.show_savedata();
								break;
							}
							if (x >= 200 + 225 && y >= 120 + 160 && x <= 200 + 334 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsq3.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								sleep(1);
								cout << "不同意悔棋" << endl;
								memset(p, 0, 1024);
								sprintf(p, "%s", "no");
								A.client_send(p);
								lcd->drawptr(200, 120, 400, 240);
								break;
							}
						}
					}
					close(dj_hq);
				}
				if (strcmp(q, "2") == 0)
				{
					Bmp yes_back("./parts/dftc.bmp");
					yes_back.reverse();
					lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
					sleep(1);
					memset(p, 0, 1024);
					sprintf(p, "%s", "exit");
					A.client_send(p);
					A.color = 0;
					return;
				}

			}

			//等待接收
			{
				memset(q, 0, 1024);
				A.client_recv(q);
				cout << "黑方接受完成" << endl;
				sscanf(q, "%d-%d-%d-%d", &chess.recv_save_sub_x, &chess.recv_save_sub_y, &chess.recv_that_sub_x, &chess.recv_that_sub_y);//格式化输入从接收到的数据中，保存数据到相应的变量中
				cout << chess.recv_save_sub_x << ":" << chess.recv_save_sub_y << " " << chess.recv_that_sub_x << ":" << chess.recv_that_sub_y << endl;
				chess.savedata(chess.recv_save_sub_x, chess.recv_save_sub_y, chess.recv_that_sub_x, chess.recv_that_sub_y, "revc");//根据获得的坐标来保存数据
				chess.show_recv_data(isfirst);
				isfirst = "no";
				if (chess.savestr[0][3].id == 5)//将军（我方），死亡，退出
				{
					Bmp yes_back("./parts/jr.bmp");
					yes_back.reverse();
					lcd->drawRgb(320, 192, yes_back.getData(), 160, 96);
					sleep(1);
					memset(p, 0, 1024);
					sprintf(p, "%s", "exit");
					A.client_send(p);
					A.color = 0;
					cout << "我方(黑方)将军已经死了，游戏结束" << endl;
					return;
				}
			}

			//接收完数据，打开触摸
			int dj_hq = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
			while (true)//走棋
			{
				if (lcd->djyesno(dj_hq, &x, &y))//判断是否点击
				{
					if (x >= 193 && x <= 616 && y >= 2 && y <= 472)//判断是否是棋盘里面的位置
					{
						chess.getsub(x, y, &sub_x, &sub_y);//获取点击的位置下标
						if (chess.str[sub_x][sub_y].color == "black" && chess.str[sub_x][sub_y].id != -1)//判断点击是否是有效操作、数据
						{
							memset(p, 0, 1024);
							sprintf(p, "%d", 0);//向对方发送走棋的代号
							A.client_send(p);
							cout << endl << "黑方等待发送" << endl << endl;
							chess.rule(sub_x, sub_y, dj_hq);//执行算法
							memset(p, 0, 1024);
							sprintf(p, "%d-%d-%d-%d", chess.send_save_sub_x, chess.send_save_sub_y, chess.send_that_sub_x, chess.send_that_sub_y);//将有发生变化的下标存储于数组中
							A.client_send(p);//执行完毕，向对方发送打包好的下标数据
							close(dj_hq);
							cout << endl << "黑方发送" << endl << endl;
							chess.show_send_data(isfirst);
							isfirst = "no";
							break;
						}
					}
					//请求悔棋
					if (x >= 622 && x <= 622 + 160 && y >= 89 && y <= 86 + 96
						&& (chess.send_save_sub_x != -1 || chess.send_that_sub_x != -1)
						&& (chess.recv_save_sub_x != -1 || chess.recv_save_sub_x != -1))
					{
						cout << "我方请求悔棋" << endl;

						Bmp back_bmp("./parts/hqsqec.bmp");
						back_bmp.reverse();
						lcd->getptr(200, 120, 400, 240);
						lcd->drawRgb(200, 120, back_bmp.getData(), 400, 240);
						while (1)
						{
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 54 && y >= 120 + 160 && x <= 200 + 163 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsqecy.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								memset(p, 0, 1024);
								sprintf(p, "%d", 1);
								A.client_send(p);

								memset(q, 0, 1024);
								A.client_recv(q);
								if (strcmp(q, "yes") == 0)
								{
									Bmp yes_argee("./parts/yes_agree.bmp");
									yes_argee.reverse();
									lcd->drawRgb(200, 120, yes_argee.getData(), 400, 240);
									sleep(1);
									lcd->drawptr(200, 120, 400, 240);
									cout << "对方同意悔棋" << endl;
									chess.show_savedata();
									isfirst = "yes";
									break;
								}
								if (strcmp(q, "yes") != 0)
								{
									Bmp yes_argee("./parts/no_agree.bmp");
									yes_argee.reverse();
									lcd->drawRgb(200, 120, yes_argee.getData(), 400, 240);
									sleep(1);
									lcd->drawptr(200, 120, 400, 240);
									break;
								}
							}
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 225 && y >= 120 + 160 && x <= 200 + 334 && y <= 120 + 200)
							{
								Bmp yes_back("./parts/hqsqecn.bmp");
								yes_back.reverse();
								lcd->drawRgb(200, 120, yes_back.getData(), 400, 240);
								lcd->drawptr(200, 120, 400, 240);
								break;
							}
						}
					}

					//退出
					if (x >= 0 && x <= 60 && y >= 0 && y <= 60)
					{
						Bmp quit_bmp("./parts/tcyx.bmp");
						quit_bmp.reverse();
						lcd->getptr(200, 120, 400, 240);
						lcd->drawRgb(200, 120, quit_bmp.getData(), 400, 240);

						while (1)
						{
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 54 && y >= 120 + 160 && x <= 200 + 163 && y <= 120 + 200)
							{
								Bmp yes_quit("./parts/tcyxs.bmp");
								yes_quit.reverse();
								lcd->drawRgb(200, 120, yes_quit.getData(), 400, 240);
								memset(p, 0, 1024);
								sprintf(p, "%d", 2);
								A.client_send(p);
								sleep(1);
								return;
							}
							if (lcd->djyesno(dj_hq, &x, &y) && x >= 200 + 225 && y >= 120 + 160 && x <= 200 + 334 && y <= 120 + 200)
							{
								Bmp no_quit("./parts/tcyxf.bmp");
								no_quit.reverse();
								lcd->drawRgb(200, 120, no_quit.getData(), 400, 240);
								sleep(1);
								lcd->drawptr(200, 120, 400, 240);
								break;
							}
						}

					}
				}
			}
			if (chess.savestr[0][1].id == 5)//将军，游戏结束
			{
				Bmp yes_back("./parts/jh.bmp");
				yes_back.reverse();
				lcd->drawRgb(320, 192, yes_back.getData(), 160, 96);
				sleep(1);
				memset(p, 0, 1024);
				sprintf(p, "%s", "exit");
				A.client_send(p);
				A.color = 0;
				cout << "敌方(红方)将军已经死了，游戏结束" << endl;
				return;
			}
		}
	}
}
