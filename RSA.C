#include<stdio.h>
#include<stdlib.h>
long long int fast_modular(long long int a,long long int b,long long int c)
{
    long long int arr1[1000]={0},t,l,i,arr2[1000]={0};
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
            t=(t*arr2[i])%c;
        }
    }
    return t%c;
}
long long int gcd(long long int a,long long int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
long long int finde(long long int toient)
{
    long long int e,i;
    for(i=2;i<toient;i++)
    {
        e=i;
        if(gcd(e,toient)==1)
        {
            break;
        }
    }
    return e;
}
long long int encryption(long long int plain_text,long long int e,long long int n)
{
    long long int cipher_text;
    cipher_text=fast_modular(plain_text,e,n);
    return cipher_text;
}
long long int decryption(long long int cipher_text,long long int e,long long int toient,long long int n)
{
    long long int plain_text,d;
    int k;
    for(k=1;k<toient;k++)
    {
        if(((k*toient)+1)%e==0)
        {
            break;
        }
    }
    d=((k*toient)+1)/e;
    printf("d is: %lld\n",d);
    plain_text=fast_modular(cipher_text,d,n);
    return plain_text;
}
int main()
{
    long long int p,q,n,toient,e,plain_text,cipher_text,plain_text_1;
    printf("Enter two prime numbers p and q: ");
    scanf("%lld %lld",&p,&q);
    n=p*q;
    printf("n is: %lld\n",n);
    toient=(p-1)*(q-1);
    printf("toient is: %lld\n",toient);
    e=finde(toient);
    printf("e is %lld\n",e);
    printf("Enter plain text: ");
    scanf("%lld",&plain_text);
    cipher_text=encryption(plain_text,e,n);
    printf("Cipher Text after encryption is: %lld\n",cipher_text);
    plain_text_1=decryption(cipher_text,e,toient,n);
    printf("Plain Text after decryption is: %lld",plain_text_1);
    return 0;
}