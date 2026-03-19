#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector *vector_create() {
	// 创建什么东西出来？
	// 申请 Vector ；申请数组空间，让 vec->table 指向它
	Vector *vec = malloc(sizeof(Vector));

	if (vec == NULL){
		printf("malloc failed in vector_create\n");
		return NULL;
	}
	// vec不为NULL

	// vec目前不能装数据
	// vec->table指向的空间才能装数据
	vec->table = malloc(VECTOR_INIT_CAPACITY * sizeof(DataType));

	if (vec->table == NULL) {
		// 说明内存申请失败
		printf("malloc failed in vector create in vectortable.\n");
		// 不要忘记free结构体Vector，否则会导致内存泄漏
		free(vec);
		return;
	}

	vec->size = 0;
	vec->capacity = VECTOR_INIT_CAPACITY;

	return vec;
}


void vector_destory(Vector *vec) {
	free(vec->table);
	free(vec);
}


void vector_print(Vector *vec) {
	// []   
	// [10 ,20, 30]
	if (vec->size == 0) {
		printf("[]\n");
		return;
	}
	
	printf("[");
	for (int i = 0; i < vec->size; i++) {
		printf(" %d", vec->table[i]);

		if (i != vec->size - 1) {
			printf(",");
		}
	}
	printf("]");
}


void vector_add_after_tail(Vector *vec, DataType data) {

	// 要来做扩容的逻辑，什么时候扩容？怎么扩容？
	if (vec->size == vec->capacity) {
		// 此时需要扩容
		// new_size  = old_size * 2
		int old_size = vec->capacity;
		int new_size = old_size * 2;

		// realloc(vec, new_size);		// 错误代码，扩容扩的是实际装数据的vec->table
		// realloc(vec->table, new_size);  // 错误代码，单位应该是字节，写new_size不对
		DataType *new_table = realloc(vec->table, new_size * sizeof(DataType));

		if (new_table == NULL) {
			// 说明重分配失败。 
			printf("realloc failed in vector_add_after_tail.\n");
			return;
		}
		vec->table = new_table;
		vec->capacity = new_size;

	}

	vec->table[vec->size] = data;
	vec->size++;

}