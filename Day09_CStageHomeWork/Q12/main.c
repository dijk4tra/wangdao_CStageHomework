#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
标准库函数strcat会将一个字符串追加到另一个字符串的末尾。
现在我们编写一个函数把两个字符串拼接起来，返回拼接的结果，但要求不改变其中任何一个字符串。其函数声明如下：
char* my_strcat(const char* prefix, const char* suffix);
形参prefix表示前缀，suffix表示后缀，拼接的结果是prefix + suffix
比如：my_strcat("abc", "d")，拼接的结果是"abcd"。
思路：
    1.在堆上分配内存空间，用于存储结果字符串。
    2.将prefix和suffix两个字符串的字符信息复制进去。
*/

char *my_strcat(const char *prefix, const char *suffix) {

    int len1 = strlen(prefix);
    int len2 = strlen(suffix);
    // 在堆上分配足够大的内存空间
    char *result_p = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    if (result_p == NULL) {
        printf("malloc failed !");
        return NULL;
    }

    int i, j;
    // 复制前缀prefix到结果内存空间
    for (i = 0; i < len1; i++) {
        result_p[i] = prefix[i];
    }
    // 继续复制后缀suffix拼接至结果内存空间
    for (j = 0; j < len2; j++) {
        result_p[i + j] = suffix[j];
    }
    // 注意：记得最后加上字符串的结束符 '\0'
    result_p[i + j] = '\0';

    return result_p;
}

int main(void) {

    char *prefix = "abcfsdlkfj9ruq9";
    char *suffix = "000dgsdgoigjo";

    char *str_p = my_strcat(prefix, suffix);

    
    printf("前缀: %s\n", prefix);
    printf("后缀: %s\n", suffix);
    printf("拼接后的结果: %s\n", str_p);

    free(str_p);
    str_p = NULL;
   
    return 0;
}