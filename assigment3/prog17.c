#include <stdio.h>
int main(){
printf("Enter the number n\n");
int n,i;
scanf("%d",&n);
int arr[n];
arr[0]=0;
arr[1]=1;
for(i=2;i<n;i++){
arr[i]=arr[i-1]+arr[i-2];
}
for(i=0;i<n;i++){
printf("%d\t",arr[i]);
}
printf("\n");
return 0;
}

