/*
	验证如果是使用添加（O_APPEND）打开一个文件，那么还可以使用lseek在
	任一位置开始读？能否用lseek更新文件中任意部分的数据
*/

#include "apue.h"
#include <fcntl.h>

#define BUFFERSIZE 1024

int main(int argc, const char *argv[])
{
	int fd;
	int val;
	char buffer[BUFFERSIZE];
	char ch[] = "I like APUE";

	if ((fd = open("test", O_APPEND)) < 0)
	{
		err_sys("open error");
	}
	

//	if (write(fd, ch, sizeof(ch)) != sizeof(ch))
//	{
//		err_sys("write error");
//	}



	if(lseek(fd, 0, SEEK_END) == -1)	/* EOF */
	{
		err_sys("lseek error1");
	}
	if (read(fd, buffer, BUFFERSIZE) > 0)
	{
		puts(buffer);
	}
//	if(write(fd, ch, sizeof(ch)) != sizeof(ch))
//	{
//		err_sys("write error1");
//	}
	


	if (lseek(fd, 0, SEEK_CUR) == -1)	/* EOF */
	{
		err_sys("lseek error2");
	}
	if (read(fd, buffer, BUFFERSIZE) > 0)
	{
		puts(buffer);
	}
//	if (write(fd, ch, sizeof(ch)) != sizeof(ch))
//	{
//		err_sys("write error2");
//	}



	if(lseek(fd, 0, SEEK_SET) == -1)	/* the beginning of file */
	{
		err_sys("lseek error3");
	}
//	if (read(fd, buffer, BUFFERSIZE) > 0)
//	{
//		puts(buffer);
//	}
	if ((write(fd, ch, sizeof(ch))) != sizeof(ch))
	{
		err_sys("write error3");
	}



	close(fd);
	return 0;
}

/*
	结论: 可以使用lseek在任一位置开始读，但是不能在任意部分写数据，只能在文件末下数据
*/
