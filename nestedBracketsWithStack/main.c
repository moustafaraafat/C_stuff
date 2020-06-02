#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool empty_stack(void);
bool full_stack(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);
void not_nested_properly(void);

int main(void) {
	char c;
	setbuf(stdout, NULL);
	make_empty();
	printf("Enter parentheses and/or braces: ");
	while((c=getchar())!='\n'){
		switch(c){
		case '(': case '{':
			push(c);
			break;
		case ')':
			if(pop()=='(');
			else not_nested_properly();
			break;
		case '}':
			if(pop()=='{');
			else not_nested_properly();
			break;
		default: break;
		}
	}
	if(empty_stack())
		printf("Parentheses/braces are nested properly\n");
	else not_nested_properly();
	return 0;
}

void make_empty(void){
	top=0;
}
bool empty_stack(void){
	return 0==top;
}
bool full_stack(void){
	return STACK_SIZE==top;

}
void push(char c){
	if(full_stack()) stack_overflow();
	else contents[top++]=c;
}
char pop(void){
	if(empty_stack()) stack_underflow();
	return contents[--top];
}
void stack_overflow(void) {
    printf("\nStack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
	not_nested_properly();
}
void not_nested_properly(void){
	printf("Parentheses/braces are not nested properly\n");
	exit(EXIT_FAILURE);
	return;
}
