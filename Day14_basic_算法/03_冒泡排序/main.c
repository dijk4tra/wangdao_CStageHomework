#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h> // 引入布尔类型 bool, true, false

/**
 * 【宏定义工具栏】
 * ARR_LEN: 自动计算数组元素个数。原理：数组总字节数 / 单个元素字节数
 * SWAP: 使用大括号封装的交换逻辑，防止在 if/else 中调用时出现语法逻辑错误
 */
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define SWAP(arr, i, j) { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
}

 /**
  * 辅助函数：打印数组
  * @param arr 数组首地址
  * @param len 数组长度
  */
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/**
 * 冒泡排序 (Bubble Sort) - 升序
 * 思路：通过相邻元素的比较和交换，使较大的元素逐渐“浮”到数组末尾。
 */
void bubble_sort(int arr[], int len) {
    // 外层循环：控制排序的轮数。n个元素最多需要 n-1 轮即可完成排序
    for (int j = 0; j < len - 1; j++) {
        // 【优化关键】：记录本轮是否发生过交换
        bool swap_flag = false;

        // 内层循环：进行相邻比较。
        // len - 1 - j 的原因：每经过一轮，末尾就有 j 个元素已排好序，无需再次比较
        for (int i = 0; i < len - 1 - j; i++) {
            // 如果前面的数比后面的大，则交换（升序逻辑）
            if (arr[i] > arr[i + 1]) {
                SWAP(arr, i, i + 1);
                swap_flag = true; // 发生了交换，说明数组可能还没排好序
            }
        }

        // 打印当前轮次后的结果，方便观察“冒泡”过程
        printf("第 %d 轮排序结果: ", j + 1);
        print_arr(arr, len);

        // 【提前结束】：如果一轮下来没有任何交换，说明数组已经有序，直接退出
        if (!swap_flag) {
            printf("检测到数组已完全有序，提前跳出循环。\n");
            break;
        }
    }

    /**
     * 性能分析：
     * 1. 时间复杂度：最坏 O(n^2)，最好（有序）O(n)
     * 2. 空间复杂度：O(1)，原地排序，不需要额外空间
     * 3. 稳定性：稳定的（相同元素不会改变相对顺序）
     */
}

int main(void) {
    // 待排序数组
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int n = ARR_LEN(arr);

    printf("原始数组内容：\n");
    print_arr(arr, n);
    printf("--------------------------------------------------\n");

    // 调用冒泡排序
    bubble_sort(arr, n);

    printf("--------------------------------------------------\n");
    printf("最终排序结果：\n");
    print_arr(arr, n);

    return 0;
}