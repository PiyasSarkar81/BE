#include<stdio.h>
int main(){
printf("Enter the number root you would like to find: \n");
int n,i,oddn=1,sum=0;
scanf("%d",&n);
while(sum<n){
sum+=oddn;
oddn+=2;
}
if(n==sum){
printf("The squre root of %d is %d \n",n,(oddn-1)/2);
}
else{
printf("Could not find the squre root\n");
}
return 0;
}

