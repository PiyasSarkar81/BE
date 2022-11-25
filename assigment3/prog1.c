#include<stdio.h>
int main(){
int n;
printf("Enter the valu of 'n'\n");
scanf("%d",&n);
int i;
for(i=1;i<=100;i++){

if(i%n==0){
printf("%d\t",i);
}
}
printf("\n");
return 0;
}
