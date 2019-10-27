#include<stdio.h>
#include<stdlib.h>
int p10[10]={3,5,2,7,4,10,1,9,8,6};
int ls1[5]={2,3,4,5,1};
int p8[8]={6,3,7,4,8,5,10,9};
int ls3[5]={4,5,1,2,3};
int ip[8]={2,6,3,1,4,8,5,7};
int ep[8]={4,1,2,3,2,3,4,1};
int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
int s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int p4[4]={2,4,3,1};
int sw[8]={5,6,7,8,1,2,3,4};
int ipinv[8]={4,1,3,5,7,2,8,6};
char *findkey(char *key,int l)
{
    char *temp_key,*text,*left_text,*right_text;
    int i;
    temp_key=(char *)malloc(8*sizeof(char));
    text=(char *)malloc(10*sizeof(char));
    left_text=(char *)malloc(5*sizeof(char));
    right_text=(char *)malloc(5*sizeof(char));
    for(i=0;i<10;i++)
    {
        text[i]=key[p10[i]-1];
    }
    for(i=0;i<5;i++)
    {
        left_text[i]=text[i];
        right_text[i]=text[i+5];
    }
    if(l==1)
    {
        for(i=0;i<5;i++)
        {
            text[i]=left_text[ls1[i]-1];
            text[i+5]=right_text[ls1[i]-1];
        }
    }
    else if(l==2)
    {
        for(i=0;i<5;i++)
        {
            text[i]=left_text[ls3[i]-1];
            text[i+5]=right_text[ls3[i]-1];
        }   
    }
    for(i=0;i<8;i++)
    {
        temp_key[i]=text[p8[i]-1];
    }
    free(text);
    free(left_text);
    free(right_text);
    return temp_key;
}
char *findf(char *text,char *key)
{
    char *text1,*text2,*text3;
    int i,row,col,val1,val2;
    text1=(char *)malloc(8*sizeof(char));
    text2=(char *)malloc(4*sizeof(char));
    text3=(char *)malloc(4*sizeof(char));
    for(i=0;i<8;i++)
    {
        text1[i]=text[ep[i]-1];
    }
    for(i=0;i<8;i++)
    {
        if(text1[i]==key[i])
        {
            text1[i]='0';
        }
        else
        {
            text1[i]='1';
        }
    }
    row=(text1[0]-'0')*2+(text1[3]-'0')*1;
    col=(text1[1]-'0')*2+(text1[2]-'0')*1;
    val1=s0[row][col];
    row=(text1[4]-'0')*2+(text1[7]-'0')*1;
    col=(text1[5]-'0')*2+(text1[6]-'0')*1;
    val2=s1[row][col];
    switch(val1)
    {
        case 0:text2[0]='0';
        text2[1]='0';
        break;
        case 1:text2[0]='0';
        text2[1]='1';
        break;
        case 2:text2[0]='1';
        text2[1]='0';
        break;
        case 3:text2[0]='1';
        text2[1]='1';
        break;
    }
    switch(val2)
    {
        case 0:text2[2]='0';
        text2[3]='0';
        break;
        case 1:text2[2]='0';
        text2[3]='1';
        break;
        case 2:text2[2]='1';
        text2[3]='0';
        break;
        case 3:text2[2]='1';
        text2[3]='1';
        break;
    }
    for(i=0;i<4;i++)
    {
        text3[i]=text2[p4[i]-1];
    }
    free(text1);
    free(text2);
    return text3;
}
char *findfk(char *text,char *key)
{
    char *left_text,*right_text,*text1,*text2;
    int i;
    left_text=(char *)malloc(4*sizeof(char));
    right_text=(char *)malloc(4*sizeof(char));
    text1=(char *)malloc(4*sizeof(char));
    text2=(char *)malloc(4*sizeof(char));
    for(i=0;i<4;i++)
    {
        left_text[i]=text[i];
        right_text[i]=text[i+4];
    }
    text1=findf(right_text,key);
    for(i=0;i<4;i++)
    {
        if(left_text[i]==text1[i])
        {
            left_text[i]='0';
        }
        else
        {
            left_text[i]='1';
        }
    }
    for(i=0;i<4;i++)
    {
        text2[i]=left_text[i];
        text2[i+4]=right_text[i];
    }
    free(left_text);
    free(right_text);
    free(text1);
    return text2;
}
char *encryption(char *plain_text,char *key1,char*key2)
{
    char *text,*text1,*cipher_text;
    int i;
    text=(char *)malloc(8*sizeof(char));
    text1=(char *)malloc(8*sizeof(char));
    cipher_text=(char *)malloc(8*sizeof(char));
    for(i=0;i<8;i++)
    {
        text[i]=plain_text[ip[i]-1];
    }
    text1=findfk(text,key1);
    for(i=0;i<8;i++)
    {
        text[i]=text1[sw[i]-1];
    }
    text1=findfk(text,key2);
    for(i=0;i<8;i++)
    {
        cipher_text[i]=text1[ipinv[i]-1];
    }
    free(text);
    free(text1);
    return cipher_text;
}
char *decryption(char *cipher_text,char *key1,char *key2)
{
    char *text,*text1,*plain_text;
    int i;
    text=(char *)malloc(8*sizeof(char));
    text1=(char *)malloc(8*sizeof(char));
    plain_text=(char *)malloc(8*sizeof(char));
    for(i=0;i<8;i++)
    {
        text[i]=cipher_text[ip[i]-1];
    }
    text1=findfk(text,key2);
    for(i=0;i<8;i++)
    {
        text[i]=text1[sw[i]-1];
    }
    text1=findfk(text,key1);
    for(i=0;i<8;i++)
    {
        plain_text[i]=text1[ipinv[i]-1];
    }
    free(text);
    free(text1);
    return plain_text;
}
void print1(char *text,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%c",text[i]);
    }
    printf("\n");
}
int main()
{
    char *key,*key1,*key2,*plain_text,*cipher_text,*plain_text_1;
    key=(char *)malloc(10*sizeof(char));
    key1=(char *)malloc(8*sizeof(char));
    key2=(char *)malloc(8*sizeof(char));
    plain_text=(char *)malloc(8*sizeof(char));
    cipher_text=(char *)malloc(8*sizeof(char));
    plain_text_1=(char *)malloc(8*sizeof(char));
    printf("Enter 10 bit key: ");
    scanf("%s",key);
    key1=findkey(key,1);
    key2=findkey(key,2);
    printf("Enter 8 bit plain text: ");
    scanf("%s",plain_text);
    printf("Key 1 is: ");
    print1(key1,8);
    printf("Key 2 is: ");
    print1(key2,8);
    cipher_text=encryption(plain_text,key1,key2);
    printf("Cipher Text after encryption is: ");
    print1(cipher_text,8);
    plain_text_1=decryption(cipher_text,key1,key2);
    printf("Plain Text after decryption is: ");
    print1(plain_text_1,8);
    return 0;
}