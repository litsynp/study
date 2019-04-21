#define MAX_DEGREE 100

// coefficient array
typedef struct
{
  int degree;
  int coef[MAX_DEGREE];
} Polynomial;

Polynomial polyA;
Polynomial polyB;
Polynomial polyD;

Polynomial zero()
{
  // return an empty polynomial
  Polynomial poly;
  int i;

  poly.degree = 0;
  for (i = 0; i < MAX_DEGREE; i++)
  {
    poly.coef[i] = 0;
  }
  return poly;
}

int isZero(Polynomial poly)
{
  return poly.degree == 0;
}

int leadExp(Polynomial poly)
{
  // return the leading exponent of poly
  int degree;
  for (degree = MAX_DEGREE - 1; degree >= 0; degree--)
  {
    if (poly.coef[degree] != 0)
    {
      return degree;
    }
  }
}

Polynomial *remove(Polynomial *poly, int expon)
{
  // return poly with the term whose expon is deleted
  poly->coef[expon] = 0;
  return poly;
}

Polynomial *attach(Polynomial *poly, int coef, int expon)
{
  // return poly with the term <coef, expon> inserted
  poly->coef[expon] = coef;
  return poly;
}

int padd(Polynomial *a, Polynomial *b)
{
  // d = a + b
  Polynomial d = zero();
  int leadExpA, leadExpB;
  int sum;

  // a와 b 둘 중 하나가 0이 될 때까지
  while (!(isZero(*a) && isZero(*b)))
  {
    leadExpA = leadExp(*a);
    leadExpB = leadExp(*b);
    // a와 b leadExp 비교
    switch (compare(leadExpA, leadExpB))
    {
    case -1: // a expon < b expon
      attach(&d, b->coef[leadExpB], leadExpB);
      b = remove(&b, leadExpB);
      break;
    case 0: // equal expons
      sum = a->coef[leadExpA] + b->coef[leadExpB];
      if (sum)
      {
        attach(&d, sum, leadExpA);
        a = remove(&a, leadExpA);
        b = remove(&b, leadExpB);
      }
      break;
    case 1: // a expon > b expon
      attach(&d, a->coef[leadExpA], leadExpA);
      a = remove(&a, leadExpA);
    }
  }

  // insert any remaining terms in a or b into d
}