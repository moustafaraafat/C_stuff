#include <stdio.h>

int max_0s_between_two_1s_binary(unsigned int num);

int main(void) {
	unsigned int x= 0b10000000000101000001100010001001;
	int zeros;
	zeros = max_0s_between_two_1s_binary(x);
	printf("%d", zeros);
	return 0;
}

int max_0s_between_two_1s_binary(unsigned int num)
{
	int i,j, count=0, countmax=0;
	for(i=0; i < sizeof(num)*8-1; i++)
	{
		if( ( num & (1<<i) ) )
		{
			for (j=i+1; !(num & (1<<j) ) && (j< sizeof(num)*8) ;j++)
				count++;
			if(j == sizeof(num)*8)   //only in 0000000011 (not closed with 1)
				count = 0;
			if (count>=countmax)
			{
				countmax = count;
			}
			count = 0;
			i=j-1; // it will be j because off i++
		}

	}
	return countmax;
}
