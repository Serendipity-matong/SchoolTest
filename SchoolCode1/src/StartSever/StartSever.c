#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "../../include/Student.h"
#include "../../include/StartSever.h"
#include "../../include/CRUD.h"
#include "../../include/menu.h"
// #include "../../include/CRUD.h"

void StartSever()
{
    SetConsoleOutputCP(CP_UTF8);
    int SeverCode;
    bool Exit=0;
    while(Exit!=1)
    {
        printf("请输入您所需要的操作：");
        scanf("%d",&SeverCode);
        getchar();
        switch(SeverCode)
        {
            case 1:
                printf("开始增加操作\n");
                Create();
                printf("aaa");
                break;
            // case 2:
            //     printf("开始修改操作\n");
            //     Delete();
            //     break;
            case 3:
                printf("开始查找操作\n");
                CheckMenu();
                Check();
                break;
            // case 4:
            //     printf("开始更新操作\n");
            //     Update();
            //     break;
            case 5:
                Exit=1;
            default:
                printf("Error\n");    
        }
    }
}