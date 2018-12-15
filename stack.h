typedef int unit;

struct Stack
{
  int cur;
  int max;
  unit* data;
};

typedef struct Stack Stack;


Stack* stack_init(int len);
void stack_put(Stack* stack, unit arg);
unit stack_get(Stack* stack);
int stack_is_empty(Stack* stack);
int stack_is_full(Stack* stack);
int stack_size(Stack* stack);
