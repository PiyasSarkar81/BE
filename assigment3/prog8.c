#include<stdio.h>
int sumfallfactor(int n){
int sum =0,i;
for(i=1;i<=n;i++){
if(n%i==0){
sum+=i;
}
}
return sum;
}
int main(){
int i,n,sum=0;
printf("Enter the number\n");
scanf("%d",&n);
for(i=1;i<=n;i++){
sum+=sumfallfactor(i);
}
printf("S = 1@ + 2@ + 3@ + 4@ + … + n@ = %d\n",sum);
return 0;
}
