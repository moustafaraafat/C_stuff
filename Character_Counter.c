#include <stdio.h>

int main(void) {
	int i;
	
	prinf("Enter a message: ");
	for(i=0;getchar()!='\n';i++);
	printf("Your message was %d character(s) long.",i);

	return 0;
}
