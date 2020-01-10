#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "hello";
	char rev[10];

	strcpy(rev, str);

	printf("%c", rev[2]);
	return 0;
}
