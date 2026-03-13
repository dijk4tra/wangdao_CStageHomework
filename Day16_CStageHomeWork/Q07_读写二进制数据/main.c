#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
在网盘项目中，常需要保存文件的元数据（如文件名、大小）。
定义一个文件信息结构体 `FileInfo`，将其实例以二进制块的方式写入磁盘，再重新读入内存。
要求：
    1. 定义结构体 `FileInfo`，包含 `char filename[64]` 和 `long filesize`。
    2. 使用 `fwrite()` 将结构体变量整体写入 `index.db`。
    3. 使用 `fread()` 将数据读回到新的结构体变量中并输出。
*/

int main(void) {
    
    return 0;
}