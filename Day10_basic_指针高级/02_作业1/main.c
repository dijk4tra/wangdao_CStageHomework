#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// 123abcABCMMMabbb
	char *p = "123abcABCMMMabbb";

	// 准备一个数组， 使用 128 个长度的数组。 
	int count_arr[129] = { 0 };

	while (*p != '\0') {
		char ch = *p++; // 将单个字符捞出来。 

		if (ch >= 'a' && ch <= 'z') {
			// 说明是小写字母。 
		}
		else if (ch >= 'A' && ch <= 'Z') {
			// 说明大写字母. 统计过程中忽略大小写的差异，
			// 如果是大写，转成小写对应的ASCII存储。 
			ch = ch + ('a' - 'A');
		}
		else if (ch >= '0' && ch <= '9') {
		}
		count_arr[ch]++;
	}

	// 需要将字符串一个一个弄出来。 {
	//     一个一个的字符。 
	//     // 大写 小写 数字。 
	//     'a'  'z'   'A' 'Z'  '0'   '9' 
	// }

	//给定一个字符串，要求它可能包含数字和字母。
	//请编写函数，统计该字符串中每个字符出现的次数，统计过程中忽略大小写的差异，
	// 并打印最终每个字符出现的次数。
	//提示：

	//用一个int数组存储字符出现的次数，可以用一个128长度的数组，这样数组下标位置的元素就是该编码值字符出现的次数，缺点是浪费空间，但你可以先写一个这样的实现。

	//（扩展）做完后，你可以思考一下：

	//实际上只会有36个字符(10个数字和26个不区分大小写的字母)，所以int数组的长度实际上只需要36就可以了。

	//那么怎么把数组的长度缩短到36呢？


}

int convert_char_to_index(char ch) {
	int related_index = 0;
	// 字母 26  数字。10
	if (ch >= 'a' && ch <= 'z') {
		// 说明是小写字母。 
		related_index = ch - 'a';
	}
	else if (ch >= 'A' && ch <= 'Z') {
		related_index = ch - 'A';
	}
	else if (ch >= '0' && ch <= '9') {
		related_index = ch - '0' + 26;
	}

	return related_index;
}


char convert_index_to_char(int index) {
	if (index >= 0 && index <= 25) {
		// 说明是字母对应的index
		return index + 'a';
	}

	return index - 26 + '0';
}

void test2() {
	// 123abcABCMMMabbb
	char *p = "123abcABCMMMabbb";

	int count_arr[36] = { 0 };

	while (*p != '\0') {
		char ch = *p++; // 将单个字符捞出来。 

		int related_index = convert_char_to_index(ch);

		count_arr[related_index]++;
	}

	//给定一个字符串，要求它可能包含数字和字母。
	//请编写函数，统计该字符串中每个字符出现的次数，统计过程中忽略大小写的差异，
	// 并打印最终每个字符出现的次数。
	//提示：

	//用一个int数组存储字符出现的次数，可以用一个128长度的数组，这样数组下标位置的元素就是该编码值字符出现的次数，缺点是浪费空间，但你可以先写一个这样的实现。

	//（扩展）做完后，你可以思考一下：

	//实际上只会有36个字符(10个数字和26个不区分大小写的字母)，所以int数组的长度实际上只需要36就可以了。

	//那么怎么把数组的长度缩短到36呢？



}


int main(void) {

	return 0;
}