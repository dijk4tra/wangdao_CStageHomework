#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
先在堆上申请创建一个长度为10的int数组，编写一个函数用于以"[xx, xx, ..., xx]"的格式打印这个int数组。
紧接着执行以下操作：
    1.在申请int数组成功后，直接调用函数打印这个int数组，思考一下：应该用哪个函数来申请创建这个数组？
    2.截断这个int数组，将其变为长度为5的int数组，然后再打印这个数组。
    3.将长度为5的int数组，再次扩容回10个元素，将最后五个元素初始化为888，最后再次打印这个数组。
    4.最后不要忘记free释放内存块。
重点需要注意realloc函数的调用格式！
*/

// 以"[xx, xx, ..., xx]"的格式打印数组
void print_array(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d",arr[i]);
        // 如果不是最后一个元素，就打印逗号
        if (i < len - 1) {
            printf("，");
        }
    }
    printf("]\n");
}


int main(void) {
    // 使用malloc函数在堆上申请空间，创建一个长度为10的int数组
    // 如果malloc成功会返回数组首元素地址
    int *arr_p = malloc(10 * sizeof(int));
    // 检查malloc是否成功，即检查arr_p是否是一个空指针
    if (arr_p == NULL) {
        printf("memory allocation failed!\n");
        return -1;
    }
    // malloc并不会初始化内存块，所以需要手动为动态分配的数组元素赋值
    for (int i = 0; i < 10; i++) {
        arr_p[i] = i;
    }

    print_array(arr_p, 10);

    // 截断数组为5个元素（截断数组通常不用担心realloc会返回空指针）
    arr_p = realloc(arr_p, 5 * sizeof(int));

    printf("截断为5个元素后的数组：\n");
    print_array(arr_p, 5);

    // 将数组再次扩容回10个元素
    // 注意：扩容数组时，realloc可能会返回空指针或指向其它地址的指针
    int *temp = realloc(arr_p, 10 * sizeof(int));
    if (temp != NULL) {
        arr_p = temp;
    }
    else {
        printf("realloc扩容失败！\n");
        free(arr_p); // 失败时手动释放原内存防止泄漏
        return -1;
    }

    // 将最后五个元素初始化为888
    for (int i = 5; i < 10; i++) {
        arr_p[i] = 888;
    }

    printf("再次扩容回10个元素的数组：\n");
    print_array(arr_p, 10);

    free(arr_p);
    arr_p = NULL; // 为了避免悬空指针，需要在free掉指针指向的内存块后，及时将指针置为空指针

    return 0;
}