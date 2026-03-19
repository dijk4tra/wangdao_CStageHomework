#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 10
typedef int DataType;

typedef struct vector {
	int *table;   // 指针，用于存放地址，存放堆空间上的地址
	int capacity; // 容量
	int size;	  // 当前装了多少数据
}Vector;

// 函数声明
// 创建它、销毁它、遍历它的函数

Vector *vector_create();
void vector_destory(Vector *vec);
void vector_print(Vector *vec);

// 增删改查
// 从Vector的尾部增加数据
void vector_add_after_tail(Vector *vec, DataType data);

#endif // !VECTOR_H

