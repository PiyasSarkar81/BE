
#define PIE 3.14

#include<stdio.h>
int main(){
int l,b,r,aR,aC,pR,cC;
printf("Enter the length of the rectangle\n");
scanf("%d",&l);
printf("Enter the beadth of the rectangle\n");
scanf("%d",&b);
printf("Enter the radius of the circle\n");
scanf("%d",&r);
pR = 2*(l+b);
cC = 2*PIE*r;
aR = l*b;
aC = PIE*r*r;
printf("the area of the rectangle\n%d\n",aR);
printf("the area of the circle\n%d\n",aC);
printf("the circumference of the circle\n%d\n",cC);
printf("the perimeter of the rectangle \n%d\n",pR);
return 0;
}
