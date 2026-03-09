#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test1(){
    // 随机数如何生成？
    // 1.引入头文件 <stdlib.h> <time.h>
    // 2.设置种子值 srand();
    // 3.使用rand()得到随机数

    srand(3);

    int random_value1 = rand();
    int random_value2 = rand();
    int random_value3 = rand();

    printf("value1 = %d\n", random_value1);
    printf("value2 = %d\n", random_value2);
    printf("value3 = %d\n", random_value3);
    // rand得到的其实是一个伪随机数
    // 随机数和 srand()种子值相关。

}

void test2() {
    // 设置种子值，然后使用rand()，会得到一个固定的序列
    // 48 7196 9294 6636 6535
    
    srand(3);
    for (int i = 1; i < 5; i++) {
        printf("round1=====%d\n", rand());
    }

    srand(3);
    for (int i = 1; i < 5; i++) {
        printf("round1=====%d\n", rand());
    }
    // 种子值固定，得到的序列也会是固定的
}

void test3() {
    // 时间是永不重复的
    // 我们可以把时间戳给srand当作种子值
    // 时间戳：从当前时间距离格林威治时间的秒数
    // 格林威治时间：1970-01-01 00:00:00

    printf("%d\n", time(NULL)); //time(NULL)就是当前的时间戳
}

void test4() {
    // 时间戳是一个公共的概念，其他的语言、数据库中都有这个概念
    // 使用时间戳时，要注意其是秒级时间戳还是毫秒级时间戳
    // 10位时间戳——秒级
    // 13位时间戳——毫秒级
}

void test5() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        printf("round1======%d\n", rand());
    }
    // srand(3);
    // rand();
    // srand(3);
    // rand();
}

void test6() {
    //srand(time(NULL));
    
    // 反例：不要反复设置种子值，尤其不能在循环中设置种子值
    for (int i = 0; i < 100; i++) {
        srand(time(NULL));  // 此处使用的是秒级时间戳
        printf("round1=====%d\n", rand()); // 一百次循环得到的“随机数”是一样的
        // 因为这个循环在一秒内能够运行几十万甚至更多次
    } 
}

void test7() {
    // rand() 生成的随机数是有范围的[0, RAND_MAX]
    // RAND_MAX; // 其值为 0x7fff，十进制为 32767
}

int main(void) {
    //test1();
    //test2();
    //test3();
    //test5();
    test6();
    return 0;
}