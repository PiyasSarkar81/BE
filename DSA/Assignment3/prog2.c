#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* lChild;
    struct node* rChild;
};

struct node* root = NULL;

struct node * newNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> lChild = NULL;
    temp -> rChild = NULL;
    return temp;
}

struct node* construct(int preOrder[], int start, int end, int inOrder[], int *pIndex)
{
    if(start>end) return NULL;
    struct node* node = newNode(preOrder[(*pIndex)++]);
    int i;
    for(i = start; i<=end;i++)
    {
        if(inOrder[i]== node->data) break;
    }
    node -> lChild = construct(preOrder, start, i-1,inOrder,pIndex);
    node -> rChild = construct(preOrder, i+1, end,inOrder,pIndex);
    return node; 
}

struct node* constBST(int inOrder[], int preOrder[], int n)
{
    int pIndex =0;
    return construct(preOrder,0,n-1,inOrder,&pIndex);
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

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int compare(int preOrder[],int inOrder[] , int n)
{
int pO[n],iO[n],i,j;
for(i=0;i<n;i++)
{
pO[i] = preOrder[i];
iO[i] = inOrder[i];
}
insertionSort(pO,n);
insertionSort(iO,n);

for(i=0;i<n;i++)
{
if(pO[i]!=iO[i])
return 0;
}

return 1;
}

int main(){
    int n;
    printf("Enter the number of elements of the tree.\n");
    scanf("%d",&n);
    int preOrder[n], inOrder[n];
    do
    {
    printf("Enter the pre-order-traversal.\n");
    int i;
    for(i=0;i<n;i++) scanf("%d",&preOrder[i]);
    printf("Enter the in-order-traversal.\n");
    for(i=0;i<n;i++) scanf("%d",&inOrder[i]);

    if(!compare(preOrder,inOrder,n))
    printf("\nWrong Input.\n");
    }
    while(!compare(preOrder,inOrder,n));    

    root = constBST(inOrder,preOrder,n);

    printf("Post-order-traversal of newly created tree is :.\n");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}
