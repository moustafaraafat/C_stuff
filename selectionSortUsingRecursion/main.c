#include <stdio.h>
#define N 5
void selection_sort(int a[], int n);

int main(void)
{
  int a[N], i;
  setbuf(stdout, NULL);
  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a,N);

  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}

void selection_sort(int a[], int n){
	int max=a[0],tem=0;
	if(n==1) return;
	for(int i=0; i<n; i++){
		if(a[i]>max) {
			max = a[i];
			tem = i;
		}
	}
	a[tem] = a[n-1];
	a[n-1]=max;

	selection_sort(a, n-1);

}


