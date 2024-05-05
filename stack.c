#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 overflow\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 underflow\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; ++t) {
        StackType stack;
        init_stack(&stack);

        int N;
        scanf("%d", &N);

        StackType min_stack, max_stack;
        init_stack(&min_stack);
        init_stack(&max_stack);

        for (int i = 0; i < N; ++i) {
            int query, block;
            scanf("%d", &query);

            if (query == 1) {
                scanf("%d", &block);
                push(&stack, block);

                if (is_empty(&min_stack) || block <= min_stack.data[min_stack.top])
                    push(&min_stack, block);
                if (is_empty(&max_stack) || block >= max_stack.data[max_stack.top])
                    push(&max_stack, block);

                printf("%d %d\n", min_stack.data[min_stack.top], max_stack.data[max_stack.top]);
            }
            else if (query == 2) {
                if (!is_empty(&stack)) {
                    block = pop(&stack);
                    if (block == min_stack.data[min_stack.top]) pop(&min_stack);
                    if (block == max_stack.data[max_stack.top]) pop(&max_stack);
                }
            }
        }
    }

    return 0;
}
