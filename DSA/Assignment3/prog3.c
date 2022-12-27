#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int inOrderArr[MAX];
int count = 0;

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

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->lChild != NULL)
        current = current->lChild;
 
    return current;
}

struct node* deleteNode(int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->lChild = deleteNode(key);
    else if (key > root->data)
        root->rChild = deleteNode( key);
    else {
        if (root->lChild == NULL) {
            struct node* temp = root->rChild;
            free(root);
            return temp;
        }
        else if (root->rChild == NULL) {
            struct node* temp = root->lChild;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->rChild);
        root->data = temp->data;
        root->rChild = deleteNode(temp->data);
    }
    return root;
}

void inOrderTraversal(struct node* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->lChild);
        inOrderArr[count] = root -> data;
        count++;
        inOrderTraversal(root->rChild);
    }
}

void inOrderTra(struct node* root)
{
    if(root != NULL)
    {
        inOrderTra(root->lChild);
        printf("%d ",root->data);
        inOrderTra(root->rChild);
    }
}

void preOrderTra(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrderTra(root->lChild);
        preOrderTra(root->rChild);
    }
}

int main(){
    int choice, key,i;
    struct node* pre = NULL, *suc = NULL;
    while(1)
    {
        printf("\n1. Create a binary search tree.\n");
        printf("2. Search a key in the binary search tree.\n");
        printf("3. Find in-order predecessor and successor of a node whose key will be an user input\n");
        printf("4. Insert a key in the binary search tree.\n");
        printf("5. Delete a key in the binary search tree.\n");
        printf("6. Inorder and Preorder traversal of the tree.\n");
        printf("7. Quit.\n\n");
        printf("Enter your choice.\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements in the BST.\n");
            int n,s;
            scanf("%d",&n);
            printf("Enter the elements.\n");
            while(n--){
                scanf("%d",&s);
                insert(s);
            }
            break;
        case 2:
            printf("Enter the key has to search.\n");
            scanf("%d",&key);
            if(search(key)!=NULL)
            printf("Key is found.\n");
            else
            printf("Key is not found.\n");
            break;
        case 3:
            count=0;
            inOrderTraversal(root);
            printf("Enter the key.\n");
            scanf("%d",&key);
            for(i=0;i<count;i++)
            {
                if(inOrderArr[i]==key) break;
            }
            if(inOrderArr[i-1] != 0)
                printf("in-order-predessasor of the key is %d\n",inOrderArr[i-1]);
            else printf("in-order-predessasor is absent.\n");
            if(inOrderArr[i+1] != 0) printf("in-order-successer is %d\n",inOrderArr[i+1]);
            else printf("in-order-succeser is absent.\n");
            break;
        case 4:
            printf("Enter the key to be inserted : ");
            scanf("%d",&key);
            insert(key);
            break;
        case 5:
            printf("Enter the key to be deleted : ");
            scanf("%d",&key);

        case 6:
            printf("In-order-traversal is:\n");
            inOrderTra(root);
            printf("\n");
            printf("Pre-order-traversal is:\n");
            preOrderTra(root);
            printf("\n");
            break;
        case 7:
            exit(1);
        default:
            break;
        }
    }
    
    return 0;
}