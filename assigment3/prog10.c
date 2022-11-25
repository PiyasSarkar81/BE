#include<stdio.h>

int isprime(int n){
int c=0,i;
for(i=1;i<=n;i++){
if(n%i==0)
c++;
}
if(c!=2)
return 0;
else
return 1;
}
int main(){
int n,i;
printf("Enter the number to find prime factors of : \n");
scanf("%d",&n);
for(i=1;i<n;i++){
if(n%i==0&&isprime(i)){
printf("%d\t",i);
}
}
printf("\n");
return 0;
}

