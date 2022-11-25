#include<stdio.h>
int main(){
int a,b,result;
printf("Enter the two integers: ");
scanf("%d %d",&a,&b);
if(a>b){
result =a%b;
printf("Result: %d/%d\n",result,b);
}
else{
result =b%a;
printf("Result:	%d/%d\n",result,a);
}

float f;
if(a>b){
f =(float)a/b;
}
else{
f =(float)b/a;
}
printf("Result : %.1f\n",f);
return 0;
}



