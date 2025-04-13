#ifndef STACK_C_
#define STACK_C_
#include <stdlib.h>

typedef struct stack_t{
    int * data;
    int top, cap;
} stack_t;

stack_t* stack_new(int cap) {
   stack_t *s = malloc(sizeof(stack_t));
    s->data = malloc(sizeof(int) * cap);
    s->top = 0; s->cap = cap;
   return s; 
}

void stack_push(stack_t *s, int val){
    if (s->top < s->cap) s->data[s->top++] = val;
}

int stack_pop(stack_t *s) {
    return s->top ? s->data[--s->top] : -1;
}

#endif // STACK_C_
