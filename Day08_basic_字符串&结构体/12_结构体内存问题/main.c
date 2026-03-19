#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct triangle {
    char flag1;
    int edge1;
    int edge2;
    int edge3;
    char test2[20];
}Triangle; 

void test1() {
    // 这个结构体，占据多大的空间，怎么占据？
    // 1 + 12 + 20 = 33 ？
    // 实际上不是33
    printf("%d\n", sizeof(Triangle));

    // 连续占据这块空间
    // 在实际操作的时候，由于CPU读取数据，最快的速度是以4字节为整数单位
    // 所以会有一个对其操作

    Triangle t1 = { 'a',1,11,12,"01234567890123456789" };
}

// 4    20    1(3)    4    4    4
typedef struct student {
    int student_id;
    char name[20];
    char gender;
    char gender2; // 新增
    int chinese;
    int math;
    int english;
}Student;

void test2() {
    // 对齐的具体策略不用管，编译器在处理的时候，怎样对齐就怎样取
    printf("%d\n", sizeof(Student));

    //Student s1 = { 11,"zhangsan",'a',10,11,13 };  // 占据空间大小为40字节
    Student s1 = { 11,"zhangsan",'a','b',10,11,13}; // 还是40字节

}


int main(void) {
    //test1();
    test2();

    return 0;
}