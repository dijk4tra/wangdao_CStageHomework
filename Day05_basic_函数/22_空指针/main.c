#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    int *p1 = NULL;

    // NULL这个位置，不允许读取数据，不允许修改数据
    //printf("%d\n", *p1);
    //*p1 = 987;

    // NULL就是用来表示一个明确不可用的信号

    if (p1 != NULL) {
        printf("%d------", *p1);
    }
    else {
        printf("p1为NULL，不可用！");
    }
}

int main(void) {
    test1();
    return 0;
}