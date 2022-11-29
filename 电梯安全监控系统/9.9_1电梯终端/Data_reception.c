/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-08-30 19:44:21
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-16 19:21:26
 * @FilePath: \gx\8.30\11.server双端接发.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "terminal.h"

//显示通知，w：文字显示区域的宽，h：文字显示区域的高，x，y表示从bmp的x，y开始获取宽w，高h大小的bmp数据作为背景
// font_x,font_y:文字显示的左上角的坐标（大小在w，h内），show_x,show_y:文字显示区域的左上角的坐标，n：字体大小
void *showtime_fun(void *rgc)
{
    int w = 150, h = 64;
    while (1)
    {
        showtime(lcd, mp, f, fmp, w, h, 0, h, 0, 0, 0, 0, 20);
    }
}
void *shownotice_fun(void *rgc)
{
    fd = fopen("./text/Life_tips.txt", "r");
    while (1)
    {
        int w = 500, h = 64;
        for (int i = 0; i < 2; i++)
        {
            shownotice(lcd, mp, f1, fmp, w, h, 500, 0, 0, 0, 300, 0, 30);
            sleep(5);
        }
    }
}
void *showweather_fun(void *rgc)
{
    while (1)
    {
        int w = 150, h = 64;
        showweather(lcd, mp, f, fmp, w, h, 150, 0, 0, 0, 150, 0, 20);
        sleep(1);
    }
}
void *datadisplay_fun(void *rgc)
{
    int w = 0, h = 0;
    while (1)
    {
        w = 63, h = 27;
        showdata(lcd, mp, f, fmp, w, h, 122, 93, w / 2 - (strlen(runmileage_numbuff) * 20 / 4), 3, 122, 93, runmileage_numbuff);
        w = 63, h = 28;
        showdata(lcd, mp, f, fmp, w, h, 122, 120, w / 2 - (strlen(people_numbuff) * 20 / 4), 3, 122, 120, people_numbuff);
        w = 49, h = 28;
        showdata(lcd, mp, f, fmp, w, h, 122, 148, w / 2 - (strlen(runtime_numbuff) * 20 / 4), 3, 122, 148, runtime_numbuff);

        w = 49, h = 27;
        showdata(lcd, mp, f, fmp, w, h, 122, 203, w / 2 - (strlen(run_numbuff) * 20 / 4), 3, 122, 203, run_numbuff);
        w = 62, h = 25;
        showdata(lcd, mp, f, fmp, w, h, 133, 230, w / 2 - (strlen(open_closedoor_numbuff) * 20 / 4), 3, 133, 230, open_closedoor_numbuff);
        w = 41, h = 25;
        showdata(lcd, mp, f, fmp, w, h, 133, 286, w / 2 - (strlen(barrier_numbuff) * 20 / 4), 3, 133, 286, barrier_numbuff);
        w = 34, h = 28;
        showdata(lcd, mp, f, fmp, w, h, 133, 311, w / 2 - (strlen(longtime_numbuff) * 20 / 4), 4, 133, 311, longtime_numbuff);
        w = 36, h = 30;
        showdata(lcd, mp, f, fmp, w, h, 491, 160, w / 2 - (strlen(floor_numbuff) * 20 / 4), 4, 491, 160, floor_numbuff);
        w = 36, h = 22;
        showdata(lcd, mp, f, fmp, w, h, 662, 167, w / 2 - (strlen(day_numbuff) * 20 / 4), 2, 662, 167, day_numbuff);
    }
}
void *batteryshow(void *arg)
{
    while (1)
    {
        if (day_num <= 2)
        {
            mpbattery = create_bmp("./9.9bmp/battery5.bmp");
        }
        if (day_num > 2 && day_num <= 4)
        {
            mpbattery = create_bmp("./9.9bmp/battery4.bmp");
        }
        if (day_num > 4 && day_num <= 6)
        {
            mpbattery = create_bmp("./9.9bmp/battery3.bmp");
        }
        if (day_num > 6 && day_num <= 8)
        {
            mpbattery = create_bmp("./9.9bmp/battery2.bmp");
        }
        if (day_num > 8 && day_num <= 10)
        {
            mpbattery = create_bmp("./9.9bmp/battery1.bmp");
        }
        reverse_bmp(mpbattery);
        show_bmp(lcd, 317, 154, mpbattery);
        destroy_bmp(mpbattery);
    }
}
int main(void)
{
    lcd = create_lcd("/dev/fb0");
    mp = create_bmp("elevator.bmp");
    f = fontLoad("./simfang.ttf");
    f1 = fontLoad("./simfang.ttf");
    fmp = createBitmap(800, 80, 4);
    zoom_bmp(mp, 800, 480);
    reverse_bmp(mp);
    show_bmp(lcd, 0, 0, mp);

    file = fopen("./text/news.txt", "r");
    show_news(lcd, mp, f1, fmp, 483, 131, 288, 281, 0, 0, 288, 281, 30);
    fclose(file);

    file = fopen("./text/maintain.txt", "r");
    show_maintain(lcd, mp, f1, fmp, 800, 46, 0, 434, 0, 0, 0, 434, 30);
    fclose(file);

    //创建管道打开管道
    int ret1 = mkfifo("/tmp/info1", 0777);
    if (ret1 < 0 && errno != EEXIST)
    {
        perror("mkfifo");
        return -1;
    }
    int readfd = open("/tmp/info1", O_RDWR);
    if (readfd < 0)
    {
        perror("open");
        return -1;
    }

    //线程
    pthread_t id = 0;
    int ret = pthread_create(&id, NULL, showtime_fun, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 0;
    }
    pthread_detach(id);

    id = 1;
    ret = pthread_create(&id, NULL, shownotice_fun, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 0;
    }
    pthread_detach(id);

    id = 2;
    ret = pthread_create(&id, NULL, showweather_fun, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 0;
    }
    pthread_detach(id);

    id = 3;
    ret = pthread_create(&id, NULL, datadisplay_fun, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 0;
    }
    pthread_detach(id);

    id = 3;
    ret = pthread_create(&id, NULL, batteryshow, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 0;
    }
    pthread_detach(id);

    char buffer[128][3] = {0};
    day_num=1;
    // char buff[128]={0};
    int n = 0;
    printf("开始运行！\n");
    sprintf(day_numbuff, "%d", day_num);
    sprintf(longtime_numbuff, "%d", longtime_num);
    sprintf(barrier_numbuff, "%d", barrier_num);
    sprintf(open_closedoor_numbuff, "%d", open_closedoor_num);
    sprintf(floor_numbuff, "%d", 1);
    sprintf(run_numbuff, "%d", run_num);
    sprintf(runmileage_numbuff, "%d", runmileage_num);
    sprintf(runtime_numbuff, "%d", runtime_num);
    sprintf(people_numbuff, "%d", people_num);
    while (1)
    {
        read(readfd, buff, sizeof(buff));
        readdata(readfd);
    }
    close(readfd);
    destroy_lcd(lcd);
    destroy_bmp(mp);
    fontUnload(f);
    fontUnload(f1);

    destroyBitmap(fmp);
    return 0;
}

