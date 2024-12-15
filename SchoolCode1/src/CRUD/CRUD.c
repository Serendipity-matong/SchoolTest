#include <stdio.h>
#include <windows.h>
#include "../../include/menu.h"
#include "../../include/CRUD.h"
#include "../../include/Student.h"
#include "../../include/StartSever.h"
#include "../../include/Sort.h"
// void Create(int *StudentsCount) {
//     printf("Create 函数被调用，StudentsCount = %d\n", ++(*StudentsCount));
//     // 继续执行函数逻辑
// }

void Create()
{
    printf("aaa");
    FILE *file=fopen("student.txt","a");
    if(file==NULL)
    {
        perror("文件打开失败");
        return ;
    }
    char NameBuffer[100];
    char choice='y';
    do
    {
        StudentsCount++;
        if(StudentsCount>=MAX_STUDENTS)
        {
            printf("txt学生数量超出限制。\n");
            break;
        }
        printf("请输入学生学号：");
        scanf("%lld",&students.id[StudentsCount]);
        printf("请输入学生姓名：");
        scanf("%99s",NameBuffer);
        students.name[StudentsCount]=malloc(strlen(NameBuffer)+1);
        if(students.name[StudentsCount]==NULL)
        {
            perror("内存分配失败");
            fclose(file);
            return ;
        }
        strcpy(students.name[StudentsCount],NameBuffer);
        printf("请输入语文成绩：");
        scanf("%d",&students.score[StudentsCount][0]);
        printf("请输入数学成绩：");
        scanf("%d",&students.score[StudentsCount][1]);
        printf("请输入英语成绩：");
        scanf("%d",&students.score[StudentsCount][2]);
        students.average[StudentsCount]=(students.score[StudentsCount][0]+students.score[StudentsCount][1]+students.score[StudentsCount][2])/3;
        students.sum[StudentsCount]=students.score[StudentsCount][0]+students.score[StudentsCount][1]+students.score[StudentsCount][2];
        fprintf(file,"ID:%lld,Name:%s,语文成绩:%d,数学成绩:%d,英语成绩:%d,平均成绩:%d,总分:%d\n",
                students.id[StudentsCount],
                students.name[StudentsCount],
                students.score[StudentsCount][0],
                students.score[StudentsCount][1],
                students.score[StudentsCount][2],
                students.average[StudentsCount],
                students.sum[StudentsCount]);
            fflush(file);
        printf("是否继续输入(y/n)?");
        while (getchar()!='\n');//清理缓存区
        scanf("%c",&choice);        
    } while (choice=='y'||choice=='Y');
    printf("学生数据已成功写入student.txt文件中.\n");
    for(int i=0;i<StudentsCount;i++)
    {
        free(students.name[i]);
    }
    fclose(file);
}

void Check()
{
    int choice;
    printf("请输入你需要的查找操作\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            for(int i=0;i<3;i++)
            {
                long long Sum=0,Average=0;
                for(int j=0;j<StudentsCount;j++)
                    Sum+=students.score[j][i];
                if(i==0)
                printf("语文总分：%lld\t平均成绩: %lld\n",Sum,Sum/StudentsCount);
                if(i==1)
                printf("数学总分：%lld\t平均成绩: %lld\n",Sum,Sum/StudentsCount);
                if(i==2)
                printf("英语总分：%lld\t平均成绩: %lld\n",Sum,Sum/StudentsCount); 
            }
            break;
        case 2:
            SortMenu();
            SortChoice();
        case 3:
            printf("输入你需要查询的学号:");
            int ID;
            scanf("%d",&ID);
            for(int i=0;i<StudentsCount;i++)
            {
                if(students.id[i]==ID)
                {
                    printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d, Sum: %d, Average: %d\n",
                    students.id[i], students.name[i],
                     students.score[i][0], students.score[i][1],
                     students.score[i][2],students.sum[i],
                     students.average[i]);
                     break;     
                }
            }
            break;
        case 4:
            printf("请输入你需要查询的对象:");
            char querryname[100];
            scanf("100%s",querryname);
            for(int i=0;i<StudentsCount;i++)
            {
                if(strcmp(students.name[i],querryname)==0)
                {
                    printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d, Sum: %d, Average: %d\n",
                    students.id[i], students.name[i],
                     students.score[i][0], students.score[i][1],
                     students.score[i][2],students.sum[i],
                     students.average[i]);
                     break;
                }
            }
            break;
        case 5:
            for(int i=0;i<3;i++)
            {
                int Excellent=0,Good=0,Average=0,Pass=0,Fail=0;
                for(int j=0;j<StudentsCount;j++)
                {
                    if(students.score[j][i]>=90)Excellent++;
                    else if(students.score[j][i]>=80)Good++;
                    else if(students.score[j][i]>=70)Average++;
                    else if(students.score[j][i]>=60)Pass++;
                    else Fail++;
                }
                if(i==0)
                {
                    printf("语文成绩：\n");
                    printf("优秀人数:%d 占比:%.2f\n",Excellent,(float)Excellent/StudentsCount);
                    printf("良好人数:%d 占比:%.2f\n",Good,(float)Good/StudentsCount);
                    printf("中等人数:%d 占比:%.2f\n",Average,(float)Average/StudentsCount);
                    printf("及格人数:%d 占比:%.2f\n",Pass,(float)Pass/StudentsCount);
                    printf("不及格人数:%d 占比:%.2f\n",Fail,(float)Fail/StudentsCount);
                }
                if(i==1)
                {
                    printf("数学成绩：\n");
                    printf("优秀人数:%d 占比:%.2f\n",Excellent,(float)Excellent/StudentsCount);
                    printf("良好人数:%d 占比:%.2f\n",Good,(float)Good/StudentsCount);
                    printf("中等人数:%d 占比:%.2f\n",Average,(float)Average/StudentsCount);
                    printf("及格人数:%d 占比:%.2f\n",Pass,(float)Pass/StudentsCount);
                    printf("不及格人数:%d 占比:%.2f\n",Fail,(float)Fail/StudentsCount);
                }
                if(i==2)
                {
                    printf("英语成绩：\n");
                    printf("优秀人数:%d 占比:%.2f\n",Excellent,(float)Excellent/StudentsCount);
                    printf("良好人数:%d 占比:%.2f\n",Good,(float)Good/StudentsCount);
                    printf("中等人数:%d 占比:%.2f\n",Average,(float)Average/StudentsCount);
                    printf("及格人数:%d 占比:%.2f\n",Pass,(float)Pass/StudentsCount);
                    printf("不及格人数:%d 占比:%.2f\n",Fail,(float)Fail/StudentsCount);
                }
            }
        default :
            break;
                
    }
}