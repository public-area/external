#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{
	if(b!=0)
	{
		return gcd(b,a%b);
	}
	else
	{
		return a;
	}
}
int cmp(const void *x,const void *y)
{
	return *(int *)x-*(int *)y;
}
int main()
{
	int arr[10],i,a,b;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	qsort(arr,10,sizeof(int),cmp);
	b=arr[0];
	i=1;
	while(i<10)
	{
		a=arr[i];
		i++;
		b=gcd(a,b);
	}
	printf("%d",b);
	return 0;
}