#include<stdio.h>
int main(){
int a,b,c;
printf("Enter three numbers\n");
scanf("%d %d %d",&a,&b,&c);
if(a<b){
if(a<c){
printf("minimun number: %d\n",a);
}
else{
printf("minimum number: %d\n",c);
}
}
else{
if(b<c){
printf("minimum	number:	%d\n",b);
}
else{
printf("minimum	number:	%d\n",c);
}
}
if(a>b){
if(a>c){
printf("maximum	number:	%d\n",a);
}
else{
printf("maximum	number:	%d\n",c);
}
}
else{
if(b>c){
printf("maximum number: %d\n",b);
}
else{
printf("maximum number: %d\n",c);
}
}

return 0;
}
