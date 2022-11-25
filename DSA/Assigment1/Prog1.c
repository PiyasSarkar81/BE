#include<stdio.h>

int main()
{
int a[10];
printf("Enter 10 elements of an array.\n");
int i;
for(i=0;i<10;i++){
scanf("%d",&a[i]);
}
for(i=2;i<9;i++){
a[i]=a[i+1];
}
for(i=4;i<8;i++){
a[i]=a[i+1];
}
printf("3th & 6th elements are deleated.\n");
printf("the 5th element in the new array is %d\n",a[4]);
return 0;
}
