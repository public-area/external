#include<stdio.h>
#include<stdlib.h>
int inv(int a,int m)
{
    int m0=m,t,q,x0=0,x1=1;
    if(m==1)
    {
        return 0;
    }
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if(x1<0)
    {
        x1+=m0;
    }
    return x1;
}
int findmin(int *divisor_array,int *remainder_array,int n)
{
    int prod=1,i,result=0,pp;
    for(i=0;i<n;i++)
    {
        prod=prod*divisor_array[i];
    }
    for(i=0;i<n;i++)
    {
        pp=prod/divisor_array[i];
        result+=remainder_array[i]*inv(pp,divisor_array[i])*pp;
    }
    return result%prod;
}
int main()
{
    int n,*divisor_array,*remainder_array,i,result;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    divisor_array=(int *)malloc(n*sizeof(int));
    remainder_array=(int *)malloc(n*sizeof(int));
    printf("Enter divisor array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&divisor_array[i]);
    }
    printf("Enter remainder array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&remainder_array[i]);
        remainder_array[i]=remainder_array[i]%divisor_array[i];
    }
    result=findmin(divisor_array,remainder_array,n);
    if(result==0)
    {
        printf("There is no solution for given input");
    }
    printf("Number is: %d",result);
    return 0;
}