#include<stdio.h>
int main(){
int a,b,c,avg;
printf("Enter the three integer numbers\n");
scanf("%d %d %d",&a,&b,&c);
avg =(a+b+c)/3;
printf("Below avg numbers are:\n");
if(a<avg){
printf("%d\n",a);
}
if(b<avg){
printf("%d\n",b);
}
if(c<avg){
printf("%d\n",c);
}
printf("Above avg numbers are:\n");
if(a>avg){
printf("%d\n",a);
}
if(b>avg){
printf("%d\n",b);
}
if(c>avg){
printf("%d\n",c);
}

return 0;
}

