#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array,size_t n)
{
  size_t l=1;
  size_t max = 0;
  if(n==0)
    return 0;

  for(size_t i=1;i<n;++i)
    {
      if(array[i]>array[i-1])
	{	 l+=1;}
	 else
	   {
	     if(l>max)
	       { max=l;}
	     l=1;
	   }
	 }
  if(l>max)
    max=l;
  return max;
}
