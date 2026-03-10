#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // 引入 isspace() 函数，isspace() 会检查字符是否为空格、\t、\n 等空白字符

/*
编写一个函数，计算一个字符串中单词的数量。这里，单词被定义为由空格分隔的字符序列。
例如，对于字符串"hello world! word Excel space blank"
就应该输出有6个单词
注意：空格可能连续出现。
思路参考:
1.整个过程就是跳过前面的所有空白字符，先找到一个非空字符，然后再跳过所有非空字符找到一个空白字符，于是确定找到一个单词。
2.第二种思路: 遍历整个字符串，如果字符是非空格制表符，那么就是单词的一部分，继续遍历直到碰到空字符或者空格制表符，意味着单词结束，计数器加1
两种思路皆可。
*/

int count_word(const char *str) {
    int count = 0;
    int in_word_flag = 0; // 0表示在单词外部，1表示在单词内部

    while (*str != '\0') {
        // isspace() 会检查字符是否为空格、\t、\n 等空白字符
        if (isspace(*str)) {
            in_word_flag = 0; // 遇到空白字符，标记当前处于单词外部
        }
        else if(in_word_flag == 0){
            // 遇到了非空白字符，且之前在单词外部，这说明找到了新单词的开头
            in_word_flag = 1; //标记进入单词内部
            count++; // 单词数加1
        }
        str++;
    }
    return count;
}


int main(void) {
    
    char str[] = "hello world! word Excel space blank";

    printf("该字符串中的单词的数量为：%d", count_word(str));

    return 0;
}