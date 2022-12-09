#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;


int white_space(char symbol)
{
    if(symbol==BLANK || symbol == TAB) return 1;
    else return 0;
}

int priority(char symbol)
{
    switch(symbol)
    {
        case '(':
        return 0;
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

int isEmpty()
{
    if(top == -1 ) return 1;
    else return 0;
}

void push(long int symbol)
{
    if(top>MAX)
    {
        printf("Stack Overflow.\n");
        exit(1);
    }
    stack[++top] = symbol;
}

long int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

void infix_to_postfix()
{
    int i,p=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        if(!white_space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop())!= '(')
                postfix[p++] =next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isEmpty() && priority(stack[top])>= priority(symbol))
                postfix[p++] = pop();
                push(symbol);
                break;
            default:
                postfix[p++] = symbol;
                return ;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

int main(){
    top = -1;
    printf("Enter the infix : ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix : %s\n",postfix);

    return 0;
}
