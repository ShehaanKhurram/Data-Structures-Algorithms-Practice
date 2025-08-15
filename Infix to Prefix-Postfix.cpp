#include <iostream>
using namespace std;

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void reverse(char* expr) {
    int length = 0;
    while (expr[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[length - 1 - i];
        expr[length - 1 - i] = temp;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[50];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isOperand(current)) {
            postfix[j++] = current;
        }
        else if (current == '(') {
            stack[++top] = current;
        }
        else if (current == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = current;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[50];
    infixToPostfix(infix, postfix);

    reverse(postfix);

    int i = 0;
    while (postfix[i] != '\0') {
        prefix[i] = postfix[i];
        i++;
    }
    prefix[i] = '\0';  
}

int main() {
    char infix[50], prefix[50];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPrefix(infix, prefix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
