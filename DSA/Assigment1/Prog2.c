#include<stdio.h>
int main(){
printf("Enter the number of dist in the array.\n");
int n;
scanf("%d",&n);
int a[n];
int i,t;
printf("Enter the %d elements of the array.\n",n);
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("The reverse array is:\n");
for(i=0;i<n/2;i++){
t=a[i];
a[i]=a[n-i-1];
a[n-i-1]=t;
}
for(i=0;i<n;i++){
printf("%d ",a[i]);
}
printf("\n");
return 0;
}

