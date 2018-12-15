#include <stdio.h>
#include <malloc.h>

#include "stack.h"

Stack* stack_init(int len)
{
  Stack* stack = malloc(sizeof(Stack));
  stack->cur = 0;
  stack->max = len;
  stack->data = calloc(len, sizeof(unit));
  return stack;
}

void stack_put(Stack* stack, unit arg)
{
  if (!stack_is_full(stack))
  {
    //printf("Putting %d\n", arg);
    stack->data[stack->cur] = arg;
    stack->cur = stack->cur+1;
  }
  else
  {
    printf("Stack reached Max Len!");
  }
}

unit stack_get(Stack* stack)
{
  unit ret = 0;
  if (!stack_is_empty(stack))
  { 
    stack->cur = stack->cur-1; 
    ret = stack->data[stack->cur];
    //printf("Gettting %d\n", ret);
  }
  else
  {
    printf("Stack is empty!");
  }
  return ret; 
}

int stack_is_empty(Stack* stack)
{
  return stack->cur <=0 ;
}

int stack_is_full(Stack* stack)
{
  return stack->cur >= stack->max;
}

int stack_size(Stack* stack)
{
  return stack->cur;
}
