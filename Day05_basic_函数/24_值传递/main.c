#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change_int_by_int(int num) {
    num = 987654;
    printf("%d\n", num);
}

void change_int_by_pointer(int *p1){
    *p1 = 665544;
    printf("change_int_by_pointer = %d\n", *p1);
}

void change_pointer_by_pointer() {
    // 后续会学到
}

int main(void) {

    int a = 123;
    change_int_by_int(a);
    // a不会变化
    // printf("main = %d\n",a);

    int *p123 = &a;
    change_int_by_pointer(p123); // a发生了变化
    printf("main = %d\n",a);


    return 0;
}