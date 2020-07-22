#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct {
    void *data;  // void pointer can point to any kind of data
    int top; // the index of the top of the stack
    int count; // the current number of elements in the stack
    int capacity; // the maximum number of elements the stack can hold
    int member_size; // the size in number of bytes of one member of the type for which we are storing in the stack
    int growth_factor; // the growth factor for dynamically resizing the stack
} stack;

stack* create_stack(int member_size, int capacity);
int stack_push(stack *s, void *element);
int stack_pop(stack *s, void *out);
int stack_peek(stack *s, void *out);
int stack_count(stack *s);
void stack_free(stack *s);