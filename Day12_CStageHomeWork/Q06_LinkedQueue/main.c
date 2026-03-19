#define _CRT_SECURE_NO_WARNINGS
#include "ListQueue.h"

int main() {

    // 创建队列
    LinkedListQueue *queue = create_queue();
    printf("队列创建成功。");

    // 入队
    printf("\n准备入队: 10, 20, 30\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    if (!is_empty(queue)) {
        printf("入队完成。");
    }

    // 获取队头元素
    printf("\n当前队头元素是: %d\n", peek_queue(queue));

    // 出队
    printf("\n准备出队...\n");
    printf("出队元素: %d\n", dequeue(queue));
    printf("当前队头元素是: %d\n", peek_queue(queue));
    printf("出队元素: %d\n", dequeue(queue));
    printf("当前队头元素是: %d\n", peek_queue(queue));
    printf("出队元素: %d\n", dequeue(queue));
    printf("当前队列是否为空: %s\n", is_empty(queue) ? "是" : "否");

    // 销毁队列
    destroy_queue(queue);
    printf("\n队列已销毁。\n");

    return 0;
}