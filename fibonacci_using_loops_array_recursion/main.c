#include <stdio.h>

int fibonacci_loops(int index);
int fibonacci_array(int index);
int fibonacci_recursion(int index);

int main(void) {
	setbuf(stdout, NULL);
	int n;
	printf("Enter the index of the nth term: ");
	scanf(" %d", &n);
	printf("The %dth term using loops is %d\n", n, fibonacci_loops(n));
	printf("The %dth term using arrays is %d\n", n, fibonacci_array(n));
	printf("The %dth term using recursion is %d\n", n, fibonacci_recursion(n));

	return 0;
}
int fibonacci_loops(int index){ //not too much memory only 4 integers
	int i, term=index-1, term1=0, term2=1;

	for(i=3	; i<=index; i++){
		term = term1 + term2;
		term1 = term2;
		term2 = term;

	}
	return term;
}
int fibonacci_array(int index){  //too much memory, up to n + 1 integers
	int a[index], i;
	a[0]=0;
	a[1]=1;
	for(i=2	; i<index; i++){
		a[i]=a[i-1]+a[i-2];
	}
	return a[index-1];
}
int fibonacci_recursion(int index){
	if (index <= 2)
		return index-1;
	return fibonacci_recursion(index -1)+fibonacci_recursion(index-2);
}
