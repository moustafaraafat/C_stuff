#include <stdio.h>

char * my_strcat(char *s1, const char *s2);
int main(void) {
	char ch1[15]="Hello";
	char ch2[15]="world";
	my_strcat(ch1, ch2);
	printf("%s", ch1);
	return 0;
}
char * my_strcat(char *s1, const char *s2){
	char *p =s1;
	while (*p)
		p++;
	while((*p++=*s2++))
		;
	return s1;
}
