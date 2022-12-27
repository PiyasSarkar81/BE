#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* lChild;
    struct node* rChild;
};

struct node* root = NULL;

struct node* search(int data)
{
    struct node *current = root;
    while(data != current -> data){
        if(current != NULL)
        {
            if(current -> data > data)
            current = current -> lChild;
            else
            current = current -> rChild; 
        }
        if(current == NULL)
        return NULL;
    }
    return current;
}

void insert(int data)
{
    struct node* tempNode = (struct node*)malloc(sizeof(struct node));
    struct node* current;
    struct node* parrent;
    tempNode -> data = data;
    tempNode -> lChild = NULL;
    tempNode -> rChild = NULL;
    if(root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parrent = NULL;
        while(1)
        {
            parrent = current;
            if(data < parrent -> data)
            {
                current = current -> lChild;
            if(current == NULL)
            {
                parrent->lChild = tempNode;
                return;
            }
            }
            else{
                current = current -> rChild;
                if(current == NULL)
                {
                    parrent -> rChild = tempNode;
                    return;
                } 
            }

        }
    }
}

void preOrderTraversal(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root-> data);
        preOrderTraversal(root->lChild);
        preOrderTraversal(root->rChild);
    }
}

void inOrderTraversal(struct node* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->lChild);
        printf("%d ",root-> data);
        inOrderTraversal(root->rChild);
    }
}

void postOrderTraversal(struct node* root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->lChild);
        postOrderTraversal(root->rChild);
        printf("%d ",root-> data);
    }
}

int main(){
    int choice;
    while(1)
    {
        printf("\n1. Create a binary tree.\n");
        printf("2. Perform pre-order-traversal.\n");
        printf("3. Perform in-order-traversal.\n");
        printf("4. Perform post-order-traversal\n");
        printf("5. Quit.\n\n");
        printf("Enter your choice.\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements in the binary tree.\n");
            int n,s;
            scanf("%d",&n);
            printf("Enter the elements.\n");
            while(n--){
                scanf("%d",&s);
                insert(s);
            }
            break;
        case 2:
            printf("pre-order-traversal : \n");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("in-order-traversal : \n");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("post-order-traversal : \n");
            postOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            exit(1);
        default:
            break;
        }
    }
    
    return 0;
}
