#include<stdio.h>
int main(){
char c[5];
printf("Enter the 5 letter word: \n");
scanf("%s",&c);
int i;
for(i=0;i<5;i++){
c[i]=(int)c[i]-30;
}
printf("The encoded word is: %s\n",c);
return 0;
}
