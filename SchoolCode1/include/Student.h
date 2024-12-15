#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 101
#define STUBENT_SUBJECT 3

typedef struct
{
    long long id[MAX_STUDENTS];
    char *name[MAX_STUDENTS];
    int score[MAX_STUDENTS][STUBENT_SUBJECT];
    int average[MAX_STUDENTS];
    int sum[MAX_STUDENTS];
}Student;

extern Student students;
extern int StudentsCount;
// void free_student_names(Student *students);

#endif
