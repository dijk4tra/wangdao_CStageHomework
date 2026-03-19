#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 浮点数的不精确是绝对的

    float f1 = 0.333;

    // 因为浮点数是使用科学计数法来存储的
    // 1000000
    // 1.0 * 10^6
}

void test2() {
    float a = 0.1f;
    double b = 0.1;
    printf("%d\n", a == b); // 输出为0，不相等

    float c = 0.1F;
    // 中间有10个0
    float d = 0.100000000001F;
    printf("%d\n", c == d); // 输出为1，相等

}

void test3() {
    // 如果在公司中，要存储精确的浮点数，怎么办？
    // 使用字符串存储。
    // 操作的时候比较麻烦。但大概率公司会有现成的轮子，可以让你使用。
}

int main(void) {
    //test1();
    test2();
    return 0;
}