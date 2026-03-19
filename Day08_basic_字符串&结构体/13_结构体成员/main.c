#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student {
    int student_id;
    char name[20];
    char gender;
    int chinese;
    int math;
    int english;
}Student;

void test1() {
    // 结构体成员的访问：使用 . 进行访问
    Student s1 = { 10,"zhangsan",'m',99,98,97 };
    Student s2 = { 12,"lisi",'f',100,87,98 };

    s1 = s2;

    // 直接认为，是将内存完成复制一份
    // 它们还是两份内存空间

    printf("s1.id = %d, s1.name = %s\n", s1.student_id, s1.name);
    printf("s2.id = %d, s2.name = %s\n", s2.student_id, s2.name);

    s1.student_id = 6666;

    printf("s1.id = %d, s1.name = %s\n", s1.student_id, s1.name);
    printf("s2.id = %d, s2.name = %s\n", s2.student_id, s2.name);

}

void test2(Student s1) {
    // 结构体其实也是值传递
    printf("test2=====id = %d, name = %s\n", s1.student_id, s1.name);

    s1.student_id = 654654;

    printf("test2=====id = %d, name = %s\n", s1.student_id, s1.name);
}

int main(void) {

    //test1();

    Student s = { 10, "zhangsan",'m',99,98,97 };
    test2(s);
    printf("main=====id = %d, name = %s\n", s.student_id, s.name);

    return 0;
}