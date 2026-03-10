#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 宏定义：获取数组长度
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换两个元素的值
// 注意：使用 do-while(0) 是 C 语言宏定义的标准写法，防止在 if 等语句中出错
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

/**
 * 堆调整（针对大顶堆）：确保以 root_idx 为根的子树满足大顶堆性质
 * 性质：父节点的值总是大于或等于其孩子节点的值
 * @param arr 存储堆的数组
 * @param root_idx 当前需要调整的根节点下标
 * @param tree_len 当前堆的有效长度（超过此长度的元素已排好序）
 */
void heapify(int arr[], int root_idx, int tree_len) {
    // 采用循环方式（下滤操作），比递归更省内存
    while (1) {
        int max_idx = root_idx;      // 记录父节点、左、右孩子中最大值的下标
        int left_idx = root_idx * 2 + 1;  // 左孩子公式：2i + 1
        int right_idx = root_idx * 2 + 2; // 右孩子公式：2i + 2

        // 1. 如果左孩子存在，且左孩子比当前最大值大，更新 max_idx
        if (left_idx < tree_len && arr[left_idx] > arr[max_idx]) {
            max_idx = left_idx;
        }

        // 2. 如果右孩子存在，且右孩子比当前最大值大，更新 max_idx
        if (right_idx < tree_len && arr[right_idx] > arr[max_idx]) {
            max_idx = right_idx;
        }

        // 3. 检查最大值是否依然是最初的父节点
        if (max_idx != root_idx) {
            // 如果孩子比父节点大，交换它们，让大值“上浮”
            SWAP(arr, max_idx, root_idx);

            // 交换后，被交换的孩子节点及其子树可能不再满足堆性质
            // 将 root_idx 指向刚才交换过的孩子节点，继续向下调整（下滤）
            root_idx = max_idx;
        }
        else {
            // 如果父节点已经是最大，说明当前子树已调整完毕，跳出循环
            break;
        }
    }
}

/**
 * 堆排序主函数
 * @param arr 待排序数组
 * @param len 数组长度
 */
void heap_sort(int arr[], int len) {
    /* * 第一步：构建初始大顶堆
     * 优化点：从最后一个非叶子节点开始向前调整。
     * 最后一个非叶子节点的下标是 (len / 2) - 1。
     */
    for (int i = (len / 2) - 1; i >= 0; i--) {
        heapify(arr, i, len);
    }

    /* * 第二步：循环交换与重建堆
     * 原理：大顶堆的堆顶（arr[0]）永远是当前堆中最大的元素。
     * 将其换到数组末尾，然后减小堆的有效长度，再次调整堆顶。
     */
    int current_heap_size = len;
    for (int i = 0; i < len - 1; i++) {
        // 1. 将当前最大的堆顶元素交换到数组末尾（已排序区域）
        SWAP(arr, 0, current_heap_size - 1);

        // 2. 堆的有效大小减 1
        current_heap_size--;

        // 3. 交换后，堆顶元素破坏了大顶堆性质，从堆顶(0)开始进行一次调整
        heapify(arr, 0, current_heap_size);
    }
}

int main(void) {
    // 初始化测试数据
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int n = ARR_LEN(arr);

    printf("排序前:\n");
    print_arr(arr, n);

    // 执行堆排序
    heap_sort(arr, n);

    printf("排序后:\n");
    print_arr(arr, n);

    return 0;
}