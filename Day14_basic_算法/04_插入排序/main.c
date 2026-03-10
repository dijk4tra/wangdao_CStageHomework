#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 宏定义：计算数组长度。原理是：数组总字节数 / 单个元素字节数
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换两个元素。注意使用了大括号封装以保证宏的安全性
#define SWAP(arr, i, j) { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
}

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

/**
 * 插入排序算法
 * 核心思想：将数组分为“已排序”和“未排序”两部分。
 * 初始时，下标 0 的元素自成一个有序区。从下标 1 开始，将后续元素逐个插入到有序区的合适位置。
 * 形象理解：打扑克牌时，左手抓着已排好序的牌，右手摸起一张新牌，在左手中从右向左比较并找位置插入。
 */
void insert_sort(int arr[], int len) {
    // 外层循环：决定当前哪张牌是“待插入”的。从第 2 张牌（下标 1）开始摸
    for (int i = 1; i < len; i++) {

        // 1. 备份当前要插入的值（因为后面挪位置时可能会覆盖这个下标的值）
        int need_insert_value = arr[i];

        // 2. 找到有序区的最后一张牌的下标
        int need_check_index = i - 1;

        // 3. 内层循环：在有序区中“从后往前”扫描
        // 条件：只要还没到头(>=0)，且有序区里的牌比待插入的牌大，就得往后挪
        while (need_check_index >= 0 && need_insert_value < arr[need_check_index]) {
            // 将较大的元素向后移动一位，腾出空间
            arr[need_check_index + 1] = arr[need_check_index];
            // 继续往前看
            need_check_index--;
        }

        // 4. 插入：当循环停止（遇到比它小的牌或者到头了），把备份的值放入空位
        // 这里的 +1 是因为 while 循环最后执行了一次 need_check_index--
        arr[need_check_index + 1] = need_insert_value;

        // 打印每一步过程，方便学习观察
        printf("第 %d 轮插入结果: ", i);
        print_arr(arr, len);
    }

    /* * 算法分析：
     * 时间复杂度：
     * - 最优情况（已排序）：O(n)，只需遍历一遍
     * - 最坏情况（完全逆序）：O(n^2)
     * 空间复杂度：O(1)，原地排序，不需要额外空间
     * 稳定性：稳定排序（相同元素的相对位置不会改变）
     */
}

/**
 * 测试最极端情况：完全逆序
 */
void test2() {
    printf("\n--- 测试极端情况：完全逆序 ---\n");
    int worst_case[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int len = ARR_LEN(worst_case);

    printf("排序前: ");
    print_arr(worst_case, len);

    insert_sort(worst_case, len);

    printf("最终排序后: ");
    print_arr(worst_case, len);
}


int main(void) {
    // 原始测试
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int len = ARR_LEN(arr);

    printf("原始数组: \n");
    print_arr(arr, len);
    printf("--------------------------------\n");

    insert_sort(arr, len);

    printf("--------------------------------\n");
    printf("排序完成!\n");

    // 调用极端情况测试
    test2();

    return 0;
}