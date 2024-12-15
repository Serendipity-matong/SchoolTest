#include <stdio.h>
#include <windows.h>
#include "../../include/menu.h"

void Menu() 
{
    SetConsoleOutputCP(CP_UTF8);
    printf("1. 增加成绩\n");
    printf("2. 删除成绩\n");
    printf("3. 查询成绩\n");
    printf("4. 修改成绩\n");
    printf("5. 退出\n");
}

void CheckMenu()
{
    SetConsoleOutputCP(CP_UTF8);
    printf("1.每门课程的总分和平均分\n");
    printf("2.整体排序查询\n");
    printf("3.学号查询成绩\n");
    printf("4.姓名查询成绩\n");
    printf("5.整体百分比布局表\n");
}
void SortMenu()
{
    SetConsoleOutputCP(CP_UTF8);
    printf("1.按总分从高到低排序\n");
    printf("2.按总分从低到高排序\n");
    printf("3.学号大小排序\n");
    printf("4.按首字母大小排序\n");
}