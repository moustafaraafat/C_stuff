/*
 ============================================================================
 Name        : ch13e11my_strcmp.c
 Author      : Raafat
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
int my_strcmp(const char *s, const char *t);

int main(void) {
	char s1[10] = "abc";
	char s2[10] = "abcd";
	printf("%d", my_strcmp(s1, s2));

	return 0;
}

int my_strcmp(const char *s, const char *t)
{
	while(*s==*t)
	{
		if(!*s)
			return 0;
		s++;
		t++;
	}
	return *s - *t;
}
