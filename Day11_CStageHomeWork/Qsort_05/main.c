#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 包含 qsort, malloc, free
#include <string.h> // 包含 strcmp, strlen, strcat

/*
首先给定以下字符数组：
char* strings[] = {
 "4show ",
 "1code.",
 "5cheap, ",
 "6is ",
 "7Talk ",
 "2the ",
 "3me "
};
请你先利用qsort函数将此字符串数组，按照逆字典顺序排序。然后将这个字符串数组中的每一个字符串，按照从前到后的顺序，拼接组装成一个新字符串，并且在拼接时删除每个子字符串的第一个字符。
这样你将得到Linux之父Linus Torvalds的名言：“Talk is cheap, show me the code.”
要求使用动态分配内存来存储结果字符串，函数声明如下：
char* concat_strs(char* strings[], int count);
*/

// qsort 所需的比较函数
// qsort 传递的是数组元素的地址。因为数组元素是 char*(指向字符串首地址的指针)，所以参数是 char**(二级指针)
int compare_str(const void *a, const void *b) {
    // (const char**)a：告诉编译器，虽然a是void*，但需要把它看作是一个 char**（指向指针的指针）”
    // 再解引用 *(char **)a，就可以取到字符串真正的起始地址
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;

    return strcmp(str2, str1); // 逆序（从大到小排序）

}

// 拼接函数
char *concat_strs(char *strings[], int size) {
    int total_length = 0;

    // 计算拼接后的总长度（需减去每个字符串的首字符，并加上最后的 '\0'）
    for (int i = 0; i < size; i++) {
        // strlen(strings[i]) - 1 是去掉首位数字后的长度
        total_length += (strlen(strings[i]) - 1);
    }
    total_length = total_length + 1; //+1 是为了存放字符串结束符 '\0'

    // 动态分配内存
    char *concat_result = malloc(total_length * sizeof(char));
    if (concat_result == NULL) {
        printf("malloc failed in concat_strs");
        return NULL; // 内存分配失败处理
    }

    // 开始拼接
    concat_result[0] = '\0'; // 确保初始是一个空字符串，方便后续 strcat
    for (int i = 0; i < size; i++) {
        // strings[i] + 1 表示跳过第一个字符，从第二个字符开始拷贝
        strcat(concat_result, strings[i] + 1);
    }
    return concat_result;
}

int main(void) {
    
    char *strings[] = {
         "4show ",
         "1code.",
         "5cheap, ",
         "6is ",
         "7Talk ",
         "2the ",
         "3me "
    };

    int size = sizeof(strings) / sizeof(strings[0]);
    // 按照逆字典顺序排序
    qsort(strings, size, sizeof(char *), compare_str);
    // 拼接
    char *final_sentence = concat_strs(strings, size);
    printf("%s\n", final_sentence);
    free(final_sentence);

    return 0;
}