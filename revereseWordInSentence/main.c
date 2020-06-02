#include <stdio.h>

int main(void) {
	char ch[100]={0}, lastChar='\0';
	int i=0,firstSpace=0, secondSpace=0,j=2;

	printf("Enter a sentence: ");
	fflush(stdout);
	while((ch[i]=getchar())!='.'  && ch[i]!='?' && ch[i]!='!'){
		i++;
	}
	lastChar=ch[i];
	ch[i]=' ';
	secondSpace=i;
	while(i>=0){
		if(ch[i]==' ' ){
			firstSpace=i;
		for(j=firstSpace+1;j<=secondSpace;j++) putchar(ch[j]);
		secondSpace=firstSpace;
		}
		if (i==0) for(j=0;j<secondSpace;j++) putchar(ch[j]);
		i--;
	}
	printf("%c",lastChar);

	return 0;
}
