/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-08-30 19:43:46
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-16 19:35:34
 * @FilePath: \gx\8.30\11.client双端接发.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
pid_t fork(void);
typedef int pid_t;

int second = 0, i = 1, closeyesno = 0;
void scan_f(int *a, int b, int c);
int main(void)
{
    //创建管道文件
    //打开管道文件
    //创建进程
    srand((unsigned)time(NULL));
    int ret = mkfifo("/tmp/info1", 0777);

    if (ret < 0 && errno != EEXIST)
    {
        perror("mkfifo");
        return -1;
    }
    int writefd = open("/tmp/info1", O_RDWR);
    if (writefd < 0)
    {
        perror("open");
        return -1;
    }
    int day = 1, n = 0, m = 0,o=1, second = 0, barrieryesno = 0, secondyesno = 0, floor = 1, floorstart = 0, people = 0, targetfloor = 0, interval = 0, hour = 0;
    char buff[128] = {0};
    char buffer[128][32] = {0};
    while (o)
    {
        if (day < 9)
        {
            barrieryesno = 0;
            printf("运行时间：%d天 %d小时\n", day, hour);
            printf("现电梯在%d层\n", floor);
            printf("1 ：搭电梯 2：时间过一天\n请输入操作序号：");

            scan_f(&m, 1, 2);
            switch (m)
            {
            case 1:
                sleep(1);
                strcpy(buff, "start");
                write(writefd, buff, strlen(buff));
                printf("%s\n", buff);
                memset(buff, 0, sizeof(buff));

                n = 0;
                printf("第几楼层的人打算乘坐电梯:");
                scan_f(&floorstart, 1, 10);
                sprintf(buffer[n], "%d", floorstart);
                memset(buffer[n], 0, sizeof(buffer[n]));
                printf("电梯正在赶来，请稍候\n");

                interval = abs(floorstart - floor);
                sleep(1);
                printf("楼层间隔%d\n", interval);
                sprintf(buff, "%d", interval);
                write(writefd, buff, strlen(buff));
                memset(buff, 0, sizeof(buff));

                if (floorstart > floor)
                {
                    for (int i = 0; i < interval; i++)
                    {
                        sleep(1);
                        floor++;
                        printf("%d\n", floor);
                        // scan_f(&floorstart, 1, 10);
                        sprintf(buff, "%d", floor);
                        printf("%s\n", buff);
                        write(writefd, buff, strlen(buff));
                    }
                }
                else
                {
                    for (int i = 0; i < interval; i++)
                    {
                        sleep(1);
                        floor--;
                        printf("%d\n", floor);
                        sprintf(buff, "%d", floor);
                        write(writefd, buff, strlen(buff));
                        memset(buff, 0, sizeof(buff));
                    }
                }

                if (interval != 0)
                {
                    sleep(1);
                    strcpy(buff, "run_num");
                    write(writefd, buff, strlen(buff));
                    memset(buff, 0, sizeof(buff));
                }
                i = 1;
                printf("电梯已到达，电梯正在开门\n");
                sleep(2);
                strcpy(buff, "open");
                write(writefd, buff, strlen(buff));
                memset(buff, 0, sizeof(buff));

                printf("进电梯的人数(最多进10人)：");
                scan_f(&people, 1, 10);
                sprintf(buff, "%d", people);

                printf("楼层(最高10楼)：");
                scan_f(&targetfloor, 1, 10);

                if (floorstart != targetfloor)
                {
                    write(writefd, buff, strlen(buff));
                    memset(buff, 0, sizeof(buff));

                    printf("是否有遮挡物？\n1:有   2:无\n");
                    printf("请输入数字判断是否有遮挡物：");
                    scan_f(&barrieryesno, 1, 2);
                    printf("%d\n", barrieryesno);

                    if (barrieryesno == 1)
                    {
                        strcpy(buff, "barrier");
                        write(writefd, buff, strlen(buff));
                        memset(buff, 0, sizeof(buff));
                        printf("有遮挡物，无法关门\n");
                        printf("正在移开障碍物\n");
                        sleep(1);
                        printf("准备关门,电梯门等待时间是否在10秒内\n 1 ：是  2 ：不是 ：");
                        scan_f(&secondyesno, 1, 2);
                        if (secondyesno == 1)
                        {
                            printf("正常关门,往指定楼层运行\n");
                            strcpy(buff, "close_door");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            sleep(1);
                            printf("楼层间隔%d\n", abs(targetfloor - floorstart));
                            sprintf(buff, "%d", abs(targetfloor - floorstart));
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            if (targetfloor > floorstart)
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor++;
                                    printf("%d\n", floor);
                                    // scan_f(&floorstart, 1, 10);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }
                            else
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor--;
                                    printf("%d\n", floor);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }
                            if (interval != 0)
                            {
                                sleep(1);
                                strcpy(buff, "run_num");
                                write(writefd, buff, strlen(buff));
                                memset(buff, 0, sizeof(buff));
                            }
                            printf("已到达指定楼层\n");
                            printf("电梯正在开门\n");
                            sleep(2);
                            strcpy(buff, "open_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            printf("人员离开电梯，电梯关门\n\n\n");
                            sleep(2);
                            strcpy(buff, "close_door_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                        }
                        else
                        {

                            printf("等待时间过长，自动关门，往指定楼层运行\n");
                            strcpy(buff, "longtime");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                            sleep(1);

                            strcpy(buff, "close_door");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                            // sleep(abs(targetfloor - floorstart));

                            sleep(1);
                            printf("楼层间隔%d\n", abs(targetfloor - floorstart));
                            sprintf(buff, "%d", abs(targetfloor - floorstart));
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            if (targetfloor > floorstart)
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor++;
                                    printf("%d\n", floor);
                                    // scan_f(&floorstart, 1, 10);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }
                            else
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor--;
                                    printf("%d\n", floor);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }
                            if (interval != 0)
                            {
                                sleep(1);
                                strcpy(buff, "run_num");
                                write(writefd, buff, strlen(buff));
                                memset(buff, 0, sizeof(buff));
                            }

                            printf("已到达指定楼层\n");
                            printf("电梯正在开门\n");
                            sleep(2);
                            strcpy(buff, "open_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            printf("人员离开电梯，电梯关门\n\n\n");
                            sleep(2);
                            strcpy(buff, "close_door_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                        }
                    }
                    else
                    {
                        printf("可关门，准备关门,电梯门等待时间是否在10秒内\n 1 ：是  2 ：不是 ：");
                        scan_f(&secondyesno, 1, 2);
                        if (secondyesno == 1)
                        {
                            printf("正常关门,往指定楼层运行\n");
                            strcpy(buff, "close_door");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                            // sleep(abs(targetfloor - floorstart));

                            sleep(1);
                            printf("楼层间隔%d\n", abs(targetfloor - floorstart));
                            sprintf(buff, "%d", abs(targetfloor - floorstart));
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            if (targetfloor > floorstart)
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor++;
                                    printf("%d\n", floor);
                                    // scan_f(&floorstart, 1, 10);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }
                            else
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor--;
                                    printf("%d\n", floor);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }

                            if (interval != 0)
                            {
                                sleep(1);
                                strcpy(buff, "run_num");
                                write(writefd, buff, strlen(buff));
                                memset(buff, 0, sizeof(buff));
                            }

                            printf("已到达指定楼层\n");
                            printf("电梯正在开门\n");
                            sleep(2);
                            strcpy(buff, "open_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            printf("人员离开电梯，电梯关门\n\n\n");
                            sleep(2);
                            strcpy(buff, "close_door_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                        }
                        else
                        {

                            printf("等待时间过长，自动关门，往指定楼层运行\n");
                            strcpy(buff, "longtime");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                            sleep(1);

                            sleep(1);
                            strcpy(buff, "close_door");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                            // sleep(abs(targetfloor - floorstart));

                            sleep(1);
                            printf("楼层间隔%d\n", abs(targetfloor - floorstart));
                            sprintf(buff, "%d", abs(targetfloor - floorstart));
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            if (targetfloor > floorstart)
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor++;
                                    printf("%d\n", floor);
                                    // scan_f(&floorstart, 1, 10);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }
                            else
                            {
                                for (int i = 0; i < abs(targetfloor - floorstart); i++)
                                {
                                    sleep(1);
                                    floor--;
                                    printf("%d\n", floor);
                                    sprintf(buff, "%d", floor);
                                    write(writefd, buff, strlen(buff));
                                    memset(buff, 0, sizeof(buff));
                                }
                            }

                            if (interval != 0)
                            {
                                sleep(1);
                                strcpy(buff, "run_num");
                                write(writefd, buff, strlen(buff));
                                memset(buff, 0, sizeof(buff));
                            }
                            -

                                printf("已到达指定楼层\n");
                            printf("电梯正在开门\n");
                            sleep(2);
                            strcpy(buff, "open_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));

                            printf("人员离开电梯，电梯关门\n\n\n");
                            sleep(2);
                            strcpy(buff, "close_door_l");
                            write(writefd, buff, strlen(buff));
                            memset(buff, 0, sizeof(buff));
                        }
                    }
                }
                else
                {
                    sprintf(buff, "%d", 0);
                    write(writefd, buff, strlen(buff));
                    memset(buff, 0, sizeof(buff));
                    printf("目标楼层与当前楼层一致，请确认楼层\n");
                    sleep(1);
                    strcpy(buff, "close_door");
                    write(writefd, buff, strlen(buff));
                    memset(buff, 0, sizeof(buff));
                }
                sleep(1);
                break;
            case 2:
                day++;
                strcpy(buff, "timego");
                write(writefd, buff, strlen(buff));
                memset(buff, 0, sizeof(buff));

                sleep(1);
                interval = floor - 1;
                printf("楼层间隔%d\n", interval);
                sprintf(buff, "%d", interval);
                write(writefd, buff, strlen(buff));
                memset(buff, 0, sizeof(buff));

                for (int i = 0; i < interval; i++)
                {
                    sleep(1);
                    floor--;
                    sprintf(buff, "%d", floor);
                    printf("楼层：%d\n", floor);
                    write(writefd, buff, strlen(buff));
                    memset(buff, 0, sizeof(buff));
                }

                if (interval != 0)
                {
                    sleep(1);
                    strcpy(buff, "run_num");
                    write(writefd, buff, strlen(buff));
                    memset(buff, 0, sizeof(buff));
                }

                break;
            }
        }
        else
        {
            printf("电梯健康值不足，请联系工作人员进行维修\n");
            o=0;
        }
    }
    close(writefd);
    return 0;
}

void scan_f(int *a, int b, int c)
{
    while (!scanf("%d", a) || *a < b || *a > c)
    {
        while (getchar() != '\n')
            ;
        printf("请输入正确的数字进行选择：");
    }
}