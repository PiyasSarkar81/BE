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
        case '{':
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

long int eval_post()
{
    long int a,b,temp,result;
    unsigned int i;
    for(i =0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
        push(postfix[i] - '0');
        else{
            b=pop();
            a=pop();
            switch (postfix[i])
            {
            case '+':
                temp = a+b;
                break;
            case '-':
                temp = a-b;
                break;
            case '*':
                temp = a*b;
                break;
            case '/':
                temp = a/b;
                break;
            case '%':
                temp = a%b;
                break;
            case '^':
                temp = pow(a,b);
                break;
            }
            push(temp);
        }
    }
    result = pop();
    return result;
}

int main(){
    top = -1;
    long int value;
    printf("Enter postfix : ");
    scanf("%s",&postfix);
    value = eval_post();
    printf("Value of expression : %ld\n",value);

    return 0;
}
