#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 按照字符串的长度，从长到短排序
int compare_length_1(const void *a, const void *b) {
    // ptr中的数据本身就是指向字符串的指针char *
    // 因此现在传入的 a 和 b 是指向指针的指针 (char **)
    // 所以需要先强转为const char **，再解引用*取出里面的const char *
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    return len2 - len1; // 降序排序，所以用len2 - len1

}

// 先按照字符串的长度从短到长排序，长度一致的字符串按照字典顺序排序
int compare_length_2(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == len2) {
        return strcmp(str1, str2); // 长度一致的字符串按照字典顺序排序
    }
    return len1 - len2; // 升序排序，所以用len1 - len2
}


int main(void) {
    int n;
    printf("请输入字符串数组的长度：");
    scanf("%d", &n);
    getchar();  // 去掉多输入的换行符 \n

    // 使用指针数组来存储各字符串的首地址
    // ptrs 是一个指向指针的指针，它存放了n个 char* 类型的空间
    char **ptrs = (char **)malloc(n * sizeof(char *));
    if (ptrs == NULL) {
        printf("malloc failed.");
        return 1;
    }

    // 临时缓冲区，用于接住用户的输入
    char buffer[1025];

    // 循环录入用户输入的字符串，并为每个字符串动态分配内存
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个字符串：", i + 1);

        // 将输入读入临时缓冲区
        fgets(buffer, 1025, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // 将字符串最后的换行符 \n 替换为 \0

        // 计算字符串的长度
        int exact_length = strlen(buffer) + 1; // +1是为了算上字符串结束符 \0

        // 为这个字符串分配内存空间
        ptrs[i] = (char *)malloc(exact_length * sizeof(char));
        if (ptrs[i] == NULL) {
            printf("malloc failed.\n");
            free(ptrs);
            return 1;
        }

        // 将缓冲区里的内容，复制到刚刚申请好的内存空间中
        strcpy(ptrs[i], buffer);
    }

    qsort(ptrs, n, sizeof(char *), compare_length_1);
    printf("\n按长度从长到短排序的结果：\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", ptrs[i]);
    }

    qsort(ptrs, n, sizeof(char *), compare_length_2);
    printf("\n按长度从短到长排序，长度一致时按字典顺序的结果：\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", ptrs[i]);
    }

    // 先释放每一个字符串实体，最后释放指针数组ptrs
    // 如果先释放了ptrs，就再也找不到那些字符串实体了（导致内存泄漏）

    for (int i = 0; i < n; i++) {
        free(ptrs[i]); // 释放每个字符串
    }
    free(ptrs);        // 释放指针数组ptrs

    return 0;
}