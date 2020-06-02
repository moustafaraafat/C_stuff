#include <stdio.h>

size_t my_strlen(const char *s);
int main(void) {
	char ch[15]="Hello123";
	printf("%d", my_strlen(ch));
	return 0;
}
size_t my_strlen(const char *s){
	const char *p = s;
	while(*s)
		s++;
	return s-p;
}
