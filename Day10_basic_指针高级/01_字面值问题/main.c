#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[15];
    char gender;
}Student;

void test1() {
    // "zhangsan"

    // 关于它存储的位置，如何确定？
    // 1."zhangsan"存储在只读数据段
    printf("zhangsan");

    char str[20] = { 0 };

    strcpy(str, "zhangsan"); // 正确的写法
    strcpy("zhangsan", str); // error

    // 如果你用指针接受，也是只读数据段
    char *p = "zhangsan";

    // 2.如果左边的写法是一个数组的写法，则不存储在只读数据段
    // 语法糖 str2 和 str3 是完全等价的
    char str2[] = "lisibubei";
    char str3[] = { 'l','i','s','i','h','u','b','e','i','\0' };
    char str4[] = { 'l','i','s','i','h','u','b','e','i' };

    // 结构体和字符串都存储在栈上
    // 结构体连续占据空间，字符串/字符数组其实是存储在结构体内部的空间
    Student stu = { 1,"wangwu",'f' };

    // 在堆上申请的空间，Student内部的数组是存储在堆上的
    Student *stu2 = malloc(sizeof(Student));

    stu2->id = 10086;
    //stu2->name = "zhangsan";  // error
    strcpy(stu2->name, "zhangsan");

}

int main(void) {
    
    return 0;
}