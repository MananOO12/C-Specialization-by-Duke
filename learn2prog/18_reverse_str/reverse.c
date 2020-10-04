#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str) {
  //WRITE ME!
  //  char check[]=*str;
  //printf(
  //strrev(str);
  if(str==NULL)
   return ;
  size_t i;
  size_t n=strlen(str);
  char temp;
  //t=str;temp=str;
  //  for(i=0;i<n;++i)
    // temp++;
  i=0;
    while(i<n/2)
    {
      /* ch=*temp;
      *temp=*t;
      *t=ch;
      t++;
      temp--;*/
      temp=str[i];
      str[i]=str[n-1-i];
      str[n-i-1]=temp;
      ++i;
    }
    return;
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char *array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
