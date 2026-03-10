#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10

// 要注意：宏定义函数只做文本替换，其不考虑优先级
// 所以在定义的时候需要加括号！需要给每个变量以及表达式整体加上括号！
// #define SQRT_DIFF(x,y) (x*x - y*y)
#define SQRT_DIFF(x,y) ((x)*(x)-(y)*(y))

int main(void) {

    // 所有注释都会在预处理阶段被预处理器忽略删除

    printf("hello world!\n");
    printf("max_size = %d\n", MAX_SIZE);
    printf("sqrt_diff = %d\n", SQRT_DIFF(5, 4));
    printf("sqrt_diff = %d\n", SQRT_DIFF(2 + 3, 4));

    return 0;
}