#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum vip_status{
    SVIP_0 = 1000,
    SVIP_1,
    SVIP_2,
    SVIP_3,
    SVIP_4

};

int limit_speed(enum vip_status status) {
    if (status == SVIP_0) {
        return 10;
    }
    else if (status == SVIP_1) {
        return 100;
    }
    else if (status == SVIP_2) {
        return 500;
    }
    else if (status == SVIP_3) {
        return 1500;
    }
    else if (status == SVIP_4) {
        return 3000;
    }
}

void test1() {
    printf("%d\n", SVIP_0);
    printf("%d\n", SVIP_1);
}

typedef enum {
    RED,
    BLACK,
    GREEN
}Color1;

typedef enum {
    TEST1, TEST2, TEST3
}Color2;


void test2() {
    // 枚举的本质，就是一个int
    // 它的类型非常弱

    // 使用它自己的类型给它初始化，不要瞎玩

    Color1 c1 = RED;

    c1 = TEST1;

    if (c1 == RED) {
        printf("red color.\n");
    }

}

int main(void) {
    
    //test1();
    test2();

    return 0;
}