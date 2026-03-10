#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 函数isOdd：用于判断整数是否为奇数
int isOdd(int n) {
    // 只有当n的二进制最低位为1时，即n为奇数时，n&1的结果才为1
    return n & 1;
}

// 函数isPowerOfTwo：用于判断正整数是否为2的幂
int isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
    // 减法"-"的优先级高于"&", 所以内层的()可以省略
    // "=="优先级高于"&", 所以外层()必须加, 不能省略
}

// 函数getLSB：用于找出值为1的最低有效位 (Last Set Bit / LSB)
int getLSB(int n) {
    // n & -n 会提取出最右侧的 1 及其后面的 0 所构成的数值
    return n & -n;
}


int main(void) {
    // 交换两个不同的整数a和b的值
    int a = 25;
    int b = 26;
    printf("交换前: a = %d, b = %d\n", a, b);
    a = a ^ b; // a 变成 a 和 b 的混合状态
    b = a ^ b; // b 提取出原先的 a
    a = a ^ b; // a 提取出原先的 b
    printf("交换后: a = %d, b = %d\n\n", a, b);


    // 给定一个非空的整数数组nums，已知某个元素只出现了一次，其余元素均出现两次，需要找出这个只出现一次的元素
    int nums[] = { 4,1,2,1,2 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int single_num = 0;
    // 把所有数字全部异或一遍。成对出现的数字会相互抵消变成0
    // 最终剩下的就是那个落单的数字
    for (int i = 0; i < size; i++) {
        single_num = single_num ^ nums[i];
    }
    printf("整数数组nums中只出现一次的元素是: %d\n\n", single_num);



    // 扩展：给定一个非空的整数数组nums，已知有两个元素只出现了一次，其余元素均出现两次，请找出这两个只出现一次的元素
    int nums2[] = { 1, 2, 1, 3, 2, 5 };
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int xor_sum = 0;

    // 第一步：全部异或。最终结果 xor_sum 等于那两个落单元素(设为x和y)的异或值 (x ^ y)
    for (int i = 0; i < size2; i++) {
        xor_sum ^= nums2[i];
    }

    // 第二步：找到 xor_sum 中值为 1 的最低有效位 (LSB)
    // 这一位为 1，说明 x 和 y 在这一位上的二进制值是不一样的 (一个是0，一个是1)
    // 为防止 xor_sum 为 INT_MIN 导致溢出，强制转换为 unsigned int 是个好习惯
    unsigned int lsb = (unsigned int)xor_sum & -(unsigned int)xor_sum;

    int numX = 0;
    int numY = 0;

    // 第三步：利用这个差异位 lsb，将原数组拆分成两组
    // 一组在该位上是 1，另一组在该位上是 0。
    // 这样就把原问题降级成了两个 "第5题" 的情况：x 和 y 分别被分到了两组中
    for (int i = 0; i < size2; i++) {
        if (nums2[i] & lsb) {
            numX ^= nums2[i]; // 第一组全部异或
        }
        else {
            numY ^= nums2[i]; // 第二组全部异或
        }
    }
    printf("数组2中两个只出现一次的元素分别是: %d 和 %d\n", numX, numY);

    return 0;
}