#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node *addatlist(struct node *last, int data, int pos){
    struct node *tmp,*p;
    int i;
    tmp = (struct node*)malloc(sizeof (struct node));
    tmp -> info = data;
    if(pos == 1)
    {
        last = tmp;
        last -> link = last;
        return last;
    }
    tmp -> link = last -> link;
    last -> link = tmp;
    last = tmp;
    return last;
}

struct node *create_list(struct node * last){
    int n,i;
    struct node *p = last;
    printf("Enter the number of elements in the circular link list.\n");
    scanf("%d",&n);
    last = NULL;
    if(n==0) return last;
    // printf("Enter the %d elements\n",n);

    for(i=1;i<=n;i++){
        // int data;
        // scanf("%d",&data);
        last = addatlist(last,i,i);
    }
    return last;
} 

void display(struct node *last){
    struct node *p;
    if(last == NULL){
        printf("List is empty\n");
        return;
    }
    p= last -> link;
    printf("List is.\n");
    do{
        printf("%d ",p->info);
        p=p->link;
    }while(p!=last->link);
    printf("\n\n");
}


int count(struct node * last){
    struct node * p;
    p=last -> link;
    int c =0;
    do{
        p=p->link;
        c++;
    }while(p!= last -> link);
    return c;
}

void josephusCircle(struct node* last,int k){
    struct node * p, *tmp;
    p = last ;
    while(count(last)>1){
     for(int i=1;i<k;i++){
            p=p->link;
        }
        if(p->link == last){
            last = p;
        }
        tmp = p->link;
        p->link = tmp -> link;
        free(tmp);
        if(p-> link == p)
        printf("Josephus Circle number : %d",p->info);
    }

}

int main(){
    struct node* last = NULL;
    last = create_list(last);
    printf("Count to choose next : ");
    int k;
    scanf("%d",&k);
    josephusCircle(last,k);
    return 0;
}
