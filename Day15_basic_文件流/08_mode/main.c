#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // r 表示读
    // w 表示写
    // a 表示追加
}

void test2() {
    // r 读，只能读
    // 如果是以读模式打开，文件存在则打开成功，文件不存在则打开失败
    FILE *fp = fopen("1.txt", "r");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }
}

void test3() {
    // w 写。如果文件存在，则打开成功且会清空文件原有内容
    // 如果文件不存在，则会新建文件

    //FILE *fp = fopen("2.txt", "w");
    FILE *fp = fopen("222.txt", "w");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    printf("fopen succeeded.\n");

    fclose(fp);
}

void test4() {
    // a 追加

    FILE *fp = fopen("333.txt", "a");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    printf("fopen succeeded.\n");

    fputc('z', fp);
    fputc('x', fp);
    fputc('y', fp);

    fclose(fp);
}

void test5() {
    // 不建议使用混合模式。  r+ w+ a+
    // 因为极其容易出问题，且很让人困惑

    FILE *fp = fopen("444.txt", "r+");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    printf("ch1 = %c\n", fgetc(fp));
    printf("ch2 = %c\n", fgetc(fp));
    printf("ch3 = %c\n", fgetc(fp));

    fputc('1', fp);
    fputc('2', fp);
    fputc('3', fp);
    fputc('4', fp);
    fputc('5', fp);
    fputc('6', fp);
    fputc('7', fp);

    // 模式尽量只使用读，或者写，或者追加。 
    // 不要开读写。 一会读一会写，很容易翻车。 
    // 比如这里就只会写入4567，123并没有被写入文件中！
    fclose(fp);

}

int main(void) {
    
    //test3();
    //test4();
    test5();

    return 0;
}