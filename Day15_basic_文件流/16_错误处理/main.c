#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>

void test1() {
    printf("errno1 = %d", errno);
    printf("----------%s\n", strerror(errno));
    
    // C中没有错误处理
    // 基本上只能通过返回值告诉你出错了
    FILE *fp = fopen("1.txt", "r");
    printf("errno2 = %d", errno);
    printf("----------%s\n", strerror(errno));
    printf("----------%s\n", strerror(1));
    printf("----------%s\n", strerror(2));
    printf("----------%s\n", strerror(3));
    printf("----------%s\n", strerror(4));
    // fp 有两种情况
    // 如果打开失败了，是什么原因导致的失败？

    // C提供了一个全局变量，就是用于记录错误原因
    // 出错时可以通过这个全局变量来查明原因
}

void test2() {
    // 直接让它打印错误信息
    // void perror(const char *s);
    perror("1111");
    FILE *fp = fopen("1.txt", "r");
    perror("1.txt");

    // perror用于打印信息。 给进去的字符串，就是特征性的描述。 你自己的描述。 
}

int main(void) {

    //test1();
    test2();

    return 0;
}