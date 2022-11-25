#include<stdio.h>
int main()
{
printf("Enter the size: ");
int size;
scanf("%d",&size);
int arr[size];
printf("Enter the elements of the array:\n");
int i;
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
int j,newarr[size],size2=0;
int c=0;
for(i=0;i<size;i++)
{
c=1;
for(j=0;j<i;j++)
{
if(arr[i]==arr[j])
{
c=0;
}
}
if(c==1)
{
newarr[size2++]=arr[i];
}
}

printf("Reversed array without repeted value: \n");
for (i=0;i<size2/2;i++)
{
int t=newarr[i];
newarr[i]=newarr[size2-1-i];
newarr[size2-1-i]=t;
}
for(i=0;i<size2;i++)
{
printf("%d ",newarr[i]);
}
printf("\n");
return 0;
}

