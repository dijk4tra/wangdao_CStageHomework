#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 如果光申请内存，使用完毕之后，不释放内存，最终会导致内存泄漏
    // 就是程序中可用的内存越来越少，最终会导致程序无法运行

    // 所以，我们在使用完毕内存之后，一定要记得及时释放

    int *p = malloc(24);

    if (p == NULL) {
        printf("malloc failed.");
        return;
    }

    for (int i = 0; i < 6; i++) {
        p[i] = i + 100;
        printf("%d\n", p[i]);
    }

    // 使用完毕之后，一定要记得释放
    free(p);
}

void test2() {
    // free 只能传入堆区的数据，不能传栈区的数据
    // 1.不要将栈区的数据放进去
    // 2.只能放申请得到的堆区的首字节指针
    // 3.如果传递的不是首字节指针，同样会报错

    //int arr[10] = { 10,11,12,13 };
    //free(arr);
    //int *p = arr;
    //free(p);

    int *p = malloc(24);

    for (int i = 0; i < 6; i++) {
        p[i] = i + 100;
        printf("%d\n", p[i]);
    }

    // p指针，动了没有？
    //free(p);  // 现在p指针还是指向首字节地址

    *p++ = 10;
    *p++ = 20;

    free(p);    // p指针已经不是指向首字节地址，会报错

}

void test3() {
    // 如果你习惯使用挪指针的写法
    // 建议再定义一个指针，存储旧指向
    // 最后再释放旧指针

    int *p = malloc(24);

    int *old_p = p;

    *p++ = 10;
    *p++ = 11;
    *p++ = 12;
    *p++ = 13;
    *p++ = 14;

    free(old_p);
}

void test4() {
    
    // 不能不free，也不能二次free
    int *p = malloc(24);

    int *old_p = p;

    p[0] = 10;
    p[0] = 11;
    p[0] = 12;
    p[0] = 13;
    
    free(p);
    free(old_p); // double free会报错

}

int main(void) {
    
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}