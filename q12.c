/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 * Calculates the speed of sound in the air given the temperature
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

/* Calculates the speed of sound in ft/sec */
double calc_speed(double temp);

int
main(void)
{
  double temp, /* Temperature (F) */
    speed_of_sound; /* Speed of sound (ft/sec) */

  /* Gets temperature */
  printf("Enter temp (F): ");
  scanf("%lf", &temp);

  /* Calculates the speed of sound based on temperature */
  speed_of_sound = calc_speed(temp);

  /* Displays results */
  printf("Speed of sound @ T=%.2f is %.6f ft/s\n", temp, speed_of_sound);
  return (0);
}


/* Calculates the speed of sound in ft/sec */
double
calc_speed(double temp)
{
  double radicand; /* Holds radicand of speed formula */

  /* Finds radicand for speed formula a = 1086*sqrt((5T + 297)/247) */
  radicand = ((5 * temp) + 297) / 247;

  /* Calculates and returns rest of speed forumla */
  return (1086 * sqrt(radicand));
}