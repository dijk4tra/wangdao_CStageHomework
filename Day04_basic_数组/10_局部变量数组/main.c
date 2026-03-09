#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
    // 目前写的数组，是局部变量
    //int arr[10] = {10};

    // 局部变量，是存储在栈上的。
    // 栈非常小

    // 数组的大小，不要写太大
    // 如果写太大，可能会将栈占完，导致函数的调用出错，程序挂掉
    
    //char str1[1024 * 1024];
    char str1[1024 * 1023];
    
    return 0;
}