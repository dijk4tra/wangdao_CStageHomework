#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void copy_binary_file(char *src_path, char *dest_path) {
    FILE *src_fp = fopen(src_path, "rb");
    FILE *dest_fp = fopen(dest_path, "wb");

    if (src_fp == NULL) {
        printf("fopen src failed.\n");
        return;
    }

    if (dest_fp == NULL) {
        printf("fopen dest failed.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(src_fp)) != EOF) {
        fputc(ch, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);
}

void test2() {
    // 相对路径： 关键点是，相对路径的起点是什么。
    // 在VS中运行代码。相对路径的起点是。项目的根目录 。 
    // 在命令行运行代码。相对路径的起点是。你执行程序的位置。 

    // 如果用绝对路径，没有这个问题。 

    // 相对路径用的会多一些。 
}

void test3() {
    // b就是专门给二进制文件用的，在读取文件和写出文件的过程中，数据是什么就操作什么
    // 不要进行任何转换过程。 

    // 如果不加 会出现复制不成功。 晚上可以试一下。 
}

void test4() {
    // 又使用了一下命令行参数。 可以提升代码的一些灵活性。 

    // 11_复制.exe C:\Users\zhoubing\Desktop\tmp\1.png C:\Users\zhoubing\Desktop\tmp\1111.png
    // 11_复制.exe C:\Users\zhoubing\Desktop\tmp\1.mp4 C:\Users\zhoubing\Desktop\tmp\2222.mp4
    // 11_复制.exe 1.mp4 2222.mp4
    // 11_复制.exe 1.png 2222.png
}


int main(int argc, char *argv[]) {
    // 从命令行接收参数。 
    // 11_复制.exe  1.png 1_copy.png

    // 11_复制.exe 
    // int argc = 1, char *argv[] ==== 11_复制.exe 
    // 11_复制.exe  1.png 1_copy.png
    // argc=3   argv[] 
    if (argc != 3) {
        printf("arg count error!\n");
        return;
    }

    char *path1 = "1.txt";
    char *path2 = "2.txt";

    copy_binary_file(path1, path2);
    copy_binary_file(argv[1], argv[2]);

    return 0;
}