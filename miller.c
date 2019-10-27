#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int mod(int a,int b,int c)
{
	int arr1[100]={0},arr2[100]={0},t=b,l=0,i,result;
    while(t>0)
    {
        arr1[l++]=t%2;
        t=t/2;
    }
    arr2[0]=a%c;
    for(i=1;i<l;i++)
    {
        arr2[i]=(arr2[i-1]*arr2[i-1])%c;
    }
    t=1;
    for(i=0;i<l;i++)
    {
        if(arr1[i]==1)
        {
            t=t*arr2[i];
        }
    }
    result=t%c;
	return result;
}
int main()
{
	int n,temp,s,d,a,x,r,l,flag;
	scanf("%d",&n);
	s=1;
	flag=0;
	temp=n-1;
	while(1)
	{
		d=temp/pow(2,s);
		if(d%2==1)
		{
			break;
		}
		s++;
	}
	printf("%d %d\n",d,s);
	a=2;
	x=mod(a,d,n);
	if(x==1)
	{
		printf("%d is inconclusive\n",n);
	}
	else
	{
		for(r=1;r<s;r++)
		{
			l=pow(2,r);
			l=l*d;
			x=mod(a,l,n);
			if(x==n-1)
			{
				printf("%d is inconclusive\n",n);
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			printf("%d is Composite\n",n);
		}
	}
	return 0;
}