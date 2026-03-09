#include "LinkedStack.h"

// 创建链式栈
LinkedStack *stack_create() {
	// 为管理链式栈结构体分配内存
	LinkedStack *stack = malloc(sizeof(LinkedStack));
	if (stack == NULL) {
		printf("malloc failed in stack_create.");
		exit(EXIT_FAILURE); // 内存不足时直接退出程序
	}
	// 初始化栈顶指针为空，表示此时栈中没有元素
	stack->top = NULL;
	return stack;
}


// 判空
bool is_empty(LinkedStack *stack) {
	if (stack == NULL) {
		return true;
	}
	return stack->top == NULL;
}


// 入栈（Push）- 在链表头部插入新节点
void stack_push(LinkedStack *stack, ElementType data) {
	if (stack == NULL) {
		return;
	}

	// 创建新结点并分配内存
	StackFrame *new_node = malloc(sizeof(StackFrame));
	if (new_node == NULL) {
		printf("malloc failed in stack_push.");
		exit(EXIT_FAILURE);
	}

	// 将数据存入新节点
	new_node->data = data;

	// 将新结点的next指向当前的栈顶结点
	new_node->next = stack->top;

	// 更新栈顶指针，使其指向刚刚插入的新节点
	stack->top = new_node;
}


// 出栈并返回栈顶元素（Pop）- 删除并返回链表头部节点
ElementType stack_pop(LinkedStack *stack) {
	// 如果栈为空，则无法出栈
	if (is_empty(stack)) {
		printf("The stack is empty, can not pop.");
		exit(EXIT_FAILURE);
	}

	// 临时保存当前的栈顶节点和它的数据
	StackFrame *temp = stack->top;
	ElementType pop_data = temp->data;

	// 移动栈顶指针，使其指向下一个节点
	stack->top = temp->next;

	// 释放原栈顶节点的内存，防止内存泄漏
	free(temp);

	// 返回出栈的数据
	return pop_data;
}


// 访问栈顶元素（Peek）- 仅查看，不删除
ElementType stack_peek(LinkedStack *stack) {
	if (is_empty(stack)) {
		printf("The stack is empty, can not peek.");
		exit(EXIT_FAILURE);
	}
	return stack->top->data;
}


// 销毁链式栈 - 释放所有结点和栈管理结构的内存
void stack_destroy(LinkedStack *stack) {
	if (stack == NULL) {
		return;
	}

	// 循环弹出元素，直到栈为空
	while (!is_empty(stack)) {
		stack_pop(stack);
		// 在pop过程中，各结点的内存都已经被释放
	}

	// 最后释放栈管理结构体本身的内存
	free(stack);
}

