#include<stdio.h>
#include<stdlib.h>
int gcd_extended(int a,int b,int *x,int *y)
{
    int x1,y1,gcd;
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    gcd=gcd_extended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
void modInverse(int a,int m)
{
	int x,y,gcd,result;
    gcd=gcd_extended(a,m,&x,&y);
	if(gcd!=1)
	{
		printf("Inverse doesn't exist");
	}
	else
	{
		result=((x%m)+m)%m;
		printf("Multiplicative Inverse is %d",result);
	}
}
int main()
{
    int a,m;
	scanf("%d%d",&a,&m);
	modInverse(a,m);
    return 0;
}