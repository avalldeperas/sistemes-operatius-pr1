#include <stdlib.h>
#include <stdio.h>

#define WAIT (1<<15)

void proc()
{
	int loop=WAIT;

	while (loop--) {
		// printf("loop = %d\n", loop);
	}

	proc();
}

int main(int argc, char *argv[])
{
	proc();

	exit(0);
}
