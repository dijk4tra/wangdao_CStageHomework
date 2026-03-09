#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

// 定义初始容量的宏
#define VECTOR_INIT_CAPACITY 10

// 使用 typedef 让代码更灵活，以后如果想存浮点数，只需把 int 改成 float 即可
typedef int ElementType;

// 定义 Vector 结构体
typedef struct {
	ElementType *data;	// 指向堆空间中实际存放数据的数组
	int size;			// 当前已经存放的元素个数
	int capacity;		// 当前数组的总容量（最多能装多少个）
}Vector;

// ---------------- 函数声明 ----------------
// 创建、销毁、遍历
// 初始化一个Vector动态数组
Vector *vector_create(void);

// 销毁一个Vector动态数组，释放内存
void vector_destroy(Vector *v);

// 遍历打印整个Vector动态数组
void vector_print(Vector *v);

// 增删改查
// 向动态数组末尾添加一个元素
void vector_push_back(Vector *v, ElementType val);

// 在动态数组最前面添加元素，所有元素依次后移
void vector_push_front(Vector *v, ElementType val);

// 将元素val添加到索引为idx的位置，idx后面的元素依次后移
void vector_insert(Vector *v, int idx, ElementType val);

#endif // !VECTOR_H
