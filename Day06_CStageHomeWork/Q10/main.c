#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define ARR_LEN(arr) ((sizeof(arr)/sizeof(arr[0])))

// 1.编写函数交换数组中两个下标的元素。函数声明如下：void swap(int *arr, int i, int j) 。要求不使用[]运算符，将[]还原成解引用运算符和指针加法来完成
void swap(int *arr, int i, int j) {
    printf("交换前的两个元素：%d---%d\n", *(arr + i), *(arr + j));
    int temp;
    temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
    printf("交换后的两个元素：%d---%d\n", *(arr + i), *(arr + j));
}

// 2.数组元素的逆序。要求使用[]运算符以及纯粹指针操作两种方式来完成
void reverse(int *arr, int len) {
    printf("逆序前的数组元素：\n");
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    int temp;
    for (int i = 0; i < len / 2; i++) {
        temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;

    }
    printf("\n逆序后的数组元素：\n");
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
}

void reverse_by_pointer(int *arr, int len) {
    printf("逆序前的数组元素：\n");
    for (int i = 0; i < len; i++) {
        printf("%d  ", * (arr + i));
    }
    int temp;
    for (int i = 0; i < len/2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + len - 1 - i);
        *(arr + len - 1 - i) = temp;
        
    }
    printf("\n逆序后的数组元素：\n");
    for (int i = 0; i < len; i++) {
        printf("%d  ", *(arr + i));
    }
}

// 3.数组元素求和。要求使用"*p++"语法结构来完成数组元素的累加
void array_sum(int *arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += *arr++;
    }
    printf("数组元素求和结果：%d\n", sum);
}

// 4.给定一个int数组以及一个目标值target，请编写函数找到这个目标值的下标，要求该函数没有返回值
void find_array_index(int *arr, int len, int target) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) {
            printf("目标值%d的下标为：%d\n",target , i);
        }
    }
}

// 5.编写一个函数，检查一个整数数组是否是回文，即正序与倒序相同。例如[1,2,3,2,1]就是回文的。要求使用指针的算术运算，不要使用取下标[]运算符
bool is_palindrome(int *arr, int len) {
    int *start = arr;           // 头指针，指向数组的第一个元素
    int *end = arr + len - 1;   // 尾指针，指向数组的最后一个元素

    while (start < end) {
        if (*start != *end) {
            printf("该整数数组不是回文。\n");
            return false;
        }
        start++;
        end--;
    }
    printf("该整数数组是回文。\n");
    return true;
}


// 6.给定一个非空整数数组src，再给定一个足够长的dest数组。编写一个函数 copy_array，使用 *p++ 复制src数组到dest数组
void copy_array(int *src, int *dest, int src_len) {
    for (int i = 0; i < src_len; i++) {
        *dest++ = *src++;
    }
}

// 7.给定一个整数数组，将该数组中所有奇数移到数组的前面，偶数移到数组的后面（扩展题）
void parity_partition(int *arr, int len){
    int *left = arr;
    int *right = arr + len - 1;

    printf("处理前的数组元素：\n");
    for (int i = 0; i < len; i++) {
        printf("%d  ", *(arr + i));
    }

    while (left < right) {
        // 从左向右找第一个偶数
        // (*left & 1) == 1 表示是奇数，则指针右移
        while (left < right && ((*left) & 1) != 0) {
            left++;
        }
        // 从右向左找第一个奇数
        // (*right & 1) == 0 表示是偶数，则指针左移
        while (left < right && ((*right) & 1) == 0) {
            right--;
        }
        // 交换左边的偶数和右边的奇数
        if (left < right) {
            int temp = *left;
            *left = *right;
            *right = temp;
        }
    }

    printf("\n处理后的数组元素：\n");
    for (int i = 0; i < len; i++) {
        printf("%d  ", *(arr + i));
    }
}




int main(void) {
    
    int arr1[5] = { 1,2,3,4,5 };
    int arr2[5] = { 1,2,3,2,1 };

    int src[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    int dest[100] = { 0 };

    //swap(arr1, 0, 4);
    
    //reverse(arr1, ARR_LEN(arr1));
    //reverse_by_pointer(arr1, ARR_LEN(arr1));
    
    //array_sum(arr1, ARR_LEN(arr1));
    
    //find_array_index(arr1, ARR_LEN(arr1), 3);

    //is_palindrome(arr2, ARR_LEN(arr2));

    parity_partition(arr1, ARR_LEN(arr1));



    return 0;
}