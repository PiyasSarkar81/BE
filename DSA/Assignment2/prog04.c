#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
struct node * top = NULL;

int isEmpty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Stack Overflow\n");
        return;
    }
    tmp -> info = item;
    tmp -> link = top;
    top = tmp;
}

int pop()
{
    struct node* tmp;
    int item;
    if(isEmpty()){
        printf("Stack Underflow.\n");
        exit(1);
    }
    tmp = top;
    item = tmp -> info;
    top = top -> link;
    free(tmp);
    return item;
}

int peek ()
{
    if(isEmpty()){
        printf("Stack Underflow.\n");
        exit(1);
    }
    return top->info;
}

void display()
{
    struct node *ptr;
    ptr = top;
    if(isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack Elements:\n");
    while (ptr != NULL)
    {
        printf(" %d\n",ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(){
    int choice, item;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display item at the top\n");
        printf("4.Display all item of the stack\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("Enter the item to be pushed.\n");
        scanf("%d",&item);
        push(item);
            break;
        case 2:
        item = pop();
        printf("popped item is: %d\n",item);
            break;
        case 3:
        printf("Item at the top is : %d",peek());
            break;
            case 4:
            display();
            break;
            case 5:
            exit(1);
            break;
        
        default:
        printf("Wrong Choice.\n");
            break;
        }
    }
    return 0;
}