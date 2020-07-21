#include "stack.h"

/**
 * Creates a new stack structure.
 * 
 * @param member_size an integer representing the size of one member of the data type to be stored in the stack.
 * @param capacity an integer representing the maximum number of elements allowed in the stack, the stack's maximum capacity.
 * 
 * @return stack*
 */
stack* create_stack(int member_size, int capacity) {
    stack *s = malloc(sizeof(stack));
    s->top = -1;
    s->member_size = member_size;
    s->capacity = capacity;
    s->data = malloc(capacity*member_size);
    s->growth_factor = 2;
    s->count = 0;
    return s;
}

/**
 * Expands the capacity of the stack by multiplying it by the given growth factor
 * @param s a pointer to the stack
 * @param growth_factor an integer representing the growth factor of the stack
 * @return integer representing the occurence of an error, 0 = no error.
 */
int expand_stack(stack *s) {
    // double capacity of stack
    s->capacity *= s->growth_factor;
    s->data = realloc(s->data, s->capacity * s->member_size);
    return 0;
}

/**
 * Puts the element on top of the stack.
 * @param s a pointer to the stack structure.
 * @param element a void pointer to the element being pushed onto the stack.
 * @return integer representing the occurence of an error, 0 = no error.
 */
int stack_push(stack *s, void *element) {
    // check if stack is full
    if (s->top == s->capacity-1) {
        // if full expand the stack
        expand_stack(s);
    }
    s->top++;
    s->count++;

    /* calculate start index of next member by typecasting to char* 
       and then adding total bytes taken by members already in the stack. */
    void* target = (char*)s->data+(s->top * s->member_size);


    memcpy(target, element, s->member_size); // copy data into stack
    return 0;
}

// remove and return the top element from the stack
int stack_pop(stack *s, void *out) {
    if (s->top == -1) {
        return 1;
    }

    void* source = (char*)s->data+(s->top * s->member_size);
    s->top--;
    s->count--;
    memcpy(out, source, s->member_size);
    return 0;
}

// get top element in the stack without removing it
int stack_peek(stack *s, void *out) {
    if (s->top == -1) {
        return 1;
    }

    void* source = (char*)s->data+(s->top * s->member_size);
    memcpy(out, source, s->member_size);
    return 0;
}

// returns the length of the stack
int stack_count(stack *s) {
    return s->count;
}

// free all dynamically allocated memory
int stack_free(stack *s) {
    free(s->data);
    free(s);
    return 0;
}
