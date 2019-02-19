/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Program to calculate monthly car payment and how much is needed to 
 * be borrowed
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */
#define YEARS_TO_MONTHS (1/12.0) /* Conversion factor for years to months */
#define PERCENT_TO_DECIMAL (1/100.0) /* Conversion factor for percent to 
 * decimal */

/* Function prototype for calculating the monthly payment */
double calc_monthly_payment(int amt_borrowed, double monthly_interest_rate,
  int number_of_payments);

int
main(void)
{
 int
  purchase_price, /* Price of purchase */
  number_of_payments, /* Number of payments needed to pay off the car */
  down_payment; /* Amount of prinicpal */
 double
  annual_interest_rate, /* Interest rate per year */
  monthly_interest_rate, /* Interest rate per month (1/12 of annual) */
  amt_borrowed, /* Amount needed on top of principal */
  monthly_payment; /* Payment needed per month */

 /* Gets the price of the purchase */
 printf("Enter purchase price: ");
 scanf("%d", &purchase_price);
 /* Gets down payment */
 printf("Enter down payment: ");
 scanf("%d", &down_payment);
 /* Gets the annual interest rate */
 printf("Enter annual interest rate (e.g. 5.5): ");
 scanf("%lf", &annual_interest_rate);
 /* Gets the number of months a payment must be made */
 printf("Enter number of month: ");
 scanf("%d", &number_of_payments);

 /* Converts annual interest rate percent to monthly decimal */
 monthly_interest_rate = annual_interest_rate * YEARS_TO_MONTHS 
 * PERCENT_TO_DECIMAL;
 /* How much money needed to be borrowed */
 amt_borrowed = purchase_price - down_payment;
 /* Calculates monthly payment */
 monthly_payment = calc_monthly_payment(amt_borrowed, monthly_interest_rate,
  number_of_payments);

 /* Displays the amount borrowed and monthly payment */
 printf("The amount you borrow will be $%.2f\n", amt_borrowed);
 printf("Your payment will be $%.2f\n", monthly_payment);

 return (0);
}


/* Calculates monthly payment */
double
calc_monthly_payment(int amt_borrowed, double monthly_interest_rate,
  int number_of_payments)
{
  double numerator,
    denominator;
  /* Uses formula iP/(1-(1 + i)^-n) where P = amount borrowed,
   * i = monthly interest rate, and n = total number of payments to calculate
   * monthly payment */
  numerator = monthly_interest_rate * amt_borrowed;
  denominator = ( 1 - pow( 1 + monthly_interest_rate, -1 * number_of_payments));

  /* Returns the finished calculation */
  return(numerator / denominator);
}