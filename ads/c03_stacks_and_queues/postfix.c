#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef element T;

T stack[MAX_STACK_SIZE];
int top = -1;

char expr[] = {
    'a', '+', 'b', '*', 'c', ' '};

/* isp and icp arrays -- index is the value of precedence
   lparen, rparen, plus, minus, times, divide, mod, eos */
int isp[] = {
    0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {
    20, 19, 12, 12, 13, 13, 13, 0};

isFull(T s[])
{
  return top >= MAX_STACK_SIZE - 1;
}

void push(T s[], T item)
{
  if (isFull(s))
  {
    printf("Stack is full\n");
    exit(EXIT_FAILURE);
  }
  s[++top] = item;
}

T pop(T s[])
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    exit(EXIT_FAILURE);
  }

  return s[top--];
}

typedef enum
{
  lparen,
  rparen,
  plus,
  minus,
  times,
  divide,
  mod,
  eos,
  operand
} precedence;

precedence getToken(char *symbol, int *n)
{
  // get the next token
  *symbol = expr[(*n)++];
  switch (*symbol)
  {
  case '(':
    return lparen;
  case ')':
    return rparen;
  case '+':
    return plus;
  case '-':
    return minus;
  case '/':
    return divide;
  case '*':
    return times;
  case '%':
    return mod;
  case ' ':
    return eos;
  default:
    return operand; // no error checking
  }
}

void printToken(char c)
{
  char o = c;
  switch (o)
  {
  case plus:
    o = '+';
    break;
  case minus:
    o = '-';
    break;
  case times:
    o = '*';
    break;
  case divide:
    o = '/';
  case mod:
    o = '%';
  }

  printf("%c", o);
}

int eval()
{ // evaluate a postfix expression, expr
  precedence token;
  char symbol;
  int op1, op2;
  int n = 0; // count for expression string
  token = getToken(&symbol, &n);
  while (token != eos)
  {
    if (token == operand)
    { // if operand, push on the stack
      push(stack, symbol - '0');
    }
    else
    { // if operator or parenthesis
      /* pop two operands, perform operation
         and push result to the stack */
      op2 = pop(stack); // stack delete
      op1 = pop(stack);

      switch (token)
      {
      case plus:
        push(stack, op1 + op2);
        break;
      case minus:
        push(stack, op1 - op2);
        break;
      case times:
        push(stack, op1 * op2);
        break;
      case divide:
        push(stack, op1 / op2);
        break;
      case mod:
        push(stack, op1 % op2);
      }
    } // if operator or parenthesis
    token = getToken(&symbol, &n);
  }
  return pop(stack); // return result
}

void postfix()
{ // ouotput the postfix of the expression
  char symbol;
  precedence token;
  int n = 0;
  stack[0] = eos;
  for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
  {
    if (token == operand)
    { // if token is an operand - print
      printf("%c", symbol);
    }
    else if (token == rparen)
    { // if token is ')'
      while (stack[top] != lparen)
      { // unstack tokens until left parenthesis
        printToken(pop(stack));
      }
      pop(stack); // discard the left parenthesis
    }             // if token is ')'
    else
    { // if token is an operator
      /* remove and print symbols whose isp is greator
         than or equal to the current token's icp */
      while (isp[stack[top]] >= icp[token])
      {
        printToken(pop(stack));
      }
      push(stack, token);
    }
  }
  while ((token = pop(stack)) != eos)
  {
    printToken(token);
  }
  printf("\n");
}

int main(void)
{
  postfix(expr);

  return 0;
}