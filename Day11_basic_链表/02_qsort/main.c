#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_LEN(arr) ((sizeof(arr))/(sizeof(arr[0])))

void test1() {
    // qsort：系统提供的一个排序函数
    // 系统为我们写好了排序，但现在有一个问题
    // 这个排序应该具有可扩展性

    // 现在，有一个结构体数组，想要用qsort对其排序
    // 需要用到函数指针
}

void select_sort(int arr[], int len) {
    // 选择排序：每一轮，选择最小的元素放到最前面
    for (int i = 0; i < len; i++) {
        // 需要将剩下数组中的最小值找出来
        int min_index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;

    }
}

void test2() {
    int arr[] = { 10,30,1,5,98,8,7,65,35,15,1256,56,4 };

    int len = ARR_LEN(arr);
    select_sort(arr, len);
    
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare_int(const void *a, const void *b) {
    // a b 是什么东西？
    // 这两个指针，始终是数据的指针
    // 数据的类型为int，数据的指针是int *
    int *p1 = a;
    int *p2 = b;

    return *p1 - *p2;
    //return *p2 - *p1;     // 降序
}

void test3() {
    printf("test3================\n");
    int arr[] = { 10,30,1,5,98,8,7,65,35,15,1256,56,4 };

    // void qsort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

    // 作用是排序，任意类型都要能排
    qsort(arr, ARR_LEN(arr), sizeof(int), compare_int);
    // qsort(arr, ARR_LEN(arr), sizeof(int), compare_int(&arr[i], &arr[j]));  // 错误写法
    // 只需要把函数指针交给qsort即可

    for (int i = 0; i < ARR_LEN(arr); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

typedef struct {
    int id;
    char name[20];
    int chinese;
    int math;
    int english;
}Student;

// 如果想要对这个结构体按id排序
int compare_student_by_id(const void *a, const void *b) {
    // a b是数据的指针
    // 数据是结构体，数据的指针是结构体指针

    Student *p_s1 = a;
    //Student s1 = *(Student *)a;
    Student *p_s2 = b;

    return p_s1->id - p_s2->id;
}

int compare_student_by_score(const void *a, const void *b) {
    // a b是数据的指针
    // 数据是结构体，数据的指针是结构体指针

    // 如果想按语文分数排（降序排）
    // 语文相同，按数学排
    // 数学相同，按英语排

    Student *p_s1 = a;
    Student *p_s2 = b;

    if (p_s1->chinese != p_s2->chinese) {
        return p_s1->chinese - p_s2->chinese;
    }
    if (p_s1->math != p_s2->math) {
        return p_s1->math - p_s2->math;
    }
    return p_s1->english - p_s2->english;
  
    /*
    if (p_s1->chinese == p_s2->chinese) {
        if (p_s1->math == p_s2->math) {
            return p_s1->english - p_s2->english;
        }
        return p_s1->math - p_s2->math;
    }
    // 不要使劲嵌套if，可以反着想一下条件
    return p_s1->chinese - p_s2->chinese;
    */
}

void test4() {
    printf("test4================\n");
    Student s1 = { 1, "zhangsan1", 90, 70, 70 };
    Student s2 = { 9, "zhangsan9", 90, 80, 75 };
    Student s3 = { 3, "zhangsan3", 80, 60, 80 };
    Student s4 = { 4, "zhangsan4", 70, 80, 69 };
    Student s5 = { 2, "zhangsan2", 100, 40, 80 };
    Student s6 = { 7, "zhangsan7", 95, 90, 81 };
    Student s7 = { 6, "zhangsan6", 80, 100, 80 };


    Student stu_arr[7] = { s1,s2,s3,s4,s5,s6,s7 };

    //qsort(stu_arr, 7, sizeof(Student), compare_student_by_id);

    qsort(stu_arr, 7, sizeof(Student), compare_student_by_score);
    
    for (int i = 0; i < 7; i++) {
        printf("ID: %d, 姓名: %s, 语文: %d, 数学: %d, 英语: %d\n",
            stu_arr[i].id,
            stu_arr[i].name,
            stu_arr[i].chinese,
            stu_arr[i].math,
            stu_arr[i].english);
    }

}

int compare_string(const void *a, const void *b) {
    // a 和 b 是数组元素的地址
    // 数组元素类型是 char*，所以 a 和 b 是 char** 类型
    char **pp1 = (char **)a;
    char **pp2 = (char **)b;

    // 3我们要比较的是字符串内容，strcmp 需要 char* 参数。
    // *p1 得到的就是数组中存储的那个字符串的首地址。
    return strcmp(*pp1, *pp2);
    // 如果想降序排列，只需：return strcmp(*p2, *p1);

    //char *str1 = *(const char **)a;
    //char *str2 = *(const char **)b;
    //return strcmp(str1, str2);
}

void test5() {
    // 对于字符串数组的排序
    // 指针数组

    char *str_arr[] = { "abc","ab","ad","b","bc","dd" };

    // 现在想排这个字符串数组的序，怎么排？
    // 数组中装的指针

    // 参数解释：
    // 1. str_arr: 数组首地址
    // 2. len: 元素个数
    // 3. sizeof(char *): 每个元素（即指针）的大小
    // 4. compare_string: 比较逻辑
    qsort(str_arr, 6, sizeof(char *), compare_string);

    // 打印排序后的结果
    for (int i = 0; i < 6; i++) {
        printf("%s ", str_arr[i]);
    }
    printf("\n");
}

int main(void) {
    //test3();
    test4();
    //test5();
    return 0;
}