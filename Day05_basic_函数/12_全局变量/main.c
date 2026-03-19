#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 全局变量不能同名
int global_num666 = 1008611;
// 尽量不要使用全局变量
// 全局变量还有一个不推荐使用的原因：生命周期太长

// 若实在要用，推荐使用static修饰的全局变量
// 加上static后，该静态全局变量就只能在改文件内被访问
//static int global_num666 = 1008611;

int global_num777;
// 若未进行显式初始化赋值，系统则会为全局变量设置默认值 0

int main(void) {

    test1111();

    printf("global print in main.c = %d\n", global_num666);

    printf("global_num777 = %d\n", global_num777);
    
    return 0;
}