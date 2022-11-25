#include<stdio.h>

int main(){
printf("Enter the 10 integers\n");
int i,j,a[10];
for(i=0;i<10;i++){
scanf("%d",&a[i]);
}
for(i=0;i<10;i++){
for(j=i+1;j<10;j++){
if(a[i]>a[j]){
a[i]=a[i]+a[j];
a[j]=a[i]-a[j];
a[i]=a[i]-a[j]; 
}
}
}
printf("shorted integers:\n");
for(i=0;i<10;i++){
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
