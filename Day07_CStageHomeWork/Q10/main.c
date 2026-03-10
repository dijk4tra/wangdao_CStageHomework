#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
编写一个函数，检查给定的字符串中的圆括号()是否正确匹配。注意只考虑小括号，字符串中没有其它括号。
如字符串：((Hello) (World))
函数会返回一个布尔值，表示匹配成功或失败
注意：只考虑英文小括号()，不需要考虑其它括号，更不需要考虑中文符号。
*/

bool is_parentheses_match(const char *str) {
    int count = 0; // 记录括号数量

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            count++; // 遇到左括号，计数器加1
        }
        else if (str[i] == ')') {
            count--; // 遇到右括号，计数器加1

            // 如果右括号比左括号多，或者提前出现了右括号，则匹配失败
            if (count < 0) {
                printf("括号匹配失败！原因：右括号比左括号多，或者提前出现了右括号。");
                return false;
            }
        }
    }
    // 遍历结束，如果count为0说明括号全部匹配，否则说明左括号多余
    if (count == 0) {
        printf("括号匹配成功！");
        return true;
    }
    else {
        printf("括号匹配失败！原因：左括号比右括号多。");
        return false;
    }
}


int main(void) {
    const char *test1 = "((Hello) (World))";
    const char *test2 = "((Hello)";
    const char *test3 = ")Hello(()";

    is_parentheses_match(test3);

    return 0;
}