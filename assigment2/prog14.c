#include<stdio.h>
int main(){
int a,i;
printf("enter the five-digit number:");
scanf("%d",&a);
int arr[5];
for(i=0;i<5;i++){
arr[i]=((a%10)+1)%10;
a/=10;
}
for(i=4;i>=0;i--){
printf("%d\n",arr[i]);
}
return 0;
}

