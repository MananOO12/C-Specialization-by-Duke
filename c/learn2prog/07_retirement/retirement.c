#include<stdio.h>
#include<stdlib.h>

#define EXIT_SUCCESS 0

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double new_bal(double bal,retire_info r)
{
  return(bal*(1+r.rate_of_return)+r.contribution);
}

void cal(int ms,int *y,int *m)
{
  *y=ms/12;
  *m=ms%12;
}

void print(int ms,double bal)
{
  int age,m;
  cal(ms,&age,&m);
  printf("Age %3d month %2d you have $%.2lf\n",age,m,bal);
}

void retirement(int startAge,double initial,retire_info working,retire_info retired)
{
  int i,age=startAge;
  double bal=initial;
  for(i=0;i<working.months;++i)
    {
      print(age,bal);
      age++;
      bal=new_bal(bal,working);
    }
  for(i=0;i<retired.months;++i)
    {
      print(age,bal);
      age++;
      bal=new_bal(bal,retired);
    }
}

int main()
{
  retire_info working={489,1000.0,0.045/12};
  retire_info retired={384,-4000.0,0.01/12};
  int age =327;
  double savings=21345;
  retirement(age,savings,working,retired);
  return EXIT_SUCCESS;
}
