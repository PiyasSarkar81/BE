#include<stdio.h>
int main(){
int a;
printf("Enter the three digits number number: ");
scanf("%d",&a);
int sum =0;
while(a>0){
sum = sum+ a%10;
a/=10;
}
printf("sum of three digits: %d\n",sum);
return 0;
}

