#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vector.h"

/*
动手自己实现动态数组Vector，基于以下结构体定义和函数声明：

typedef int ElementType;

typedef struct {
    ElementType *data;   // 指向堆空间的数组
    int size;	// 元素的个数
    int capacity; // 数组的容量
} Vector;

// 请实现下面方法

// 初始化一个Vector动态数组
Vector *vector_create(void);

// 销毁一个Vector动态数组，释放内存。
void vector_destroy(Vector *v);

// 向动态数组末尾添加一个元素
void vector_push_back(Vector *v, ElementType val);

// 在动态数组最前面添加元素，所有元素依次后移
void vector_push_front(Vector *v, ElementType val);

// 将元素val添加到索引为idx的位置，idx后面的元素依次后移
void vector_insert(Vector *v, int idx, ElementType val);

// 遍历打印整个Vector动态数组
void vector_print(Vector *v);

注意：
你应该将上述代码放在头文件中，并且自己添加头文件保护语法。
提交作业时，你应该提交头文件，实现Vector的源文件，测试源文件三个文件的代码
*/



int main(void) {
    // 创建 Vector
    Vector *vec = vector_create();

    // 测试尾部追加
    printf("--- testing vector_push_back ---\n");
    vector_push_back(vec, 10);
    vector_push_back(vec, 20);
    vector_push_back(vec, 30);
    vector_print(vec); // 预期输出: [10, 20, 30]

    // 测试头部插入
    printf("--- testing vector_push_front ---\n");
    vector_push_front(vec, 5);
    vector_push_front(vec, 1);
    vector_print(vec); // 预期输出: [1, 5, 10, 20, 30]

    // 测试中间插入
    printf("--- testing vector_insert ---\n");
    // 在索引 2 的位置插入 99 (即插在 5 和 10 之间)
    vector_insert(vec, 2, 99);
    vector_print(vec); // 预期输出: [1, 5, 99, 10, 20, 30]

    // 释放内存
    vector_destroy(vec);
    printf("free succeed.\n");

    return 0;
}