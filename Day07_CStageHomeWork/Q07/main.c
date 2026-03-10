#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // 引入函数 tolower()

/*
给定一个字符串，要求它可能包含数字和字母。
请编写函数，统计该字符串中每个字符出现的次数，统计过程中忽略大小写的差异，并打印最终每个字符出现的次数。
提示：
用一个int数组存储字符出现的次数，可以用一个128长度的数组，这样数组下标位置的元素就是该编码值字符出现的次数，缺点是浪费空间，但你可以先写一个这样的实现。
扩展
实际上只会有36个字符(10个数字和26个不区分大小写的字母)，所以int数组的长度实际上只需要36就可以了。
那么怎么把数组的长度缩短到36呢？
*/

void count_characters(const char *str) {
    // 下标对应字符的 ASCII 码值，数组元素存储该字符出现的次数
    int count[128] = { 0 };
    
    // 遍历字符串
    while (*str != '\0') {
        // 将字符统一转换为小写
        char ch = tolower(*str);
        if (ch >= 0 && ch <= 128) {
            count[ch]++;
        }
        // 指针后移，检查下一个字符
        str++;
    }

    for (int i = 0; i < 128; i++) {
        // 如果该字符出现过（次数大于0），则打印
        if (count[i] > 0) {
            printf("字符'%c'出现的次数为：%d\n", i, count[i]);
        }
    }
}

void count_characters_36(const char *str) {
    // 长度为36的数组，0-9存数字，10-35存字母，数组元素存储该字符出现的次数
    int count[36] = { 0 };

    // 遍历字符串
    while (*str != '\0') {
        // 将字符统一转换为小写
        char ch = tolower(*str);

        // 用函数isdigit()判断是否为数字并映射
        if (isdigit(ch)) {
            count[ch - '0']++;
        }
        // 用函数isalpha()判断是否为字母并映射
        else if (isalpha(ch)) {
            count[ch - 'a' + 10]++;
        }
        str++;
    }

    for (int i = 0; i < 36; i++) {
        if (count[i] > 0) {
            char original_char;

            // 打印时，需要把下标原本的字符的ASCII码值
            if (i < 10) {
                // 下标 0-9 还原为字符 '0'-'9'
                original_char = i + '0';
            }
            else {
                // 下标 10-35 还原为字符 'a'-'z'
                original_char = (i - 10) + 'a';
            }
            printf("字符'%c'出现的次数为：%d\n", original_char, count[i]);
        }
    }
}


int main(void) {

    char str[] = "hEllo0world23fxvjioe986eImckjnurBrouriWYtioqevty151646fsr32vs";

    //count_characters(str);

    count_characters_36(str);

    return 0;
}