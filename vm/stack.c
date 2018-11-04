#include "stack.h"

STACK stack_create(uint16_t num_objects)
{
  STACK stack;
  stack.objects = (OBJECT *)malloc(sizeof(OBJECT) * num_objects);
  stack.max_size = num_objects;
  stack.size = 0;

  return stack;
}

void stack_free(STACK stack)
{
  if (stack.objects != NULL)
  {
    free(stack.objects);
  }
}

OBJECT stack_top(STACK *stack)
{
  return stack->objects[stack->size];
}

OBJECT stack_pop(STACK *stack)
{
  return stack->objects[stack->size--];
}

void stack_push(STACK *stack, OBJECT object)
{
  stack->objects[stack->size++] = object;
}