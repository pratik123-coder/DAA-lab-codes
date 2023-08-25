#include <stdio.h>
void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
	
}
void sort(int arr[], int n)   // Using Selection Sort Algorithm
{
	int i, j, min_idx;
	for (i=0; i<n-1;i++)
	{
		min_idx = i; // Initialize min_idx with the current index i
		for (j=i+1; j<n;j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx=j;
			}
		}
		if (min_idx!=i)
		{
			swap(&arr[min_idx],&arr[i]);
		}	
	}
}

int main()
{
	int arr[10];
	int n=5;
	for (int i=0;i<5;i++)
	{
		printf("Enter %d number - ",i);
		scanf("%d",&arr[i]);	
	}
	sort(arr,n);
	printf("Second Largest number is = %d\n", arr[3]);
	printf("Second Smallest number is = %d", arr[1]);	
	
	
}
