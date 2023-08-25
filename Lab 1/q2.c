#include <stdio.h>

int fiv(int n)
{
	static int a;
	a=n+a;		
	return a;
}	

int main()
{
	int n[10];
	int res[10];
	for(int i=0;i<5;i++)
	{
		printf("Enter %d number\n",i);
		scanf("%d",&n[i]);
	}
	for (int i=0;i<5;i++)
	{
		res[i]=fiv(n[i]);
	}
	printf("Final Array is =\n");
	for (int i=0;i<5;i++)
	{
		printf(" %d ", res[i]);
	}
	return 0;
		
}
