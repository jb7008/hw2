/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 * Calculates the ratio between speeds in a six speed gearbox based on rpm ratio
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

/* Calculates ratio between successive speeds of a six-speed gearbox */
double speeds_ratio(double max_speed, double min_speed); 

int
main(void)
{
  double min_speed, /* Minimum speed */
    max_speed, /* Maximum speed */
    speed_ratio; /* Ratio between the speeds based on rpm */

  printf("**** Ratio of six-speed gearbox ****\n");
  /* Gets min speed */
  printf("Enter minimum speed: ");
  scanf("%lf", &min_speed);
  /* Gets max speed */
  printf("Enter maximum speed: ");
  scanf("%lf", &max_speed);

  /* Calculates the speed ratio based on max and min speed */
  speed_ratio = speeds_ratio(max_speed, min_speed);

  /* Displays results */
  printf("The ratio between successive speeds of a six-speed gearbox with "
    "maximum speed %.1f rpm and minimum speed %.1f rpm is %.6f\n",
    min_speed, max_speed, speed_ratio);
  
  return (0);
}

/* Calculates ratio between successive speeds of a six-speed gearbox */
double
speeds_ratio(double max_speed, double min_speed)
{
  /* Calculates ratio based on formula fifthroot(M/m) */
  return(pow(max_speed / min_speed, 1/5.0));
}