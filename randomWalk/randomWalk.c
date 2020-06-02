#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
	char a[10][10], c[26];
	int i, j,rows=0, cols=0,dir;
	srand((unsigned)time(NULL));
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			a[i][j]='.';
	}
	for(i=0;i<26;i++)
		c[i]='A'+i;
	i=1;
	a[0][0]=c[0];
	while(i<26){
		dir = rand() % 4;
		switch(dir){
		case 0: cols++; break;
		case 1: rows++; break;
		case 2: cols--; break;
		case 3: rows--; break;
		default: break;
		}
		if(a[rows][cols]=='.' && rows >=0 && cols >=0){
			a[rows][cols]=c[i];
			i++;
		}
		else switch(dir){
		case 0: cols--; break;
		case 1: rows--; break;
		case 2: cols++; break;
		case 3: rows++; break;
		default: break;
		}
		if(a[rows+1][cols]!='.'&&a[rows][cols+1]!='.'&&a[rows-1][cols]!='.'&&a[rows][cols-1]!='.')
			break;
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}

	return 0;
}
