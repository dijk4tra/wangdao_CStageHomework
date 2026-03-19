#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**
 * 功能：演示如何将两个已经有序的子数组合并成一个新的有序数组
 */
void test1() {
	// 1. 定义两个初始有序数组及其长度
	int arr1[] = { 1, 3, 5, 6, 8, 9, 12 };
	int arr2[] = { 2, 3, 4, 7, 9, 11, 13 };
	int len1 = 7;
	int len2 = 7;

	// 2. 动态分配内存以存储合并后的结果
	// 计算新数组所需的总长度：len1 + len2
	int *arr = (int *)malloc(sizeof(int) * (len1 + len2));

	// 健壮性检查：判断内存是否分配成功
	if (arr == NULL) {
		printf("内存分配失败！\n");
		return;
	}

	// 3. 定义索引（指针）
	int index1 = 0;      // 遍历 arr1 的索引
	int index2 = 0;      // 遍历 arr2 的索引
	int total_index = 0; // 填充新数组 arr 的索引

	// 4. 核心合并逻辑：比较两个数组的当前元素，将较小者放入新数组
	// 只要两个数组都没遍历完，就继续比较
	while (index1 < len1 && index2 < len2) {
		if (arr1[index1] < arr2[index2]) {
			// 如果 arr1 的元素更小，将其放入 arr，并移动 index1
			arr[total_index++] = arr1[index1++];
		}
		else {
			// 如果 arr2 的元素更小（或相等），将其放入 arr，并移动 index2
			arr[total_index++] = arr2[index2++];
		}
	}

	// 5. 处理剩余元素
	// 如果 arr1 还有剩余（此时 arr2 已遍历完），直接追加到末尾
	while (index1 < len1) {
		arr[total_index++] = arr1[index1++];
	}

	// 如果 arr2 还有剩余（此时 arr1 已遍历完），直接追加到末尾
	while (index2 < len2) {
		arr[total_index++] = arr2[index2++];
	}

	// 6. 打印合并后的有序数组
	printf("合并后的数组为：\n");
	for (int i = 0; i < total_index; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	// 7. 【关键】释放动态分配的内存，防止内存泄漏
	free(arr);
	arr = NULL; // 养成好习惯：释放后将指针置为空
}

int main(void) {
	// 调用测试函数
	test1();

	return 0;
}