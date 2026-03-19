#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 文件流：其实就是一个流，用于方便的在程序中读取外部数据，或者说向外部输出数据
    FILE *fp = fopen("1.txt", "r");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    int ch;
    // EOF: End of File
    // while ((ch = fgetc(fp)) != -1){}
    while ((ch = fgetc(fp)) != EOF) {
        printf("=============%c\n", ch);
    }
    fclose(fp);
}

void test2() {
    // mode
    // r w a: read write append
    // r：文件存在则打开成功；文件不存在则打开失败
    // w：文件存在则打开成功，且文件原有内容会被清空；文件不存在则创建文件
    // a：只在文件内容尾部追加内容，不会清空文件原有内容

    FILE *fp = fopen("1.txt", "r");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("=========%c\n", ch);
    }
    fclose(fp);
}

void test3() {
    // windows 的换行符和C语言中的不一样。 

    // windows: \r\n  
    // C: \n
    // Linux: \n
    // Mac: \r

    // fputc('\n', fp);
    // 特殊符号的转换过程。 

    // b: 二进制的模式。 文件中，是什么内容，就读什么出来。不会进行任何转换
    // 读一些二进制数据的时候，建议使用。 图片，视频，音乐，压缩包
}

int main(void) {
    test1();
    return 0;
}