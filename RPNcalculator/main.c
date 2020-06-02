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
void read_expression(void);

int main(void) {
	setbuf(stdout, NULL);
	read_expression();
	return 0;
}

void read_expression(void){
	char c;
	int result, num1, num2;
	make_empty();
	printf("Enter an RPN expression: ");
	do{
		scanf(" %c", &c);
		if(c>='0' && c<='9') push(c);
		else if(c=='+'|| c=='-' || c=='*' || c=='/') {
			num2 = pop()-48;
			num1 = pop()-48;
			switch(c) {
			case '+':
				push(num1+num2+48);
            break;
			case '-':
				push(num1-num2+48);
            break;
			case '*':
				push(num1*num2+48);
            break;
			case '/':
				push(num1/num2+48);
            break;
			default:
            break;			}
		}
		else if(c=='='){
			result = pop()-48;
			printf("Value of expression: %d\n", result);
			empty_stack();
			printf("Enter an RPN expression: ");
		}

	}while(c!='q');

	return;
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
    printf("\nExpression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
	printf("Not enough operands in expression\n");
	exit(EXIT_FAILURE);
	return;}
