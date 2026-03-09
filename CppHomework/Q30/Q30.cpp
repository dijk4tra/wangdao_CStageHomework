#include <stdio.h>

// 约瑟夫环问题：n个人围成一圈，从第k个人开始报数，数到m的人出列，接着从下一个人重新报数，直到所有人出列，输出出列顺序
void josephus(int n, int k, int m) {
    // n: 总人数
    // k: 从第几个人开始 (1-based)
    // m: 数到几出列
    int people[100]; // 假设最多100人
    // 初始化数组，值为 1~n，代表每个人的编号
    // people[0] = 1, people[1] = 2, ..., people[n-1] = n
    for (int i = 0; i < n; i++) {
        people[i] = i + 1;
    }

    int count = 0;      // 记录当前报数报到了几
    int outCount = 0;   // 记录已经出列了多少人
    int index = k - 1;  // 当前数组下标（因为数组从0开始，所以 k-1）

	printf("出列顺序: ");

    // 只要出列人数没达到 n，就继续循环
    while (outCount < n) {
        // 如果当前这个人还在圈里（值不为0）
        if (people[index] != 0) {
            count++; // 报数 +1

            // 如果报数到了m，当前人员出列
            if (count == m) {
                printf("%d ", people[index]); // 打印出列人的编号
                people[index] = 0; // 标记为0，表示已出列
                outCount++;        // 出列人数 +1
                count = 0;         // 报数归零，从下一个人重新开始报数
            }
        }

        // 移动到下一个位置
        index++;
        // 实现环形结构：如果超出数组末尾，则回到数组开头
        if (index == n) {
            index = 0;
        }
    }
    printf("\n");
}

int main() {
	// 示例：一共5个人，从第1个人开始报数，数到3的人出列
    int n = 5;  // 总人数：5
    int k = 1;  // 起始位置：从第1个人开始
    int m = 3;  // 出列报数：数到3的人出列

    // 调用约瑟夫环求解函数
    josephus(n, k, m);

    return 0; 
}
