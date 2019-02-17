/*
 * Programmer : Josh Booth      Date : Feb 15 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Program to calculate speed of mile runners in ft/s and m/s
 */

#include <stdio.h> /* Includes printf, scanf */
#define FEET_PER_MILE 5280.0 /* Number to feet in a mile */
#define FEET_PER_KM 3282.0 /* Number of feet in a kilometer */
#define SEC_PER_MIN 60.0 /* Conversion factor for minutes to seconds */
#define M_PER_KM 1000.0 /* Conversion factor for meters to kilometers */

/* Function prototypes */
float calc_ft_per_sec(float time); /* Finds feet per second */
float calc_m_per_sec(float time); /* Finds meters per seconds */

int
main(void)
{
  int mins, /* Minutes it took the runner to complete the race */
    secs; /* Seconds it took the runner to complete the race */
  float frac_time, /* Time to complete the race with fractional seconds 
   * (ex. 2.5 mins) */
    ft_per_sec, /* Feet per second */
    m_per_sec; /* Meters per seconds */
  
  printf("***** Track Stars *****\n");
  /* Gets minutes and seconds */
  printf("Enter time (minutes seconds): ");
  scanf("%d %d", &mins, &secs);

  /* Calculates time to a fractional minute from mins and secs */
  frac_time = (mins * SEC_PER_MIN) + secs;
  ft_per_sec = calc_ft_per_sec(frac_time); /* Finds feet per second */
  m_per_sec = calc_m_per_sec(frac_time); /* Finds meters per seconds */
  
  /* Displays feet/sec and m/sec */
  printf("%.2f feet/sec    %.2f meter/sec\n", ft_per_sec, m_per_sec);
  
  return (0);
}

/* Calculates feet per second */
float
calc_ft_per_sec(float time)
{
  /* V = d/t */
  return (FEET_PER_MILE / time);
}

/* Calculates meters per second */
float
calc_m_per_sec(float time)
{
  /* Converts feet to meters then divides by time (V = d/t) */
  return (((FEET_PER_MILE / FEET_PER_KM) * M_PER_KM) / time);
}