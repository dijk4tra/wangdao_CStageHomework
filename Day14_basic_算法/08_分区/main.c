#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 包含 rand() 和 srand()
#include <time.h>   // 包含 time()

// 宏定义：计算数组长度
// 原理：数组总字节数 / 单个元素字节数
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换数组中两个下标对应的元素
// 使用 do...while(0) 是一种 C 语言编程技巧，确保宏在 if/else 等语句中安全展开
#define SWAP(arr, i, j) do { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
} while(0)

/**
 * 打印数组元素
 * @param arr 数组首地址
 * @param len 数组长度
 */
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // 初始化随机数种子，防止每次运行随机结果都一样
    srand((unsigned int)time(NULL));

    // 待处理数组
    int arr[] = { 16, 22, 28, 1, 7, 5, 3, 2, 4, 50 };
    int n = ARR_LEN(arr);

    printf("原始数组: ");
    print_arr(arr, n);

    /* * 【分区的核心逻辑：挖坑填补法】
     * 目标：选择一个“枢纽值”(Pivot)，调整数组顺序，
     * 使得 Pivot 左边的元素都 <= Pivot，右边的元素都 > Pivot。
     */

     // 1. 选择枢纽值
     // 技巧：随机选择一个位置并与左边界交换，可以有效防止在面对“近乎有序”的数组时退化成 O(n^2)
    int left = 0;
    int right = n - 1;
    int pivot_idx = rand() % n;
    SWAP(arr, left, pivot_idx); // 将随机选中的枢纽值换到最左边

    int pivot_value = arr[left]; // 此时 arr[left] 就是坑位，值已存入 pivot_value
    int cur_l = left;            // 左指针
    int cur_r = right;           // 右指针

    // 2. 开始左右夹击
    while (cur_l < cur_r) {

        // --- 步骤 A: 从右向左扫描 ---
        // 寻找第一个【比枢纽值小】的数，准备填到左边的坑里
        while (cur_l < cur_r && arr[cur_r] >= pivot_value) {
            cur_r--;
        }
        if (cur_l < cur_r) {
            arr[cur_l] = arr[cur_r]; // 把小的数填到左坑，此时 arr[cur_r] 变成了新坑
            cur_l++;                 // 填完后，左指针右移一位
        }

        // --- 步骤 B: 从左向右扫描 ---
        // 寻找第一个【比枢纽值大】的数，准备填到右边的坑里
        while (cur_l < cur_r && arr[cur_l] <= pivot_value) {
            cur_l++;
        }
        if (cur_l < cur_r) {
            arr[cur_r] = arr[cur_l]; // 把大的数填到右坑，此时 arr[cur_l] 变成了新坑
            cur_r--;                 // 填完后，右指针左移一位
        }
    }

    // 3. 归位枢纽值
    // 当 cur_l == cur_r 时，所有元素都已扫描完毕，最后这个位置就是 Pivot 的最终归宿
    arr[cur_l] = pivot_value;

    printf("分区后(枢纽值 %d): ", pivot_value);
    print_arr(arr, n);

    return 0;
}