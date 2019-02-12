#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */
#define YEARS_TO_MONTHS (1/12) /* Conversion factor for years to months */

int
main(void){
 int
  purchase_price, /* Price of purchase */
  number_of_payments, /* Number of payments needed to pay off the car */
  down_payment; /* Amount of prinicpal */
 float
  annual_interest_rate, /* Interest rate per year */
  monthly_interest_rate, /* Interest rate per month (1/12 of annual) */
  amt_borrowed;/* Amount needed on top of principal*/
long double
  monthly_payment; /* Payment needed per month */

 /* Gets the price of the purchase */
 printf("Enter purchase price: ");
 scanf("%d", &purchase_price);
 /* Gets down payment */
 printf("Enter down payment: ");
 scanf("%d", &down_payment);
 /* Gets the annual interest rate */
 printf("Enter annual interest rate (e.g. 5.5): ");
 scanf("%f", &annual_interest_rate);
 /* Gets the number of months a payment must be made */
 printf("Enter number of month: ");
 scanf("%d", &number_of_payments);

 /* Converts annual interest rate to monthly */
 monthly_interest_rate = annual_interest_rate * YEARS_TO_MONTHS;
 /* How much money needed to be borrowed */
 amt_borrowed = purchase_price - down_payment;
 /* Calculates what payment is needed per month using the formula
  * (iP)/(1-(1-i)^-n) where P = prinicpal, i = monthly interest rate,
  * and m = total number of payments */
printf("%f", (1 - pow(1 + monthly_interest_rate, -1 * number_of_payments)));
 monthly_payment = (monthly_interest_rate * amt_borrowed) /
  (1 - pow(1 + monthly_interest_rate, -1 * number_of_payments));

 /* Displays the amount borrowed and monthly payment */
 printf("The amount you borrow will be $%.2f", amt_borrowed);
 printf("Your payment will be $%.2f", monthly_payment);

 return (0);
}
