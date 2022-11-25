#include<stdio.h>
int main(){
int a[100],n,t,i,c;
printf("Enter the size of the array: ");
scanf("%d",&n);
c=n-1;
printf("Enter the numbers:");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<=(c-1)/2;i++)
{
t=a[i];
a[i]=a[c-i];
a[c-i]=t;
}
printf("\nThe reversed array is:\n");
for(i=0;i<n;i++){
printf("\t%d",a[i]);
}
return 0;
}


