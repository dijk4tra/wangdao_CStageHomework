#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // scanf函数会从左到右依次匹配格式字符串中的每一项：
    // 如果匹配数据项成功，那么scanf函数会继续处理格式串的剩余部分；
    // 如果匹配不成功，那么scanf函数将不再处理格式串的剩余部分，而会立刻返回。

    int num1, num2;

    // 10 30   ===> num1=10  num2=30
    // 10a333  ===> num1=10  num2 还是未初始化的随机值
    int ret = scanf("%d %d", &num1, &num2);

    // 返回值就是它成功匹配的个数。 
    printf("%d\n", ret);
}

void test2() {
    int num1 = 9999;
    double d1 = 3.151515;

    // scanf会尽自己可能去匹配。 一直往后匹配，直到匹配到不能匹配为止。 
    // 111113.1415   ===> num1=111113  d1=0.1415
    // 10086 9.9956  ===> num1=10086  d1=9.9956
    scanf("%d %lf", &num1, &d1);

    printf("num1 = %d, d1 = %lf\n", num1, d1);
}

void test3() {
    int num1 = 0, num2 = 0;

    // 空格可以匹配零空格，也可匹配一个空格，也可匹配多个空格，也可以匹配换行符
    //scanf("%d %d", &num1, &num2);
    //printf("num1 = %d, num2 = %d\n", num1, num2);

    // %d 处理的整形
    // 如果在scanf中，除了转换说明，有其它的字符
    // 则必须要求原样输入，否则匹配不成功
    // 10,80
    // 10 80
    scanf("%d,%d", &num1, &num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
}

void test4() {
    // 容易将printf和scanf用混 
    int num1 = 0, num2 = 0;

    // num1=10 num2=999
    // 如果这样输入，则 scanf 必须写为
    //scanf("num1=%d num2=%d", &num1, &num2);
    //printf("num1 = %d, num2 = %d\n", num1, num2);


    // 如果想让scanf输入的时候，前方有提示，可以用printf来提示 
    printf("please input two number, (num1 num2)\n");

    //scanf("%d %d\n", &num1, &num2); // 不建议，因为回车回看起来没效果。 其实只是因为 \n 匹配了换行符。 
    scanf("%d %d", &num1, &num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
}

void test5() {
    // 使用 printf 也要注意，不要写printf  &
    int num1 = 111;
    int num2 = 666;

    printf("%d, %d\n", num1, num2);
    printf("%d, %d\n", &num1, &num2);
}



int main(void) {
    //test1();
    //test2();
    test3();
    //test4();
    //test5();
    return 0;
}