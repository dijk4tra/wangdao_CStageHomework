#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // fwrite：写，是以二进制模式写
    int arr[] = { 10,11,12,13,14,15 };
    // 00 00 00 0a

    FILE *fp = fopen("1.dat", "wb");

    if (fp == NULL) {
        printf("fopen failed.");
        return;
    }

    size_t ret = fwrite(arr, sizeof(int), 6, fp);

    printf("%d", ret);
    fclose(fp);
}

void test2() {
    FILE *fp = fopen("1.dat", "rb");

    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    // 13个int
    int arr[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

    size_t ret = fread(arr, sizeof(int), 13, fp);

    printf("ret = %d\n", ret);

    fclose(fp);

}

typedef struct student {
    int id;
    char name[25];
    int chinese;
    int math;
}Student;


// 如果有一个结构体，能否直接用 fwrite 将其写出？
// 序列化/反序列化 
// 编码/解码
void test3() {
    // 1. 初始化结构体数据
    Student s1 = { 1001, "Zhang San", 95, 88 };

    // 2. 打开文件（wb 表示以二进制覆盖写入）
    FILE *fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        perror("文件打开失败");
        return;
    }

    // 3. 写入结构体
    // &s1: 结构体的地址
    // sizeof(Student): 一个结构体占用的大小
    // 1: 写入 1 个结构体
    size_t ret = fwrite(&s1, sizeof(Student), 1, fp);

    if (ret == 1) {
        printf("结构体写入成功！\n");
    }

    // 4. 记得关闭文件，否则数据可能还在缓冲区没进硬盘
    fclose(fp);

    // --- 验证：立即读回数据 ---
    Student s2;
    fp = fopen("student.dat", "rb");
    if (fp != NULL) {
        fread(&s2, sizeof(Student), 1, fp);
        printf("读回的数据：ID=%d, 姓名=%s, 数学=%d\n", s2.id, s2.name, s2.math);
        fclose(fp);
    }
}

int main(void) {

    //test1();
    //test2();
    test3();

    return 0;
}