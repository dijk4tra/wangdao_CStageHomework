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

    Student s1 = { 10,"zhangsan",'m',99,98,97 };

    s1.student_id = 999;

    Student *p_s1 = &s1;
    // 结构体指针

    // 错误示例：. 比 * 的优先级更高
    //*p_s1.student_id;

    // 两种正确写法：
    //(*p_s1).student_id;
    //p_s1->student_id;

    printf("1========id = %d, name = %s\n", (*p_s1).student_id, (*p_s1).name);
    printf("1========id = %d, name = %s\n", p_s1->student_id, p_s1->name);

    // 结构体指针推荐使用 -> 来写
}

void change_student(Student *pstu) {
    printf("1========id=%d, name=%s\n", pstu->student_id, pstu->name);

    pstu->student_id = 987654;
    //pstu->name = "lisi";
    strcpy(pstu->name, "lisi");

    printf("1========id=%d, name=%s\n", pstu->student_id, pstu->name);
}

void test2() {
    // 若要在函数内部，修改外部的结构体值，需要传递结构体指针
    Student s1 = { 10,"zhangsan",'m',99,98,97 };
    //Student *ps1 = &s1;
    change_student(&s1);
    printf("22222========id=%d, name=%s\n", s1.student_id, s1.name);
}

int main(void) {

    //test1();
    test2();

    return 0;
}