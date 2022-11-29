#include "terminal.h"

void shownotice(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n)
{
    fontSetSize(fmp, n);
    font = createBitmap(w, h, 4);
    char buff[128] = {0};
    char buffer[128] = {0};

    fgets(buff, 128, fd);
    sscanf(buff, "%s", buffer);
    // printf("%s\n",buffer);
    if (strcmp(buff, "quit") == 0)
    {
        fseek(fd, 0, SEEK_SET);
        fgets(buff, 128, fd);
        sscanf(buff, "%s", buffer);
    }

    // sscanf(buff, "%s", buffer[1], buffer[2]);
    // printf("%s\n",buff);
    setfontPix(font, mp, w, h, x, y, 0xffffff00);
    // setfontPix(font1,NULL,w1,h1,0,h,0x0000ff00);
    fontPrint(f, font, font_x, font_y, buffer, 0xff00, 0);
    //当文本走完，
    show_font(lcd, show_x, show_y, font);
    destroyBitmap(font);
}

void showtime(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n)
{
    time_t t;
    struct tm *Time;
    time(&t);
    char buff[100] = {0};
    Time = localtime(&t);
    char *wd[7] = {"星期天", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    snprintf(buff, 100, "%d年%d月%d日\n%s\n%d时%d分%d秒", 1900 + Time->tm_year, 1 + Time->tm_mon, Time->tm_mday, wd[Time->tm_wday], Time->tm_hour, Time->tm_min, Time->tm_sec);

    fontSetSize(fmp, n);
    font = createBitmap(w, h, 4);
    setfontPix(font, mp, w, h, 0, 0, 0x0000ff00);
    fontPrint(fmp, font, font_x, font_y, buff, 0xffffff00, 0);
    show_font(lcd, show_x, show_y, font);
    destroyBitmap(font);
}

void showweather(LcdDevice *lcd, struct Bmp *mp, font *f, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n)
{
    fontSetSize(f, n);
    font = createBitmap(w, h, 4);
    FILE* ffile = fopen("./text/weat.txt","r");
    char buff[128] = {0};
    char buffer[128] = {0};
    fgets(buff, 128, ffile);
    sscanf(buff, "%s", buffer);
    int l = 1;
    setfontPix(font, mp, w, h, x, y, 0xffffff00);
    while (l)
    {
        fontPrint(f, font, font_x, font_y, buffer, 0xc7820a00, 0);
        font_y += 30+2;
        fgets(buff, 128, ffile);
        sscanf(buff, "%s", buffer);
        if (strcmp(buff, "quit") == 0)
        {
            l = 0;
        }
    }
    //setfontPix(font, mp, w, h, x, y, 0xff000000);
    //fontPrint(f, font, font_x, font_y, "天气", 0x0000ff00, 0);
    fclose(ffile);
    show_font(lcd, show_x, show_y, font);
    destroyBitmap(font);
}

void showdata(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, char buff[128])
{
    // /printf("\\\\\\\\\\\\\\\\\\==\n");
    font = createBitmap(w, h, 4);
    setfontPix(font, mp, w, h, x, y, 0xff000000);
    fontPrint(f, font, font_x, font_y, buff, 0x00, 0);
    show_font(lcd, show_x, show_y, font);
    destroyBitmap(font);
}

void readdata(int readfd)
{

    if (strcmp(buff, "start") == 0)
    {
        printf("电梯运行：%s\n", buff);
        memset(buff, 0, sizeof(buff));

        // read(readfd, buff, sizeof(buff));
        // printf("电梯运行一次人数:%s\n", buff);
        // memset(buff, 0, sizeof(buff));
        read(readfd, buff, sizeof(buff));
        sscanf(buff, "%d", &floor_spacing);
        printf("楼层间隔:%d\n", floor_spacing);
        memset(buff, 0, sizeof(buff));

        for (int i = 0; i < floor_spacing; i++)
        {
            printf("i=%d\n", i);
            read(readfd, buff, sizeof(buff));
            strcpy(floor_numbuff, buff);
            printf("star=%s\n", floor_numbuff);
            memset(buff, 0, sizeof(buff));

            runmileage_num += 3;
            sprintf(runmileage_numbuff, "%d", runmileage_num);

            runtime_num += 2;
            sprintf(runtime_numbuff, "%d", runtime_num);
        }
    }
    //printf("%s\n", buff);
    if (strcmp(buff, "open") == 0)
    {
        printf("电梯开门:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        open_closedoor_num++;
        sprintf(open_closedoor_numbuff, "%d", open_closedoor_num / day_num);

        read(readfd, buff, sizeof(buff));
        printf("电梯运行一次人数:%s\n", buff);
        sscanf(buff, "%d", &people_number);
        memset(buff, 0, sizeof(buff));

        people_num += people_number;
        sprintf(people_numbuff, "%d", people_num);
    }

    if (strcmp(buff, "run_num") == 0)
    {
        run_num++;
        sprintf(run_numbuff, "%d", run_num);
        memset(buff, 0, sizeof(buff));
    }

    if (strcmp(buff, "barrier") == 0)
    {
        printf("电梯阻碍:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        barrier_num++;
        sprintf(barrier_numbuff, "%d", barrier_num);
    }

    if (strcmp(buff, "longtime") == 0)
    {
        printf("电梯开门时间过长:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        longtime_num++;
        sprintf(longtime_numbuff, "%d", longtime_num);
    }

    if (strcmp(buff, "close_door") == 0)
    {
        printf("电梯关门，准备运行:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        open_closedoor_num++;
        sprintf(open_closedoor_numbuff, "%d", open_closedoor_num / day_num);

        read(readfd, buff, sizeof(buff));
        sscanf(buff, "%d", &floor_spacing);
        printf("楼层间隔:%d\n", floor_spacing);
        memset(buff, 0, sizeof(buff));

        for (int i = 0; i < floor_spacing; i++)
        {
            printf("i=%d\n", i);
            read(readfd, buff, sizeof(buff));
            strcpy(floor_numbuff, buff);
            printf("end=%s\n", floor_numbuff);
            memset(buff, 0, sizeof(buff));

            runmileage_num += 3;
            sprintf(runmileage_numbuff, "%d", runmileage_num);

            runtime_num += 2;
            sprintf(runtime_numbuff, "%d", runtime_num);
        }
    }

    if (strcmp(buff, "open_l") == 0)
    {
        printf("电梯一次运行结束，电梯开门:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        open_closedoor_num++;
        sprintf(open_closedoor_numbuff, "%d", open_closedoor_num / day_num);
    }

    if (strcmp(buff, "close_door_l") == 0)
    {
        printf("电梯已空，自动关门:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        open_closedoor_num++;
        sprintf(open_closedoor_numbuff, "%d", open_closedoor_num / day_num);
    }

    if (strcmp(buff, "timego") == 0)
    {
        printf("一天过去:%s\n", buff);
        memset(buff, 0, sizeof(buff));
        day_num++;
        sprintf(day_numbuff, "%d", day_num);

        read(readfd, buff, sizeof(buff));
        sscanf(buff, "%d", &floor_spacing);
        printf("楼层间隔:%d\n", floor_spacing);
        memset(buff, 0, sizeof(buff));

        for (int i = 0; i < floor_spacing; i++)
        {
            printf("i=%d\n", i);
            read(readfd, buff, sizeof(buff));
            strcpy(floor_numbuff, buff);
            printf("楼层：%s\n", floor_numbuff);
            memset(buff, 0, sizeof(buff));

            runmileage_num += 3;
            sprintf(runmileage_numbuff, "%d", runmileage_num);

            runtime_num += 2;
            sprintf(runtime_numbuff, "%d", runtime_num);
        }
    }
}

void show_news(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n)
{
    fontSetSize(fmp, n);
    font = createBitmap(w, h, 4);
    char buff[128] = {0};
    char buffer[128] = {0};

    fgets(buff, 128, file);
    sscanf(buff, "%s", buffer);
    int l = 1;
    setfontPix(font, mp, w, h, x, y, 0xffffff00);
    while (l)
    {
        fontPrint(f, font, font_x, font_y, buffer, 0xc7820a00, 0);
        fgets(buff, 128, file);
        sscanf(buff, "%s", buffer);
        font_y += n + 5;
        if (strcmp(buff, "quit") == 0)
        {
            l = 0;
        }
    }
    show_font(lcd, show_x, show_y, font);
    destroyBitmap(font);
}

void show_maintain(LcdDevice *lcd, struct Bmp *mp, font *fmp, bitmap *font, int w, int h, int x, int y, int font_x, int font_y, int show_x, int show_y, int n)
{
    fontSetSize(fmp, n);
    font = createBitmap(w, h, 4);
    char buff[128] = {0};
    char buffer[128] = {0};

    fgets(buff, 128, file);
    sscanf(buff, "%s", buffer);
    int l = 1;
    setfontPix(font, mp, w, h, x, y, 0xffffff00);
    while (l)
    {
        fontPrint(f, font, font_x, font_y, buffer, 0xc7820a00, 0);
        font_x += n * strlen(buffer) / 4;
        fgets(buff, 128, file);
        sscanf(buff, "%s", buffer);
        if (strcmp(buff, "quit") == 0)
        {
            l = 0;
        }
    }
    show_font(lcd, show_x, show_y, font);
    destroyBitmap(font);
}
