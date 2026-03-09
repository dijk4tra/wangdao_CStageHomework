#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>

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
void vector_add_before_head(Vector *vec, DataType data);
void vector_add_by_idx(Vector *vec, DataType data);

// 删除
// 按下标删除
bool vector_delete_by_idx(Vector *vec, int idx);
// 按值删除：删除第一次出现的值、删除最后一次出现的值、删除所有出现的值
bool vector_delete_by_value_first_accurance(Vector *vec, DataType data);
bool vector_delete_by_value_last_accurance(Vector *vec, DataType data);
bool vector_delete_by_value_all_accurance(Vector *vec, DataType data);
// 改：将某个索引的值，改成另一个值
void vector_update_idx(Vector *vec, int idx , DataType data);

// 查：查值是否存在、查下标对应的值、查值的下标
bool vector_value_exists(Vector *vec, DataType data);
DataType vector_get_idx_value(Vector *vec, int idx);
int vector_get_value_of_idx(Vector *vec, DataType data);

#endif // !VECTOR_H

