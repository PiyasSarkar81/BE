#include<stdio.h>

int main(){
int i,j,n;
printf("Enter the number of rows & colums of the squre matrix\n");
scanf("%d",&n);

int a[n][n];
printf("Enter the matrix\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
printf("the transpose matrix is\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d\t",a[j][i]);
}
printf("\n");
}
 return 0;
}
