#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr))/(sizeof(arr[0])))

/*
练习题：
1.给一个字符数组，判断元音字母的个数 aeiou
2.给一个字符数组，将元音字母找到，拼接到这个数组的后面，若数组到了 0 这个字符，就结束  {abcde0ae}
3.给一个字符数组，将其内容复制一份，数组长度不会超过100
4.比较两个字符数组内容是否完全相同
5.统计一个字符数组中，字母的个数
6.删除一个字符数组中的空格 abcde ccdde aab
7.将一个字符数组中，大写字母转换为小写，小写转换为大写，数字不动，没有其他的字符
*/

/*
* 
* 题1.错误写法
* 这段代码在逻辑上有一个非常经典且隐蔽的错误，主要出在 ARR_LEN 宏在函数内部失效
* 虽然在 main 函数中定义的数组确实有 20 个元素，但当数组作为参数传递给函数时，它会“退化”为指针
* 在 main 函数里，sizeof(arr1) 返回的是整个数组的大小（20 字节）
* 但在 vowel_number(char arr[]) 函数中，参数 char arr[] 实际上等同于 char *arr
* 此时 sizeof(arr) 返回的是指针的大小（在 64 位系统上通常是 8 字节，32 位系统是 4 字节）
* 这里的函数中的ARR_LEN(arr)的结果永远是4，因为sizeof(arr)返回的是指针的大小4
* 这会导致该函数只会统计数组中前4个元素中的元音字母的数量

void vowel_number(char arr[]) {
    int vowel_count = 0;
    for (int i = 0; i < ARR_LEN(arr); i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            vowel_count++;
        }
    }
    printf("元音字母的个数为：%d\n", vowel_count);
}

int main(void) {
    char arr1[] = {'a','r','7','*','y','t','i','o','b','4','u','x','8','a','3','0','%','m','e','c'};
    vowel_number(arr1);

    return 0;
}

*/


// 1.给一个字符数组，判断元音字母的个数 aeiou
void vowel_number(char arr[], int len) {
    int vowel_count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            vowel_count++;
        }
    }
    printf("元音字母的个数为：%d\n", vowel_count);
}



// 2.给一个字符数组，将元音字母找到，拼接到这个数组的后面，若数组到了 0 这个字符，就结束{ abcde0ae }
void find_vowel_and_insert(char arr[], int current_len, int total_capacity){
    printf("old arr: ");
    for (int k = 0; k < current_len; k++) {
        printf("%c", arr[k]);
    }
    int i = 0;
    int write_index = current_len; // 从当前数组末尾开始写入
    while (arr[i] != '0' && write_index < total_capacity) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            arr[write_index] = arr[i];
            write_index++;
        }
        i++;
    }
    printf("\nnew arr: ");
    for (int k = 0; k < write_index; k++) {
        printf("%c", arr[k]);
    }
}

// 3.给一个字符数组，将其内容复制一份，数组长度不会超过100
void copy_char_array(char arr[], int len) {
    char copy_arr[100] = { 0 };
    for (int i = 0; i < len; i++) {
        copy_arr[i] = arr[i];
    }
    printf("复制后的内容为：");
    for (int i = 0; i < len; i++) {
        printf("%c ", copy_arr[i]);
    }
}

// 4.比较两个字符数组内容是否完全相同
void compare_two_array(char arr1[], char arr2[], int len) {

}

int main(void) {
    //char arr1[] = {'a','r','7','*','y','t','i','o','b','4','u','x','8','a','3','0','%','m','e','c'};
    //vowel_number(arr1, ARR_LEN(arr1));

    //char arr2[20] = { 'a','b','c','d','e','0','a','e' };
    //find_vowel_and_insert(arr2, 8, ARR_LEN(arr2));

    char arr3[8] = { 'a','b','c','d','e','0','a','e' };
    copy_char_array(arr3, ARR_LEN(arr3));

    char arr4[8] = { 'a','b','c','d','e','0','a','e' };
    char arr5[8] = { 'a','b','c','d','e','o','a','e' };
    compare_two_array(arr4, arr5, 8);

    return 0;
}