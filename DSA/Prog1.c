#include<stdio.h>

struct state{
char state[20];
int engColl;
int medColl;
int magColl;
int uni;
};

int main(){
printf("Enter the number of States : ");
int n;
scanf("%d",&n);
struct state a[n];
int i;
for(i=0;i<n;i++){
printf("\nEnter the name of States : ");
scanf("%s",&a[i].state);
printf("Enter the number of engineering collage : ");  
scanf("%d",&a[i].engColl);
printf("Enter the number of medical collage : ");  
scanf("%d",&a[i].medColl);
printf("Enter the number of managgering collage : ");  
scanf("%d",&a[i].magColl);
printf("Enter the number of university : ");  
scanf("%d",&a[i].uni);
}

int arr[n];
for(i=0;i<n;i++){
arr[i] = a[i].engColl+a[i].medColl+a[i].magColl+a[i].uni;
}
int max = 0;
int maxi =0;
for(i=0;i<n;i++){
if(arr[i]>max){
max = arr[i];
maxi=i;
}
}
printf("\nHighest number of collages in %c state\n\n",a[maxi].state);

return 0;
}
