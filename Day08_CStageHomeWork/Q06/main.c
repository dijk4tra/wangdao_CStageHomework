#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 通过命令行参数传递额外的三个参数：10 8.8 hello

int main(int argc, char *argv[]) {
    // 题目一：输出参数个数，并循环打印参数数组
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // 确保输入了足够的参数 (程序名本身算1个，外加3个额外参数，共4个)
    if (argc < 4) {
        printf("\n提示：请提供足够的命令行参数！\n");
        return 1; // 异常退出
    }

    // 题目二：使用 sscanf 进行数据类型转换
    int num1;
    double num2;

    // argv[1] 对应传入的 "10"，使用 %d 将其转换为 int 存入 num1
    sscanf(argv[1], "%d", &num1);

    // argv[2] 对应传入的 "8.8"，使用 %lf 将其转换为 double 存入 num2
    // 注意：读取 double 类型必须用 %lf
    sscanf(argv[2], "%lf", &num2);

    // 题目三：计算和，并使用 sprintf 构建最终字符串-
    // 计算前两个参数之和
    double sum = num1 + num2;

    // 定义一个字符数组，存放拼接后的字符串
    char resultString[100];

    // 使用 sprintf 将各种类型的数据格式化后写入 resultString 数组
    // %d   对应 num1 (10)
    // %.1f 对应 num2 (保留1位小数即 8.8)
    // %.2f 对应 sum  (保留2位小数即 18.80)
    // %s   对应 argv[3] (也就是字符串 "hello")
    sprintf(resultString, "%d + %.1f = %.2f%s", num1, num2, sum, argv[3]);

    // 打印构建好的字符数组
    printf("结果字符串: %s\n", resultString);

    return 0;
}