#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node *addtoempty(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    last = tmp;
    last -> link = last;
    return last;
}

struct node *addatend(struct node *last, int data)
{
    struct node* tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> link = last -> link;
    last -> link = tmp;
    last = tmp;
    return last;
}

struct node *create_list(struct node * last){
    int n,i,data;
    printf("Enter the length of the Josephus promlem.\n");
    scanf("%d",&n);
    last = NULL;
    if(n==0) return last;
    last = addtoempty(last,1);

    for(i=2;i<=n;i++){
        last = addatend(last,i);
    }
    return last;
} 

int survivor(struct node *last, int k)
{
    struct node *p, *q;
    int i;
 
    q = p = last -> link;
    while (p->link != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->link;
        }
        q->link = p->link;
        printf("%d has been killed.\n", p->info);
        free(p);
        p = q->link;
    }
    last = p;
 
    return (p->info);
}

int main(){
    struct node* last = NULL;
    last = create_list(last);
    printf("Count to choose next : ");
    int k;
    scanf("%d",&k);
    
    printf("survivor is : %d",survivor(last, k));
    return 0;
}
