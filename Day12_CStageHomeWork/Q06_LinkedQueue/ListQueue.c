#include "ListQueue.h"

// 创建链式队列
LinkedListQueue *create_queue() {
	LinkedListQueue *queue = malloc(sizeof(LinkedListQueue));
	if (queue == NULL) {
		printf("malloc failed in create_queue.");
		exit(EXIT_FAILURE);
	}
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

// 判空
// 如果队头指针为 NULL，说明队列里没有任何节点
bool is_empty(LinkedListQueue *q) {
	if (q == NULL) {
		return true;
	}
	return q->front == NULL;
}

// 入队列
// 创建一个新节点并放入数据。如果队列为空，新节点既是队头也是队尾；如果队列非空，将新节点接在当前队尾之后，然后更新队尾指针。
bool enqueue(LinkedListQueue *q, ElementType element) {
	if (q == NULL) {
		return false;
	}

	// 创建新结点并初始化
	QueueNode *new_node = malloc(sizeof(QueueNode));
	if (new_node == NULL) {
		printf("malloc failed in enqueue.");
		return false;
	}
	new_node->data = element;
	new_node->next = NULL;  // 新节点始终是最后一个节点，所以next为NULL

	if (is_empty(q)) {
		// 队列为空时，新结点既是队头结点也是队尾结点
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		// 队列非空时，将当前队尾的 next 指向新节点，然后移动 rear 指针
		q->rear->next = new_node;
		q->rear = new_node;
	}
	return true;
}

// 出队列并返回队头元素
// 记录当前队头节点，将其数据取出。将队头指针向后移动一位（指向下一个节点）。如果出队后队列变为空，需要将队尾指针也置为 NULL。最后释放原队头节点的内存。
ElementType dequeue(LinkedListQueue *q) {
	if (is_empty(q)) {
		printf("The queue is empty, can not dequeue.");
		exit(EXIT_FAILURE);
	}

	QueueNode *temp = q->front;
	ElementType data = temp->data;

	q->front = q->front->next;

	// 如果出队的是队列中最后一个元素，出队后队头变为空，此时必须将队尾也置空
	if (q->front == NULL) {
		q->rear = NULL;
	}

	free(temp);
	return data;
}


// 访问队头元素
// 直接读取队头节点的数据但不删除节点
ElementType peek_queue(LinkedListQueue *q) {
	if (is_empty(q)) {
		printf("The queue is empty, can not peek.");
		exit(EXIT_FAILURE);
	}
	return q->front->data;
}


// 销毁链式队列
// 循环执行出队操作，直到队列为空，这会释放所有内部节点的内存。最后释放队列控制结构本身的内存。
void destroy_queue(LinkedListQueue *q) {
	if (q == NULL) {
		return NULL;
	}

	// 释放所有内部节点
	while (!is_empty(q)) {
		QueueNode *temp = q->front;
		q->front = q->front->next;
		free(temp);
	}

	// 释放队列结构体本身
	free(q);
}