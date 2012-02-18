/*
	测试能否对标准输入设置偏移量
*/
#include "apue.h"

int main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
	{
		printf("cannot seek\n");
	}
	else
	{
		printf("seek OK\n");
	}

	exit(0);
}

/* 结论: 标准输入STDIN是不能设置偏移量的，而对文本文件则可以 */
