#include<stdio.h>
int formulate(int n){
if (n==1){
return 1;
}
else{
if(n%2==1){
printf("Next value is: %d\n",n*3+1);
return formulate((n*3+1))+1;
}
else
{
printf("Next value is: %d\n",n/2);
return formulate((n/2))+1;
}
}
}
int main(){
int n ,op=0;
printf("Enter the initial value:\n");
scanf("%d",&n);
printf("Initial value is: %d\n",n);
op = formulate(n)-1;
printf("No of operatiopns is: %d\n",op);
return 0;
}
