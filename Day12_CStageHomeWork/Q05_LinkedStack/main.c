#define _CRT_SECURE_NO_WARNINGS
#include "LinkedStack.h"

int main(void) {
    
    // 创建链式栈
    LinkedStack *stack = stack_create();
    printf("LinkedSrack create successfully.\n");

    // 入栈
    printf("\n将元素 10, 20, 30 依次入栈...\n");
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);
    printf("Stack push successfully.\n");

    // 访问栈顶
    printf("\n当前栈顶元素是: %d\n", stack_peek(stack)); // 30

    // 出栈
    printf("\n开始执行出栈操作：\n");
    printf("出栈元素: %d\n", stack_pop(stack)); // 30
    printf("出栈后，新的栈顶元素是: %d\n", stack_peek(stack));
    printf("出栈元素: %d\n", stack_pop(stack)); // 20
    printf("出栈后，新的栈顶元素是: %d\n", stack_peek(stack));
    printf("出栈元素: %d\n", stack_pop(stack)); // 10

    // 验证是否完全清空
    if (is_empty(stack)) {
        printf("\n所有元素已出栈。当前栈为空。\n");
    }

    // 销毁栈，回收内存
    stack_destroy(stack);
    printf("\n栈已安全销毁，程序结束。\n");

    return 0;
}