#include <stdio.h>
#include <string.h>
#include "../../include/Student.h"
#include "../../include/Sort.h"
void SortChoice()
{
    printf("请输入你需要的排序操作\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            for(int i=0;i<StudentsCount;i++)
            {
                for(int j=i;j<StudentsCount;j++)
                {
                    if(students.sum[i]<students.sum[j])
                    {
                        int mid;
                        mid=students.id[j];
                        students.id[j]=students.id[i];
                        students.id[i]=mid;

                        mid=students.sum[j];
                        students.sum[j]=students.sum[i];
                        students.sum[i]=mid;

                        mid=students.score[j][0];
                        students.score[j][0]=students.score[i][0];
                        students.score[i][0]=mid;

                        mid=students.score[j][1];
                        students.score[j][1]=students.score[i][1];
                        students.score[i][1]=mid;

                        mid=students.score[j][2];
                        students.score[j][2]=students.score[i][2];
                        students.score[i][2]=mid;

                        char *temp=students.name[j];
                        students.name[j]=students.name[i];
                        students.name[i]=temp; 
                    }
                }
            }
            for(int i=0;i<StudentsCount;i++)
            printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d\n",
               students.id[i], students.name[i],
               students.score[i][0], students.score[i][1],
               students.score[i][2]);
               break;
        case 2:
            for(int i=0;i<StudentsCount;i++)
            {
                for(int j=i;j<StudentsCount;j++)
                {
                    if(students.sum[i]>students.sum[j])
                    {
                        int mid;
                        mid=students.id[j];
                        students.id[j]=students.id[i];
                        students.id[i]=mid;

                        mid=students.sum[j];
                        students.sum[j]=students.sum[i];
                        students.sum[i]=mid;

                        mid=students.score[j][0];
                        students.score[j][0]=students.score[i][0];
                        students.score[i][0]=mid;

                        mid=students.score[j][1];
                        students.score[j][1]=students.score[i][1];
                        students.score[i][1]=mid;

                        mid=students.score[j][2];
                        students.score[j][2]=students.score[i][2];
                        students.score[i][2]=mid;

                        char *temp=students.name[j];
                        students.name[j]=students.name[i];
                        students.name[i]=temp; 
                    }
                }
            }
            for(int i=0;i<StudentsCount;i++)
            printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d\n",
               students.id[i], students.name[i],
               students.score[i][0], students.score[i][1],
               students.score[i][2]);
               break;
        case 3:
            for(int i=0;i<StudentsCount;i++)
            {
                for(int j=i;j<StudentsCount;j++)
                {
                    if(students.id[i]>students.id[j])
                    {
                        int mid;
                        mid=students.id[j];
                        students.id[j]=students.id[i];
                        students.id[i]=mid;

                        mid=students.sum[j];
                        students.sum[j]=students.sum[i];
                        students.sum[i]=mid;

                        mid=students.score[j][0];
                        students.score[j][0]=students.score[i][0];
                        students.score[i][0]=mid;

                        mid=students.score[j][1];
                        students.score[j][1]=students.score[i][1];
                        students.score[i][1]=mid;

                        mid=students.score[j][2];
                        students.score[j][2]=students.score[i][2];
                        students.score[i][2]=mid;

                        char *temp=students.name[j];
                        students.name[j]=students.name[i];
                        students.name[i]=temp; 
                    }
                }
            }
            for(int i=0;i<StudentsCount;i++)
            printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d\n",
               students.id[i], students.name[i],
               students.score[i][0], students.score[i][1],
               students.score[i][2]);
               break; 
        case 4:
            for(int i=0;i<StudentsCount;i++)
            {
                for(int j=i;j<StudentsCount;j++)
                {
                    if (strcmp(students.name[i],students.name[j])>0)
                    {
                        int mid;
                        mid=students.id[j];
                        students.id[j]=students.id[i];
                        students.id[i]=mid;

                        mid=students.sum[j];
                        students.sum[j]=students.sum[i];
                        students.sum[i]=mid;

                        mid=students.score[j][0];
                        students.score[j][0]=students.score[i][0];
                        students.score[i][0]=mid;

                        mid=students.score[j][1];
                        students.score[j][1]=students.score[i][1];
                        students.score[i][1]=mid;

                        mid=students.score[j][2];
                        students.score[j][2]=students.score[i][2];
                        students.score[i][2]=mid;

                        char *temp=students.name[j];
                        students.name[j]=students.name[i];
                        students.name[i]=temp; 
                    }
                }
            }
            for(int i=0;i<StudentsCount;i++)
            printf("ID: %lld, Name: %s, Chinese: %d, Maths: %d, English: %d\n",
               students.id[i], students.name[i],
               students.score[i][0], students.score[i][1],
               students.score[i][2]);
               break;         
            default :
                break;   
    }
}