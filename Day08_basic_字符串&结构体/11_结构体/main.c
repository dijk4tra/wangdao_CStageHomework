#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct triangle {
    int edge1;
    int edge2;
    int edge3;

    double area;
}Triangle; // 大驼峰

void test1() {
    // 如果你不想每次写结构体的时候，都要写
    // struct triangle t1
    
    // 可以使用typedef
    Triangle t1;
}

void test2(struct triangle t1) {
    // sizeof(struct triangle);
}

void test3() {
    // 有了结构体别名之后，就可以直接使用结构体别名来。 
    Triangle t1;

    t1.area;
}

int main(void) {
    
    return 0;
}