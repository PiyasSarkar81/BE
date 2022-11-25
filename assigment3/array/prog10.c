#include<stdio.h>
int main(){
int i,j,arr[4],num,l,s,d,temp;
printf("Enter the 4 digit number\n");
scanf("%d",&num);
do{
temp=num;
for(i=0;i<4;i++){
arr[i]=num%10;
num/=10;
}
printf("The 4-digit number: %d%d%d%d\n",arr[3],arr[2],arr[1],arr[0]);
for(i=0;i<4;i++){
for(j=i+1;j<4;j++){
if(arr[i]>arr[j]){
arr[i]=arr[i]+arr[j];
arr[i]=arr[i]-arr[j];
arr[i]=arr[i]-arr[j];
}
}
}
printf("larger number:%d%d%d%d\n",arr[3],arr[2],arr[1],arr[0]);
printf("smaller number:%d%d%d%d\n",arr[0],arr[1],arr[2],arr[3]);
l=1000*arr[3]+100*arr[2]+10*arr[1]+arr[0];
s=1000*arr[0]+100*arr[1]+10*arr[2]+arr[3];
d=l-s;
num=d;
for(i=0;i<4;i++){
arr[i]=d%10;
d/=10;
}
printf("difference of the larger number and the smalller number: %d%d%d%d\n",arr[3],arr[2],arr[1],arr[0]);
}
while(num==temp);

return 0;
}
