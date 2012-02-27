/*
	对一个文件描述符打开一个或多个文件状态标志
*/

#include "apue.h"
#include <fcntl.h>

#define BUFFERSIZE 1024

int main(int argc, const char *argv[])
{
	char buffer[BUFFERSIZE];
	int n;

	set_fl(STDOUT_FILENO, O_SYNC);
	if ((n = read(STDIN_FILENO, buffer, BUFFERSIZE)) > 0)
	{
		if ((write(STDOUT_FILENO, buffer, n))  != n)
		{
			err_sys("wirte error");
		}
	}

	if (n < 0)
	{
		err_sys("read error");
	}
	
	return 0;
}

void set_fl(int fd, int flags)	/* flags are file status flags ro turn on */
{
	int val = 0;

	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		err_sys("fcntl F_GETFL error");
	}

	val |= flags;	/* trun on flags */
	/* val &= ~flags turn off flags  */
	if (fcntl(fd, F_GETFL, val) < 0)
	{
		err_sys("fcntl F_GETFL error");
	}
}



