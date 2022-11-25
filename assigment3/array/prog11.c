#include<stdio.h>
#include<math.h>

int main(){
int n,i;
printf("Enter the number of elements\n");
scanf("%d",&n);
int x[n];
float y,sum=0,sum1=0,z,s;
printf("Enter some numbers: \n");
for(i=0;i<n;i++){
scanf("%d",&x[i]);
}
for(i=0;i<n;i++){
sum+=x[i];
}
y=sum/n;
for(i=0;i<n;i++){
sum1+=(x[i]-y)*(x[i]-y);
}
z=sum1/(n-1);
s=sqrt(z);
printf("Standerd deviation is: %.6f\n",s);

return 0;
}
