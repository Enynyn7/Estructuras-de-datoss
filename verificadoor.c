/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX 1000

int is_open(char c) {
    return c == '(' || c == '[' || c == '{';
}

int is_close(char c) {
    return c == ')' || c == ']' || c == '}';
}

int matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int check_brackets(const char *expr) {
    char stack[MAX];
    int index_stack[MAX];
    int top = -1;

    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (is_open(c)) {
            stack[++top] = c;
            index_stack[top] = i;
        } else if (is_close(c)) {
            if (top == -1) {
                return i; // error: cierre sin apertura
            }
            if (!matches(stack[top], c)) {
                return i; // error: par no coincide
            }
            top--; // correcto, se empareja
        }
    }

    if (top != -1) {
        return index_stack[0]; // error: apertura sin cierre
    }

    return -1; // OK
}

int main() {
    const char *tests[] = {
        "([]{})",
        "([)]",
        "abc(def[ghi]{j}k",
        NULL
    };

    for (int i = 0; tests[i]; i++) {
        int result = check_brackets(tests[i]);
        if (result == -1)
            printf("%s → OK\n", tests[i]);
        else
            printf("%s → ERROR %d\n", tests[i], result);
    }

    return 0;
}

   
