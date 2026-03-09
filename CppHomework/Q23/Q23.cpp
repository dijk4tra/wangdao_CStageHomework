#include <stdio.h>
#include <ctype.h> // 用于 isalpha

int main() {
	char str[] = "As a technology, \"HailStorm\" is so new";
	int count = 0;
	int inWord = 0; // 0表示当前没在单词里，1表示在单词里
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) { // 如果是字母
			if (inWord == 0) { // 如果之前不在单词里
				count++;      // 刚开始进入一个新单词，单词计数加1
				inWord = 1;   // 标记为在单词里
			}
		}
		else {
			inWord = 0; // 遇到非字母，状态变为“在单词外”
		}
	}

	printf("该字符串中单词的个数是: %d\n", count);
	return 0;
}