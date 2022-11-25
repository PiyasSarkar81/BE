#include<stdio.h>
int main(){
int i,j,ct;
printf("All the prime number 1 to 100\n");
for(i=1;i<=100;i++){
ct=0;
for(j=1;j<=i;j++){
if(i%j==0){
ct++;
}
}
if(ct==2){
printf("%d\t",i);
}
}
printf("\n");
return 0;
}
