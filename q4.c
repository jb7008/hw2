/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Program to calculate n factorial
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

double find_factorial(int n); /* Finds the factorial of n */

int
main(void)
{
  int n; /* Holds the integer of the factorial */
  double factorial; /* Holds calculated factorial */
  
  printf("****** Approximate N! *******\n");
  /* Gets n in the factorial n! */
  printf("Enter n: ");
  scanf("%d", &n);
  
  /* Finds factorial with formula: n^n * e^-n * sqrt(pi * 2n + 1/3) */
  factorial = find_factorial(n);
  
  /* Displays factorial */
  printf("%d! equals approximately %.6f\n", n, factorial);

  return (0);
}

/* Finds the factorial of n */
double
find_factorial(int n)
{
  double factorial; /* Factorial of n */
  
  /* Finds factorial with formula: n^n * e^-n * sqrt(pi * 2n + 1/3) */
  factorial = pow(n, n) * pow(M_E, -1 * n) * sqrt(M_PI * ((2 * n) + (1.0 / 3)));

  return(factorial);
}