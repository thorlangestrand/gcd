/**
 * @file main.c
 * @author Thor B. Langestrand
 * @brief
 * Small program to calculate the greatest common denominator
 * between two numbers using the Euclidean Algorithm
 *
 * @copyright GPL 3.0
 * https://www.gnu.org/licenses/gpl-3.0.html
 *
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
  // If both 0, error
  if (a == 0 && b == 0) { return -1; }
  // Using definition for division of 0
  if (b == 0) { return a; }
  if (a == 0) { return b; }

  // If equal gcd is same
  if (a == b) { return a; }

  int large = 0;
  int small = 0;
  
  // Set values based on which is larger
  if (b > a) { large = b; small = a; }
  else { large = a; small = b; }

  // Get quotient and remainder 
  int quotient = large / small;
  int remainder = large - small * quotient;

  // Recurse until remainder is 0
  if (remainder != 0) { return gcd(small, remainder); }
  // If remainder is 0 means common denominator is small
  else { return small; }
}

int main(int argc, char const* argv[])
{
  if (argc != 3) { printf_s("Usage: gcd [num1] [num2]"); return 1; }
  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);
  printf_s("%i\n", gcd(num1, num2));
  return 0;
}
