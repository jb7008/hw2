/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 * Program to calculate how quickly the flu spreads through a college campus
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

int get_day(void); /* Gets number of days since initial report */
int num_of_cases(int day); /* Calculates the number of cases based 
 * on the number of days since initial report */

int
main(void)
{
 int day1, /* Days since patient zero was reported */ 
  day2,
  day3,
  day1_cases, /* Number of cases predicted */
  day2_cases,
  day3_cases;
  printf("FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED "
    "DAYS SINCE FIRST CASE REPORT\n");

  /* Gets day */
  day1 = get_day();
  /* Calculates the number of cases */
  day1_cases = num_of_cases(day1);
  
  /* Displays results */
  printf("By day %d, model predicts %d cases total.\n", day1, day1_cases);

  day2 = get_day();
  day2_cases = num_of_cases(day2);
  printf("By day %d, model predicts %d cases total.\n", day2, day2_cases);

  day3 = get_day();
  day3_cases = num_of_cases(day3);
  printf("By day %d, model predicts %d cases total.\n", day3, day3_cases);
  
  return (0);
}

/* Gets number of days since initial report */
int
get_day(void)
{
  int day; /* Number of days since first case */

  /* Gets day */
  printf("Enter day number>> ");
  scanf("%d", &day);

  return day;
}

/* Calculates the number of cases based on the number of days 
 * since initial report */
int
num_of_cases(int day)
{
  int cases; /* Holds the number of reported cases */

  /* Calculates the number of cases using the formula 
   * 40000/(1 + 39999(e^-0.24681)) */
  cases = (int)(40000 / (1.0 + (39999.0 * pow(M_E, -1 * 0.24681 * day))));

  return (cases);
}
