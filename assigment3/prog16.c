#include <stdio.h>
 int main(){
int arr[100],i,p=0,n=0,z=0;
printf("Enter the 100 integers\n");
for(i=0;i<100;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<100;i++){
if(arr[i]==0){
 z++;
}
else if(arr[i]<0){
n++;
}
else{
p++;
}
}
printf("positive numbers : %d\n",p);
printf("negetive numbers : %d\n",n);
printf("zeros  : %d\n",z);
}
