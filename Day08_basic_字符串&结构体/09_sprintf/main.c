#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // printf： 输出，往屏幕输出   
    // scanf ： 输入，从键盘输入

    // sprintf: 输出，往字符串输出
    // sscanf： 输入，从字符串输入
}

void test2() {
    int num1 = 10;
    double d1 = 3.14;

    printf("%d=====%lf\n", num1, d1);

    char buf[50] = { 0 };
    
    char *p = NULL;

    sprintf(buf, "%d=====%lf\n", num1, d1);
    //sprintf(p, "%d=====%lf\n", num1, d1);

    // sprintf也会输出\0

}

void test3() {
    // sscanf: 输入，从字符串中输入。 

    int num = 0;
    double d1 = 0.0;

    scanf("%d %lf", &num, &d1);

    char buf[20] = "666 3.33";
    sscanf(buf, "%d %lf", &num, &d1);
}

int main(int argc, char *argv[]) {
    
    int num = 0;
    sscanf(argv[1], "%d", &num);

    printf("num = %d\n", num);

    for (int i = 0; i < num; i++) {
        printf("========\n");
    }

    //test2();
    //test3();

    // 后续，如果有将字符串转成其他类型的需求，需要想起来用sscanf
    return 0;
}