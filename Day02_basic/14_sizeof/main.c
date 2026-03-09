#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // sizeof 可以用于计算一个类型占多大空间
    // sizeof（类型）
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(float));

    // sizeof（变量名）：可以计算一个变量占多大空间
    long long num1 = 10L;
    printf("%d\n", sizeof(num1));

    // sizeof（表达式）
    printf("%d\n", sizeof(2 + 3));     // 整数相加不改变类型
    printf("%d\n", sizeof(2 + 3.4));   // 默认浮点字面量是 double，整数向高精度转换
    printf("%d\n", sizeof(2 + 3.4f));  // f 后缀指定为 float
    // 注意：sizeof 是在编译时计算的。2 + 3.4 这种运算并不会在程序运行时真正执行，编译器只是推导出了这个表达式的“最终大小”
    // 在编译过程中，sizeof(2 + 3.4)，编译器不会计算2 + 3.4，而是根据这个两个数的类型（int和double），得到了结果 8（8字节），然后用‘8’直接替换掉‘sizeof(2 + 3.4)’
    // 最终结果：程序运行到这一行时，CPU 接收到的指令其实只是 printf("%d\n", 8);
    // sizeof()是“根据类型推导大小”而不是“计算数值”

    /*
    经典证据——副作用失效
    int i = 10;
    printf("%zu\n", sizeof(i++)); // i++ 是一个赋值操作
    printf("%d\n", i);            // 猜猜 i 现在是多少？
    结果是：i 的值依然是 10
    解释：因为 sizeof 只关心 i++ 的结果类型（即 int），它在编译时就把结果定为 4 了。程序运行时，i++ 这行代码压根没有被执行，所以 i 的值没变！
    */ 
     
    /*
    一个极端的例子
    运行时逻辑：如果在程序里运行 int a = 1 / 0;，程序会因为除以 0 直接崩溃（Floating point exception）
    sizeof 逻辑：这段代码不仅能跑通，还会打印出 4
    原因：编译器看到 1 是 int，0 也是 int，所以 1 / 0 的结果类型一定是 int。既然是 int，大小就是 4
    它根本不去算 1 除以 0 到底等于多少，所以完美的避开了崩溃
    */

}

int main(void) {
    test1();
    return 0;
}