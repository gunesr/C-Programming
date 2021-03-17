#include <stdlib.h>
#include <stdio.h>

struct _retire_info {

  int months;

  double contribution;

  double rate_of_return;

};

typedef struct _retire_info retire_info;

void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired) //info about being retired
{

  int i, j;

  double balance;

  balance = initial;

  int age;

  int months;

  months = startAge%12;

  age = startAge/12;

  for ( i=0; i < working.months; i++) {

    printf ( "Age %3d month %2d you have $%.2f\n", age, months, balance );

    months++;

    balance = balance*working.rate_of_return + balance + working.contribution;

    if ( months > 11 ) {

      age++;

      months = 0;

    }

  }

  for ( j=0; j < retired.months; j++ ) {

    printf ( "Age %3d month %2d you have $%.2f\n", age, months, balance );

    months++;

    balance = balance*retired.rate_of_return + balance + retired.contribution;

    if ( months > 11 ) {

      age++;

      months = 0;

    }

  }

  return;

}

int main(void) {

  retire_info working;

  retire_info retired;
  
  int startAge = 327;

  double initial = 21345.00;

  working.months = 489;

  working.contribution = 1000;

  working.rate_of_return = .045/12;

  retired.months = 384;

  retired.contribution = -4000;

  retired.rate_of_return = .01/12;

  retirement ( startAge, initial, working, retired ) ;

  return EXIT_SUCCESS;
}
