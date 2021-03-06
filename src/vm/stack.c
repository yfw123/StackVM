#include "stack.h"
#include <malloc.h>
#include <stdio.h>

STACK stack_create(uint16_t num_objects)
{
    STACK stack;
    stack.objects  = (OBJECT*)malloc(sizeof(OBJECT) * num_objects);
    stack.max_size = num_objects;
    stack.size     = 0;

    return stack;
}

void stack_free(STACK stack)
{
    if (stack.objects != NULL) {
        free(stack.objects);
    }
}

void stack_reset(STACK* stack)
{
    stack->size = 0;
}

OBJECT stack_top(STACK* stack)
{
    return stack->objects[stack->size];
}

OBJECT stack_pop(STACK* stack)
{
    return stack->objects[--stack->size];
}

OBJECT stack_at(STACK* stack, INTEGER position)
{
    return stack->objects[position];
}

void stack_push(STACK* stack, OBJECT object)
{
    stack->objects[stack->size++] = object;
}

INTEGER stack_size(STACK* stack)
{
    return stack->size;
}