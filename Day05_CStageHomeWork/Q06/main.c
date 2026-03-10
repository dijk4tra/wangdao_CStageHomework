#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1.汉诺塔问题：
有三根杆子A，B，C。A杆上有 N 个 (N>1) 穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至 C 杆：
    1.每次只能移动一个圆盘;
    2.大盘不能叠在小盘上面。
利用递归的方式，打印出移动轨迹。
*/

// 该函数用于将n个盘子从start塔移动到target塔以完成汉诺塔问题,sup是辅助移动的塔
void move(int n, char start, char sup, char target) {
    /*
    * 递归出口
    * 此时只有一个最大的盘子在塔start
    * 所以只需要将盘子从start --> target
    */
    if (n == 1) {
        printf("%c --> %c\n", start, target);
        return;
    }
    /*递归分解，递归体, 要想完成n个盘子的汉诺塔问题需要*/
    // 第一步: 将n-1个盘子从start塔移动到sup塔,target塔用于辅助
    move(n - 1, start, target, sup);
    // 第二步: 将最大的盘子从start移动到target,直接打印即可
    printf("%c --> %c\n", start, target);
    // 第三步: 将n-1个盘子从sup塔移动到target,start塔用于辅助
    move(n - 1, sup, start, target);
}

void hanoi_track(int n) {
    long long steps = (1LL << n) - 1;
    printf("完成%d个盘子的汉诺塔问题，最少需要%lld步，全部移动轨迹如下：\n", n, steps);

    move(n, 'A', 'B', 'C');
}



/*
2.十进制转换成二进制
给定任意一个非负十进制整数，请利用递归的方式，求解它的二进制表示方式
基本的思路是：把该整数除以2得到余数，然后倒着输出余数。
思考一下：如何实现倒着打印余数呢？
*/

void decimal_to_binary(int n) {
    // 终止条件：当商大于1时，继续递归
    if (n > 1) {
        decimal_to_binary(n / 2);
    }
    // 内层递归结束时，才会运行到这里
    // 打印余数当前层的余数，直接实现了倒着打印余数
    printf("%d", n % 2);
}

int main(void) {
    //1.汉诺塔
    int n = 1;
    printf("请输入汉诺塔的层数: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("输入错误，请输入非负正整数。\n");
    }
    else {
        hanoi_track(n);
    }
    

    //2.十进制转换成二进制
    int num;
    printf("\n请输入一个非负十进制整数: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("输入错误，请输入非负整数。\n");
    }
    else {
        printf("十进制数 %d 的二进制表示为: ", num);
        decimal_to_binary(num);
    }
    return 0;
}