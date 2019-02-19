/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Program to round a program to two decimal places
 */

#include <stdio.h> /* Includes prinf, scanf */
#define ROUND_DECIDER (0.5) /* Will push number a hundredth higher to simulate 
 * rounding up on truncation */

/* Function prototype for rounding function */
double round(double to_round);

int
main(void)
{
  double to_round, /* Number to round to two decimal places */
    rounded; /* to_round rounded to two decimal places */

  printf("***** Round to two decimal places *****\n");
  /* Gets the number to round */
  printf("Enter the number: ");
  scanf("%lf", &to_round);
  
  /* Rounds to_round to 2 decimal places */
  rounded = round(to_round);
  
  /* Displays results */
  printf("Rounded %.6f\n", rounded);

  return (0);
}

/* Rounds to_round to 2 decimal places */
double
round(double to_round)
{
  double rounded_int, /* intermediate step holding the rounded number * 100 */
  rounded; /* to_round rounded to two decimal places */

  /* Multiplies the number to move it 2 decimal places to the right, uses the 
   * round decider and truncates the rest */
  rounded_int = (int)((to_round * 100) + ROUND_DECIDER);

  /* Removes the multiplication applied in the previous step */
  rounded = rounded_int / 100;

  return(rounded);
}