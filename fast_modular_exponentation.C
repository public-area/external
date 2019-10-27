#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,arr1[20]={0},t,l,i,arr2[20]={0};
    scanf("%d%d%d",&a,&b,&c);
    t=b;
    l=0;
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
    printf("%d",t%c);
    return 0;
}