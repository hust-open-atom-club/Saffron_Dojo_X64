#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "util.h"

#define BUF_LEN 0x40
#define OOB_LEN 0x80

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void read_flag(char *filename)
{
	char *p;
	FILE *fp;
	char flag[BUF_LEN];

	memset(flag, 0, sizeof(flag));
	fp = fopen(filename, "r");

	if (!fp) {
		perror("[-] fopen failed");
	}

	p = fgets(flag, sizeof(flag), fp);
	if (!p) {
		perror("[-] fgets failed");
		fclose(fp);
	}
	
	printf("%s\n", flag);

	fclose(fp);
}

int main()
{
	char buffer[BUF_LEN];

	init();
	print_desc();

        printf("Say something at %p\n", buffer);
        printf(">>> ");
	read(0, buffer, OOB_LEN);

	print_exit();

	return 0;
}
