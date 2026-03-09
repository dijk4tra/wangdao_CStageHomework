#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
int count = 0;
int sum = 0;
int i;
while (count < 5) {
    scanf("%d", &i);
    if (i == 0) {
        // 输入0就不必要累加了
        continue;
    }
    sum += i;
    count++;
}
printf("sum = %d\n", sum);

// -----------------------------------  //

int sum = 0;
int i;
for (int count = 0; count < 5; count++) {
    scanf("%d", &i);
    if (i == 0) {
        // 输入0就不必要累加了
        continue;
    }
    sum += i;
}
printf("sum = %d\n", sum);
以上两段代码中都使用了continue关键字，一个使用while循环实现，一个使用for循环实现。

那么它们实现的功能有什么区别呢？为什么有这样的区别呢？
*/


/*
while循环需要输入五个非零整数才会结束循环。
而for循环总共只给五次输入整数的机会，输入五次整数后循环就会结束。
这是因为在while循环中，count++是写在循环体内部的普通语句，当执行到continue时，程序会直接跳回到while (count < 5) 进行条件判断，这就绕过了后面的count++。
而对于for循环，即使其在循环体中触发了continue，依然会执行更新表达式count++。
*/

int main(void) {
    printf("hello world!\n");
    return 0;
}