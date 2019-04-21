#include <stdio.h>
#define MAX_TERMS 100

// terms array
typedef struct
{
  float coef;
  int expon;
} Polynomial;
int avail = 0; // term available, increases when a term is attached

Polynomial terms[MAX_TERMS];

void attach(float coefficient, int exponent)
{
  // add a new term to the polynomial
  if (avail >= MAX_TERMS)
  {
    fprintf(stderr, "Too many terms in the polynomia\n");
    exit(-1);
  }
  terms[avail].coef = coefficient;
  terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
  // add A(x) and B(x) to obtain D(x)
  float coefficient;
  *startD = avail;
  while (startA <= finishA && startB <= finishB)
  {
    // compare terms of a and b
    switch (compare(terms[startA].expon, terms[startB].expon))
    {
    case -1: // a expon < b expon
      attach(terms[startB].coef, terms[startB].expon);
      startB++;
      break;
    case 0: // equal expons
      coefficient = terms[startA].coef + terms[startB].coef;
      if (coefficient)
      {
        attach(coefficient, terms[startA].expon);
      }
      startA++;
      startB++;
      break;
    case 1: // a expon > b expon
      attach(terms[startA].coef, terms[startA].expon);
      startA++;
    }
  }

  // add remaining terms of A(x) and B(x)
  for (; startA <= finishA; startA++)
  {
    attach(terms[startA].coef, terms[startA].expon);
  }
  for (; startB <= finishB; startB++)
  {
    attach(terms[startB].coef, terms[startB].expon);
  }
  *finishD = avail - 1;
}