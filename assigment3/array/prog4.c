#include<stdio.h>
#include<stdlib.h>

int main(){
int n,i,r,small,big;
printf("Enter the number of intigers\n");
scanf("%d",&n);
int arr[n] ;
printf("enter %d the values :\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
small=big=arr[0];
for(i=0;i<n;i++){
if(arr[i]<small){
small=arr[i];
}
if(arr[i]>big){
big=arr[i];
}
}
r=big-small;
printf("Renge is:%d\n",abs(r));
 return 0;
}

