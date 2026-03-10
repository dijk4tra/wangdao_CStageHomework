#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 宏定义：自动计算数组长度
// 原理：数组总字节数 / 单个元素的字节数
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换两个元素的值
// 使用了 tmp 变量作为中转，注意宏中的花括号是为了防止多行逻辑在 if/for 后失效
#define SWAP(arr, i, j) { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
}

/**
 * 打印数组内容
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
 * 选择排序 (Selection Sort)
 * 核心思想：每一轮在“未排序区域”中找到最小（或最大）的元素，放到“已排序区域”的末尾。
 */
void select_sort(int arr[], int len) {
    // 外层循环：控制排序的轮数
    // i 代表当前“待填充”的位置，i 之前的元素都是已经排好序的
    for (int i = 0; i < len; i++) {
        // 1. 假设当前位置 i 就是最小值的索引
        int min_index = i;

        // 2. 内层循环：从 i+1 开始遍历剩余的所有元素，寻找真正的最小值
        for (int j = i + 1; j < len; j++) {
            // 如果发现更小的值，更新记录的索引
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // 3. 交换：将找到的最小值与当前 i 位置的元素交换
        // 即使 min_index 没有变化，执行交换也是安全的，但在工业级代码中常加 (if min_index != i) 判断
        SWAP(arr, i, min_index);

        // 调试：打印每一轮交换后的数组状态，方便观察排序过程
        printf("第 %d 轮选择后: ", i + 1);
        print_arr(arr, len);
    }

    /* * --- 算法复杂度分析 ---
     * 1. 比较次数：(n-1) + (n-2) + ... + 1 = n*(n-1)/2
     * 2. 时间复杂度：O(n^2) —— 无论数组是否有序，比较次数都是固定的。
     * 3. 空间复杂度：O(1) —— 只需要一个 tmp 临时变量，不随 n 增大。
     * 4. 稳定性：不稳定 —— 交换过程可能会破坏相同数值元素的相对顺序。
     * 例如: [5, 8, 5, 2] -> 第一轮 2 会和第一个 5 交换，两个 5 的相对位置就变了。
     */
}

int main(void) {
    /*
     * 选择排序逻辑直观理解：
     * 想象一排人站队，你从左往右走。
     * 第一次：看遍所有人，选出最矮的，和第1个人换位置。
     * 第二次：从第2个人开始往后看，选出剩下人里最矮的，和第2个人换位置。
     * 以此类推。
     */

     // 测试数据：包含无序、极大值和重复值的数组
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int length = ARR_LEN(arr);

    printf("原始数组: \n");
    print_arr(arr, length);
    printf("--------------------------------\n");

    // 开始排序
    select_sort(arr, length);

    printf("--------------------------------\n");
    printf("最终排序结果: \n");
    print_arr(arr, length);

    return 0;
}