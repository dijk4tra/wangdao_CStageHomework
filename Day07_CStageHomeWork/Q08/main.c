#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
依照C语言的字符串标准库函数，手动实现以下函数：
    size_t my_strlen(const char *str);
    char *my_strcpy(char *dest, const char *src);
    char *my_strncpy(char *dest, const char *src, size_t n);
    char *my_strcat(char *dest, const char *src);
    char *my_strncat(char *dest, const char *src, size_t n);
    int my_strcmp(const char *str1, const char *str2);
函数的实现要模拟标准库函数中对应函数的行为，不要依据自己的理解来实现这些函数。
*/


// strlen：计算字符串str的长度，不包括结尾的空字符 '\0'
// 使用指针遍历字符串，直到遇到 '\0' 为止，记录遍历的次数
size_t my_strlen(const char *str) {
    size_t count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

// strcpy：将源字符串src复制到dest，必须包含结尾的 '\0'。返回目标字符串的首地址（dest的指针）
// 逐字符复制，直到源字符串的 '\0'
char *my_strcpy(char *dest, const char *src) {
    char *ret = dest;  // 目标字符串的首地址，用于在最后返回

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // 最后在目标字符串末尾加上 '\0'
    *dest = '\0';

    return ret;
}

// strncpy：最多复制n个字符。如果源字符串src长度小于n，则在目标字符串后面追加 '\0'，直到总共写入了n个字符
// 先循环复制字符，每次递减n。如果提前遇到 '\0'，则继续用 '\0' 填充剩余的n个空间
char *my_strncpy(char *dest, const char *src, size_t n) {
    char *ret = dest;

    // 最多复制n个字符
    while (*src != '\0' && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    // 如果src的长度小于n，用 '\0' 填充剩余的空间
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return ret;
}

// strcat：将源字符src串追加到目标字符串dest的结尾。目标字符串原有的 '\0' 会被覆盖，并在追加后的新字符串末尾添加完整的 '\0'
// 先将目标指针移动到原字符串的 '\0' 处，然后开始逐字节复制源字符串
char *my_strcat(char *dest, const char *src) {
    char *ret = dest;

    // 找到dest的末尾
    while (*dest != '\0') {
        dest++;
    }
    // 复制字符
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // 最后在目标字符串末尾加上 '\0'
    *dest = '\0';

    return ret;
}

// strncat：最多追加n个字符，并始终在最后追加一个 '\0'。如果源字符串src长度小于n，则仅追加源字符串本身的内容（包含结尾的 '\0'）
// 找到目标字符串结尾，然后最多复制n次
char *my_strncat(char *dest, const char *src, size_t n) {
    char *ret = dest;
    
    // 找到dest的末尾
    while (*dest != '\0') {
        dest++;
    }
    // 最多复制n个字符
    while (*src != '\0' && n > 0 ) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    // 最后在目标字符串末尾加上 '\0'
    *dest = '\0';

    return ret;
}

// strcmp：比较两个字符串，若相等返回 0；若 str1 大于 str2 返回正数；若 str1 小于 str2 返回负数
// 逐字符比较，直到遇到不同的字符或者遇到 '\0'。返回当前指向字符的 ASCII 码差值
int my_strcmp(const char *str1, const char *str2) {

    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}


int main(void) {
    char str1[100] = "Hello";
    char str2[] = " World";
    char dest1[20];
    char dest2[20];

    // my_strlen
    printf("Length of str1: %zu\n", my_strlen(str1));

    // my_strcpy
    my_strcpy(dest1, str1);
    printf("my_strcpy result: %s\n", dest1);

    // my_strncpy
    my_strncpy(dest2, "hello", 10);
    printf("my_strncpy result: %s\n", dest2);

    // my_strcat
    my_strcat(str1, str2);
    printf("my_strcat result: %s\n", str1);

    // my_strncat
    char str3[100] = "Hello ";
    my_strncat(str3, "World", 3);
    printf("my_strncat result: %s\n", str3);

    // my_strcmp
    printf("Compare 'helloworld' and 'helloworld': %d\n", my_strcmp("helloworld", "helloworld"));
    printf("Compare 'helloworld' and 'hellow0rld': %d\n", my_strcmp("helloworld", "hellow0rld"));
    
    return 0;
}