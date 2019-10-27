#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *s,*key;
    int **mat,k,i,j,n,**pt,**result,sum=0;
    printf("Enter Plain Text: ");
    s=(char *)malloc(100*sizeof(char));
    scanf("%s",s);
    n=strlen(s);
    printf("Enter key of length %d: ",n*n);
    key=(char *)malloc(n*n*sizeof(char));
    scanf("%s",key);
    mat=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        mat[i]=(int *)malloc(n*sizeof(int));
    }
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mat[i][j]=key[k]-'A';
            k++;
        }
    }
    pt=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        pt[i]=(int *)malloc(1*sizeof(int));
    }
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            pt[i][j]=s[k]-'A';
            k++;
        }
    }
    result=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        result[i]=(int *)malloc(1*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            for(k=0;k<n;k++)
            {
                sum=sum+(mat[i][k]*pt[k][j]);
            }
            result[i][j]=sum%26;
            sum=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("%c",result[i][j]+'A');
        }
        printf("\n");
    }
    return 0;
}