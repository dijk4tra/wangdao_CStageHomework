#include <stdio.h>

int main() {
    // 初始化字符串数组a，并赋值
    char a[100] = "My name is Li jilin.";
    // 初始化字符串数组b，并赋值（编译器会自动计算b的长度）
    char b[] = "Mr. Zhang Haoling is very happy.";

    // 将从1开始的索引转换为从0开始的数组索引
    int startB = 5 - 1;  // 提取b的第5个字符（包括空格），对应下标4
    int endB = 17 - 1;   // 提取b的第17个字符（包括空格），对应下标16
    int startA = 12 - 1; // 从a的第12个字符位置开始替换，对应下标11
    int i, j; // 循环变量：i用于a的索引，j用于b的索引

    // 循环将b中指定片段复制到a的指定位置
    for (i = startA, j = startB; j <= endB; i++, j++) {
        a[i] = b[j]; // 将b[j]的字符赋值给a[i]
    }
    // 在复制完成后，手动添加字符串结束符'\0'，确保a是一个有效的字符串
    a[i] = '\0';
    // 输出替换后的新字符串
    printf("新字符串: %s\n", a);
	return 0;
}