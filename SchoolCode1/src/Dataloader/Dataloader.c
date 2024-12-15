#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/Dataloader.h"
#include "../../include/Student.h"

int LoadStudentsFromFile(const char *filename)
{
    FILE *file=fopen("student.txt","r");
    if(file==NULL)
    {
        perror("文件打开失败");
            return -1;
    }
    int index=0;
    char line[50001];
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        long long id;
        char MiddleName[101];
        int Chinese,Maths,English,Average,Sum;
        char *token=strtok(line,",");
        while(token!=NULL)
        {
            if(strncmp(token,"ID:",3)==0)
            {
                id=atoll(token+3);
            }
            else if(strncmp(token,"Name:",5)==0)
            {
                strcpy(MiddleName,token+5);
            }
            else if(strncmp(token,"语文成绩:",strlen("语文成绩:"))==0)
            {
                Chinese=atoi(token+strlen("语文成绩:"));
            }
            else if(strncmp(token,"数学成绩:",strlen("数学成绩:"))==0)
            {
                Maths=atoi(token+strlen("数学成绩:"));
            }
            else if(strncmp(token,"英语成绩:",strlen("英语成绩:"))==0)
            {
                English=atoi(token+strlen("英语成绩:"));
            }
            else if(strncmp(token,"平均成绩:",strlen("平均成绩:"))==0)
            {
                Average=atoi(token+strlen("平均成绩:"));
            }
            else if(strncmp(token,"总分:",strlen("总分:"))==0)
            {
                Sum=atoi(token+strlen("总分:"));
            }
            //分割字符串，根据，将字符串进行分割
            token=strtok(NULL,",");
        }
        students.id[index]=id;
        students.name[index]=malloc(strlen(MiddleName)+1);
        if(students.name[index]==NULL)
        {
            perror("内存分配失败");
            fclose(file);
            return -1;
        }
        strcpy(students.name[index],MiddleName);
        students.score[index][0]=Chinese;
        students.score[index][1]=Maths;
        students.score[index][2]=English;
        students.average[index]=Average;
        students.sum[index]=Sum;
        printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d\n",
               students.id[index], students.name[index],
               students.score[index][0], students.score[index][1],
               students.score[index][2]);
               printf("aaaa\n");
        index++;
    }
    StudentsCount=index;
    fclose(file);
    return StudentsCount;
}