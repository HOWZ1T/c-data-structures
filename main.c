#include <stdio.h>
#include "collections/stack.h"

int main(int argc, char* argv[]) {
    stack *s = create_stack(sizeof(int), 1);
    for(int i = 1; i <= 10; i++) {
        stack_push(s, (void *)&i);
    }

    void *ptr = malloc(sizeof(int));
    int count = s->count;
    for(int i = 0; i < count; i++) {
        stack_pop(s, ptr);
        printf("%d: %d\n", i, *(int *)ptr);
    }

    free(ptr);
    stack_free(s);
    return 0;
}