#include "../include/stack.h"

void throw_stack_overflow_error() { throw_error("Stack size exceed limit"); };
void throw_empty_stack_error() { throw_error("Could not retrieve data, Stack is empty"); };

 
struct Stack* create_stack(int size) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
 
    stack->maxsize = size;
    stack->top = -1;
    stack->items = (int*)malloc(sizeof(int) * size);

    return stack;
}

int is_stack_empty(struct Stack *stack) {
    return stack->top == -1;
}
 
int is_stack_full(struct Stack *stack) {
    return stack->top == stack->maxsize - 1;
}

void push_stack(struct Stack *stack, int op) {
    if (is_stack_full(stack)) {
      throw_stack_overflow_error();
    }
 
    stack->items[++stack->top] = op;
}
 
int peek(struct Stack *stack) {
    if (!is_stack_empty(stack)) {
        return stack->items[stack->top];
    }
    else {
        throw_empty_stack_error();
    }
}
 
int pop(struct Stack *stack) {
    if (is_stack_empty(stack))     {
        throw_empty_stack_error();
    }
 
    return stack->items[stack->top--];
}
 