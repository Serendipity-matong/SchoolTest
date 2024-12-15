#include <stdio.h>
//通过windows.h进行中文输出，利用utf8的格式，避免不兼容的问题
#include <windows.h>
#include "../../include/Student.h"
#include "../../include/Dataloader.h"
#include "../../include/menu.h"
#include "../../include/StartSever.h"
int StudentsCount=0;
Student students;
int main()
{
    //宏定义txt文件名
    const char *filename="student.txt";
    //转成utf8的格式
    SetConsoleOutputCP(CP_UTF8);
    //加载数据操作
    int StudentsCount=LoadStudentsFromFile("student.txt");
    if(StudentsCount==-1)
    printf("加载学生数据失败\n");
    //输出开始菜单
    Menu();
    //启动服务
    StartSever();
}