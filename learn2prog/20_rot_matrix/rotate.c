#include<stdio.h>

void rotate(char a[10][10])
{
  char temp;
  for(int i=0;i<10;++i)
    {
      for(int j=i;j<10;++j)
	{
	  temp=a[i][j];
	  a[i][j]=a[j][i];
	  a[j][i]=temp;
	}
    }

  for(int i=0;i<10;++i)
    {
      for(int j=0;j<5;++j)
	{
	  temp=a[i][j];
	  a[i][j]=a[i][9-j];
	  a[i][9-j]=temp;
	}
    }
}
