#include <stdio.h>

#define UNUSEDPARAM(x) \
	if (x) {       \
	}
int main(int argc, char **argv)
{
	UNUSEDPARAM(argc);
	UNUSEDPARAM(argv);

	printf("Second Rewrite of CVM\n");
}