#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 全局变量：就是定义在函数外的变量
// 存储位置：存储在数据段中
// 生命周期：只要程序启动就活着
// 作用域：全局变量的作用域从"声明位置"开始，并延申至整个程序
// 要想在其他源文件中使用该全局变量，可以通过extern关键字来引用它

int global_num1 = 10086;

int main(void) {
    printf("%d\n", global_num1);
    printf("%d\n", global_num2);

    return 0;
}

int global_num2 = 100000;