#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 宏定义：计算数组长度
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换两个元素的值
// 使用 do-while(0) 是一种 C 语言惯用法，可以确保宏在 if-else 等语句中安全展开
#define SWAP(arr, i, j) { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
}

/**
 * 打印数组元素
 * @param arr 目标数组
 * @param len 数组长度
 */
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/**
 * 希尔排序（缩小增量排序）
 * 原理：将数组按一定增量 gap 分组，对每组使用直接插入排序；
 * 随着增量逐渐减小到 1，整个数组恰好被分成一组，完成最后一次排序。
 */
void shell_sort(int arr[], int len) {
    // 1. 初始化增量 gap，通常初始为长度的一半
    // gap 既是分组的依据，也是逻辑上每组元素之间的距离
    int gap = len / 2;

    // 2. 只要增量 gap >= 1，就继续进行分组排序
    while (gap > 0) {

        // 3. 遍历数组，执行各组内部的插入排序
        // i 从 gap 开始，意味着我们从每一组的第二个元素开始处理（因为第一个元素默认有序）
        for (int i = gap; i < len; i++) {

            int temp = arr[i];           // 暂存当前需要插入的元素（待排元素）
            int pre_index = i - gap;    // 寻找在当前组内，temp 前面的一个元素索引

            // 4. 组内插入排序的核心：
            // 只要前面的元素比待排元素大，就将前面的元素向后移动 gap 个位置
            while (pre_index >= 0 && temp < arr[pre_index]) {
                arr[pre_index + gap] = arr[pre_index]; // 元素后移
                pre_index -= gap;                      // 继续向前跨 gap 步检查
            }

            // 5. 找到合适位置后，将 temp 插入
            // 循环结束时，pre_index 停在比 temp 小的元素索引处，所以要 +gap
            arr[pre_index + gap] = temp;
        }

        // 6. 缩小增量，继续下一轮循环
        // 这里的缩小策略是折半，直到 gap 变为 1
        gap /= 2;
    }
}

int main(void) {
    // 初始化测试数组
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int n = ARR_LEN(arr);

    printf("排序前的数组：\n");
    print_arr(arr, n);
    printf("------------------------------------------\n");

    // 执行希尔排序
    shell_sort(arr, n);

    printf("排序后的数组：\n");
    print_arr(arr, n);

    return 0;
}