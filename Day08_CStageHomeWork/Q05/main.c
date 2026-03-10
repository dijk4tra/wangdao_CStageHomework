#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
在main函数当中，先写出下列代码，用两种不同的方式来定义实现字符串数组：
// char类型二维数组实现字符串数组
char fruits1[][10] = {
"apple",
"banana",
"cherry"
};

// char*指针数组实现字符串数组
char *fruits2[] = {
"apple",
"banana",
"cherry"
};

请完成以下编程或者回答相应的问题。
题目一：
请分别遍历 fruits1 和 fruits2 这两个字符串数组，输出每个字符串的内容及其长度。

题目二：
请分别将两个字符串数组中的第一个字符串，修改成"orange"。
首先你需要回答：基于"="运算符直接赋值修改，能不能完成这样的操作？如果不能为什么？
提示：通过一定的手段，两个都可以完成修改。参考代码仅提供一种实现方式，若你能够实现，亦可采用自己的实现。

题目三：
请分别将两个字符串数组中的第二个字符串"banana"中的第一个字符'b'，修改成'B'。
首先你需要回答：基于"="运算符直接赋值修改，能不能完成这样的操作？如果不能为什么？

题目四：
请自行定义初始化一个字符串数组fruits3，使得这个字符串数组既可以通过"="直接修改整个字符串的内容，也可以利用"="修改某个字符串的某个字符。

*/



int main(void) {
    // 方式一： char类型二维数组实现字符串数组（分配了连续的内存空间，可读写）
    // 内存分配：在栈区（可读写内存）分配了一块连续的内存空间（3行 × 10列 = 30个字节）
    char fruits1[][10] = {
        "apple",
        "banana",
        "cherry"
    };

    // 方式二：char*指针数组实现字符串数组（数组里存的是指针，指向只读的字符串常量）
    // 内存分配：在栈区只分配了一个指针数组（包含3个指针变量）。而 "apple"、"banana" 等字符串本身，被存储在操作系统的常量区（只读数据段，RODATA）
    char *fruits2[] = {
        "apple",
        "banana",
        "cherry"
    };

    // 题目一
    printf("题目一：\n");

    // sizeof 计算数组大小：用整个数组占用的总字节数，除以单个元素占用的字节数，从而得出数组的长度。
    // strlen 计算字符串长度：从给定地址开始向后逐个字符扫描，直到遇到字符串结束标志 \0（空字符）为止。

    // 计算数组元素的个数
    int size1 = sizeof(fruits1) / sizeof(fruits1[0]);
    printf("数组fruits1每个字符串的内容及其长度:\n");
    for (int i = 0; i < size1; i++) {
        printf("字符串内容：%s，长度：%d\n", fruits1[i], strlen(fruits1[i]));
    }

    int size2 = sizeof(fruits2) / sizeof(fruits2[0]);
    printf("\n数组fruits2每个字符串的内容及其长度:\n");
    for (int i = 0; i < size2; i++) {
        printf("字符串内容：%s，长度：%d\n", fruits2[i], strlen(fruits2[i]));
    }

    // 题目二
    printf("\n题目二：\n");
    // fruits1[0] = "orange"; // 不能这样操作，因为fruits1[0]是一个字符数组的名字，在C语言中，数组名代表的是数组首元素的地址，它是一个常量，不能作为左值被'='重新赋值
    strcpy(fruits1[0], "orange"); // 正确操作方式：拷贝字符串到该内存区

    fruits2[0] = "orange"; // 可以这样操作，因为fruits2[0]是一个char*类型的指针变量，指针变量可以直接用'='指向新的字符串常量
    
    printf("修改后 fruits1[0]: %s\n", fruits1[0]);
    printf("修改后 fruits2[0]: %s\n", fruits2[0]);

    // 题目三
    printf("\n题目三：\n");
    // fruits1 是存储在可读写区的二维数组，可以直接修改单个字符
    fruits1[1][0] = 'B';
    // fruits2[1][0] = 'B'; // 不能这样操作，程序会崩溃，因为原本指向的是只读常量
    // 解决手段：让该指针指向一个全新的常量字符串，或者指向一个可变数组
    // 重新指向一个新的字符串常量
    fruits2[1] = "Banana";

    printf("修改后 fruits1[1]: %s\n", fruits1[1]);
    printf("修改后 fruits2[1]: %s\n", fruits2[1]);

    // 题目四
    printf("\n题目四：\n");
    // 先定义三个独立的、存在于可读写内存区（栈区）的字符数组
    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "cherry";
    // 然后定义一个指针数组，指向这三个可读写的数组
    char *fruits3[] = { str1,str2,str3 };
    // 这个字符串数组fruits3[]既可以通过"="直接修改整个字符串的内容，也可以利用"="修改某个字符串的某个字符

    // 利用 '=' 直接修改整个字符串的内容（改变指针朝向）
    fruits3[0] = "orange";
    printf("fruits3[0] 整体修改后: %s\n", fruits3[0]);

    // 利用 '=' 修改某个字符串的某个字符（因为 str2 是可读写的数组）
    fruits3[1][0] = 'B';
    printf("fruits3[1] 单字符修改后: %s\n", fruits3[1]);


    return 0;
}