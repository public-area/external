#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
 
  char arr[5][5];
  char pt[10];
  char key[10],pt1,pt2;
 
  int i, j, r1=0, r2=0, c1=0, c2=0,index=0,a[26]={0},k=0,flag=0;
  printf("Enter Key: ");
  scanf("%s",&key);
  for(k=0;k<strlen(key);k++)
  {
   a[key[k]-'A']++;
  }
  k=0;
  for(i=0;i<5;i++)
  {
      for(j=0;j<5;j++)
      {
          arr[i][j]=key[k];
          k++;
          if(k-1==strlen(key))
          {
              break;
          }
      }
      if(k-1==strlen(key))
      {
          break;
      }
  }
  k=0;
  for(r1=j;r1<5;r1++)
  {
      while(a[k]!=0)
      {
          k++;
      }
      if(a[k]==0)
      {
          arr[i][r1]=k+'A';
      }
      k++;
  }
  for(r1=i+1;r1<5;r1++)
  {
      for(r2=0;r2<5;r2++)
      {
          while(a[k]!=0)
          {
              k++;
          }
          if(a[k]==0)
        {
            arr[r1][r2]=k+'A';
        }
        k++;
      }
  }
  printf("Playfair Keymatrix\n==================\n");
  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    printf("%c ", arr[i][j]);
    printf("\n");
  }
 
  printf("Enter your plain text:");
  scanf("%s",pt);
  printf("Your plain text = %s\n", pt);
 while(index<strlen(pt))
 {
     flag=0;
     if(pt[index]==pt[index+1])
     {
         pt1=pt[index];
         pt2='X';
         flag=1;
     }
     else
     {
         pt1=pt[index];
         pt2=pt[index+1];
         if(index+1==strlen(pt))
         {
             pt2='X';
         }
     }
  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    {
       if(arr[i][j] == pt1)
       {
         r1=i; c1=j;
       }
       if(arr[i][j] == pt2)
       {
         r2=i; c2=j;
       }
    }
  }
  if(r1==r2) //when both characters in same row
  {
    if(c2==4) //for char in last column
       printf("Ciphertext = %c%c\n", arr[r1][c1+1], arr[r2][0]);  
    else
       printf("Ciphertext = %c%c\n", arr[r1][c1+1], arr[r2][c2+1]); 
  }
  else if(c1==c2)//when both characters in same column
  {
    if(r2==4) //for char in last row
       printf("Ciphertext = %c%c\n", arr[r1+1][c1], arr[0][c2]); 
    else
       printf("Ciphertext = %c%c\n", arr[r1+1][c1], arr[r2+1][c2]); 
  }
  //when characters are not in a same row and column
  else if(r1 != r2 && c1 != c2) 
  {
    printf("Ciphertext = %c%c\n", arr[r1][c2], arr[r2][c1]); 
  }
  if(flag==1)
  {
      index=index+1;
  }
  else
  {
      index=index+2;
  }
 }
  return 0;
}