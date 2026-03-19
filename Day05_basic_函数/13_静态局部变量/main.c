#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 静态局部变量，性质比较接近全局变量
    // 存储在数据段上
    // 生命周期都是从程序启动到程序结束，都是"静态存储期限"

    static int num = 123;
    static int num2; 
    // 若未进行显式初始化赋值，默认初始化为0值

    // 静态局部变量，只会初始化一次
    printf("test1 call once. num = %d\n", ++num);
}

int generate_unique_id() {
    static int id = 100;
    return id++;
}


void test2() {
    // 静态局部变量：可以用在C中，一次程序运行期间，生成唯一的编号
    printf("unique id = %d\n", generate_unique_id());
    printf("unique id = %d\n", generate_unique_id());
    printf("unique id = %d\n", generate_unique_id());
    printf("unique id = %d\n", generate_unique_id());
    printf("unique id = %d\n", generate_unique_id());
    printf("unique id = %d\n", generate_unique_id());
}


int main(void) {
    //test1(); //123
    //test1(); //124
    //test1(); //125
    //test1(); //126
    //test1(); //127

    test2();

    return 0;
}