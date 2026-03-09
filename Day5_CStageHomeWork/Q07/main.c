#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
现在你已经知道如何打印n个盘子汉诺塔问题的移动轨迹了，那么在这个的基础上，我们进行以下扩展：
对于n个盘子的汉诺塔问题，给定一个整数m，要求在控制台打印出m + 1步的移动轨迹。
提示：
既然要打印m + 1步的移动轨迹，那么肯定需要计数器记录移动的步骤，需要用什么变量呢？
核心思路就还是move函数的递归，但要加上一个计数器，实际编码时注意边界值就可以了。
*/

// 该函数用于将n个盘子从start塔移动到dest塔以完成汉诺塔问题,sup是辅助移动的塔
void move(int n, char start, char sup, char dest, long long target_step) {
    
    static long long move_number = 0; // 当前移动的步数计数器

    // 如果已经达到目标步数，直接返回
    if (move_number >= target_step) {
        return;
    }
    
    /*
    * 递归出口
    * 此时只有一个最大的盘子在塔start
    * 所以只需要将盘子从start --> dest
    */
    if (n == 1) {
        move_number++;
        if (move_number == target_step) {
            // 外层已经打印了前缀，这里只打印轨迹
            printf("%c --> %c\n", start, dest);
        }
        return;
    }

    /*递归体*/
    // 第一步: 将n-1个盘子从start塔移动到sup塔, dest塔用于辅助
    move(n - 1, start, dest, sup, target_step);

    if (move_number >= target_step) {
        return;
    }

    // 第二步: 将最大的盘子从start移动到dest
    move_number++;
    if (move_number == target_step) {
        printf("%c --> %c\n", start, dest);
        return; // 找到后直接返回
    }

    // 第三步: 将n-1个盘子从sup塔移动到dest, start塔用于辅助
    move(n - 1, sup, start, dest, target_step);
}

void hanoi_track(int n, long long m) {
    long long total_steps = (1LL << n) - 1; // 总步数：2^n - 1
    long long target_step = m + 1;          // 目标步数是 m + 1

    if (target_step > total_steps) {
        printf("输入的步数超出了总步数 %lld，无法移动。\n", total_steps);
        return;
    }

    printf("%d个盘子的汉诺塔问题，第%lld步的移动轨迹是：", n, target_step);

    // 传入的 A B C 分别对应 start, sup, dest
    move(n, 'A', 'B', 'C', target_step);
}

int main(void) {
    int n = 1;
    long long m = 0;

    printf("请输入汉诺塔的层数 n 和整数 m (将打印第 m+1 步的轨迹):");
    
    if (scanf("%d %lld", &n, &m) != 2) {
        printf("输入格式错误。\n");
        return 1;
    }

    if (n <= 0 || m < 0) {
        printf("输入错误，请输入正整数层数和非负整数步骤。\n");
    }
    else {
        hanoi_track(n, m);
    }

    return 0;
}