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
	int open_p=0, open_b=0, close_p=0, close_b=0;
	bool last_b=0,last_p=0; // last_p = 0 if we last saw ) 1 if ( same with last_b
	setbuf(stdout, NULL);
	make_empty();
	printf("Enter parentheses and/or braces: ");
	while((c=getchar())!='\n'){
		push(c);
	}
	int i=0;
	while(i<top){
		c=contents[i];
		switch(c){
		case '(' :
			open_p++;
			last_p=1;
			last_b=0;
			break;

		case '{' :
			open_b++;
			last_b=1;
			last_p=0;
			break;
		case ')' :
			close_p++;
			if((close_p > open_p) || (1==last_b && 0==last_p))
				not_nested_properly();
			last_p=0;
			break;
		case '}' :
			close_b++;
			if((close_b > open_b) || (1==last_p && 0==last_b))
				not_nested_properly();
			last_b=0;
			break;
		default: break;

		}
		i++;
	}

	if(open_p==close_p && open_b==close_b)
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
    printf("\nStack underflow\n");
    exit(EXIT_FAILURE);
}
void not_nested_properly(void){
	printf("Parentheses/braces are not nested properly\n");
	exit(EXIT_FAILURE);
	return;
}
