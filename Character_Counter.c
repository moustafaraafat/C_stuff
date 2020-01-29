#include <stdio.h>

int main(void) {
	int i;
	
	printf("Enter a message: ");
	fflush(stdout);
	for(i=0;getchar()!='\n';i++);
	printf("Your message was %d character(s) long.",i);

	return 0;
}
