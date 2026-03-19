#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// int num;
// 这个只是在定义一个自己的类型
struct student{
    int student_id;
    char name[20];
    char gender;
    int chinese;
    int math;
    int english;
};

void test1() {
    // 结构体：就是给一组变量，规定一个名字
    // 下一次使用结构体的时候，可以直接认为结构体中，就有这些变量
}

void test2() {
    // 这个就相当于，声明了一个struct student，名字叫做s1
    struct student s1;

    //s1.student_id;
    //s1.name;
    //s1.
}

void test3() {
    // 结构体变量的初始化：也就是给刚刚声明的结构体，进行首次赋值
    struct student s1 = { 10,"zhangsan",'m',100,80,60 };
    struct student s2 = { 11,"lisi",'m' };
    struct student s3 = { 12 };

    // 如果给一个结构体初始化的时候，依次挨个赋值
    // 如果初始化的个数不够，后续补 0

    printf("id=%d, name=%s, chinese=%d, math=%d, english=%d\n", s1.student_id, s1.name, s1.chinese, s1.math, s1.english);
    printf("id=%d, name=%s, chinese=%d, math=%d, english=%d\n", s2.student_id, s2.name, s2.chinese, s2.math, s2.english);
    printf("id=%d, name=%s, chinese=%d, math=%d, english=%d\n", s3.student_id, s3.name, s3.chinese, s3.math, s3.english);

}

int main(void) {

    test3();

    return 0;
}