#include "apue.h"

int main(int argc, const char *argv[])
{
	int fd;
	
	if ((fd = open("open", O_CREAT && O_EXCL, FILE_MODE)) < 0)	
	{
		perror("open");
	}
	return 0;
}
