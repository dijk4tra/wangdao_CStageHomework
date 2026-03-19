#include "vector.h"

// 当数组满了时，将容量翻倍
void grow_capacity(Vector *v) {
	int new_capacity = v->capacity * 2;

	// 使用realloc重新分配内存，它会自动把旧数据拷贝到新空间
	ElementType *new_data = realloc(v->data, new_capacity);

	if (new_data == NULL) {
		printf("realloc failed in grow_capacity.\n");
		return;
	}

	v->data = new_data;  // 让 data 指针指向新空间
	v->capacity = new_capacity;  // 更新容量记录
}

// 初始化一个Vector动态数组
Vector *vector_create(void) {
	// 先在堆区申请 Vector 结构体本身的内存
	Vector *v = malloc(sizeof(Vector));
	if (v == NULL) {
		printf("malloc failed in vector_create.\n");
		return NULL;
	}

	// 再在堆区申请存放实际数据的数组内存
	v->data = (ElementType *)malloc(VECTOR_INIT_CAPACITY * sizeof(ElementType));
	if (v->data == NULL) {
		printf("malloc failed in vector_data.\n");
		free(v); // 如果数组申请失败，记得把前面申请的结构体的空间也释放掉
		return NULL;
	}

	// 初始化 size 和 capacity
	v->size = 0;
	v->capacity = VECTOR_INIT_CAPACITY;

	return v;
}

// 销毁一个Vector动态数组，释放内存
void vector_destroy(Vector *v) {
	if (v == NULL) {
		return;
	}
	// 注意释放顺序：先释放内部的数据数组，再释放结构体本身
	free(v->data);
	free(v);
}

// 向动态数组末尾添加一个元素
void vector_push_back(Vector *v, ElementType val) {
	// 如果当前元素个数已经等于容量，说明满了，需要扩容
	if (v->size == v->capacity) {
		grow_capacity(v);
	}

	// 在数组末尾放入新元素，然后size+1
	v->data[v->size] = val;
	v->size++;
}

// 将元素val添加到索引为idx的位置，idx后面的元素依次后移
void vector_insert(Vector *v, int idx, ElementType val) {
	// 索引不能小于0，也不能大于当前的元素个数
	if (idx < 0 || idx > v->size) {			// 做插入操作时索引合法范围是[0, size]
		printf("illegal insert location!\n");
		return;
	}

	// 如果满了，先扩容
	if (v->size == v->capacity) {
		grow_capacity(v);
	}

	// 从后往前遍历，把 idx 及其之后的元素统一往后挪一位
	for (int i = v->size; i > idx; i--) {
		v->data[i] = v->data[i - 1];
	}

	// 在目标位置腾出空位后，把新数据放进去
	v->data[idx] = val;
	v->size++;

}

// 在动态数组最前面添加元素，所有元素依次后移
void vector_push_front(Vector *v, ElementType val) {
	// 头部插入，本质上就是插入到索引为 0 的位置
	// 直接复用写好的 vector_insert 函数即可
	vector_insert(v, 0, val);
}

// 遍历打印整个Vector动态数组
void vector_print(Vector *v) {
	if (v->size == 0) {
		printf("[]\n");
		return;
	}

	printf("[");
	for (int i = 0; i < v->size; i++) {
		printf("%d", v->data[i]);
		// 如果不是最后一个元素，就打印逗号
		if (i != v->size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}