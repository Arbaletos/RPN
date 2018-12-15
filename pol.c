#include <stdio.h>
#include <string.h>

#include "stack.h"

#define MAXNUM 100
#define DEL ' '
#define NONE -1

int check_op(Stack* stack, char op, char true_op, int argc)
{
  if (op==true_op)
  {
    if (stack_size(stack)>=argc) return 1;
    printf("Parsing error: Not enough arguments in stack!\n");
  }
  return 0;
}


int main(int argc, char* args[])
{
  char* in_str;
  int i;
  int acc = 0;
  int empty = 1;
  if (argc>=2)
  {
    in_str = args[1];
  }
  else
  {
     printf("[USAGE]:\n\t./pol \"equation\"\n");
     printf("\tUse space as a delimeter, digits as operands, +,-,* as operators.\n");
     return 0;
  }

  Stack* stack = stack_init(strlen(in_str));
  
  for (i=0; i<strlen(in_str); i++)
  {
    char c = in_str[i];
    if ((c>='0') && (c<='9'))
    {
      if (empty){
        empty = 0;
        acc = c - '0';
      }
      else{
        acc = acc * 10 + c - '0';
      }
    }
    if (c==DEL){
      if(!empty){
        if (stack_is_full(stack))
        {
          printf("Something went wrong, Maximum stack capacity reached\n");
          return 0;
        } 
        stack_put(stack, acc);
        acc = 0;
        empty = 1;
        
      }
    }
    if (check_op(stack, c, '+', 2))
      stack_put(stack, stack_get(stack)+stack_get(stack));
    if (check_op(stack, c, '*', 2))
      stack_put(stack, stack_get(stack)*stack_get(stack));
    if (check_op(stack, c, '-', 2))
    {
      int a = stack_get(stack);
      int b = stack_get(stack);
      stack_put(stack, b - a);
    }
  }
  if (!empty)
  {
    printf("RPN can not end by a number, cupo.\n");
    return 0;
  }
  if (!stack_is_empty(stack)){
    printf("Result of Equation \"%s\" is %d\n", in_str, stack_get(stack));
    return 0;
  }

  printf("Something went Wrong, no values left.\n");
  return 0;
}
