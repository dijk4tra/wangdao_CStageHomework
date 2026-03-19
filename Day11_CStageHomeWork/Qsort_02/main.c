#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // 引入qsort()
#include <string.h>  // 引入strcmp()

// qsort 的比较函数逻辑
// 比较函数需要返回一个整数：
// 负值：表示第一个元素应该排在第二个元素前面
// 零：表示两个元素相等
// 正值：表示第一个元素应该排在第二个元素后面



// Student学生结构体类型定义
typedef struct {
    char name[25];
    int score;
} Student;

// 按照学生成绩从高到低进行排序（降序）
int compare_student_by_score(const void *a, const void *b) {
    // a、b是数据的指针
    // 数据是结构体，数据的指针的结构体指针
    Student *p_s1 = a;
    Student *p_s2 = b;

    return p_s2->score - p_s1->score;
}

// 按照学生成绩从低到高进行排序，如果成绩一致，则那么按照名字的字典顺序进行排序
int compare_student_by_score2(const void *a, const void *b) {
    Student *p_s1 = a;
    Student *p_s2 = b;

    if (p_s1->score != p_s2->score) {
        // 分数升序：前减后 (p1 - p2)
        return p_s1->score - p_s2->score;
    }
    else {
        // 分数相同时，调用 strcmp 比较字符串
        // strcmp 会根据字典序返回负、零或正数，正好符合 qsort 要求
        return strcmp(p_s1->name, p_s2->name);
    }
}

void print_students(Student stus[], int size) {
    for (int i = 0; i < size; i++) {
        printf("学生名字：%s，分数：%d\n",stus[i].name, stus[i].score);
    }
    printf("\n");
}


int main(void) {
    
    Student stus[] = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 85},
        {"David", 85},
        {"Eve", 92},
        {"Frank", 75},
        {"Grace", 85},
        {"Hannah", 95},
        {"Ivy", 78},
        {"Jack", 85}
    };

    int size = sizeof(stus) / sizeof(stus[0]);

    printf("规则1：按成绩从高到低排序：\n");
    qsort(stus, size, sizeof(Student), compare_student_by_score);
    print_students(stus, size);

    printf("规则2：按成绩升序，成绩一致按名字字典序：\n");
    qsort(stus, size, sizeof(Student), compare_student_by_score2);
    print_students(stus, size);

    return 0;
}