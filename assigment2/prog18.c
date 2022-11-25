#include<stdio.h>
int main(){
int year;
printf("Enter a year: \n");
scanf("%d",&year);
if(year%400==0){
printf("This year is leap year\n");
}
else if(year%100==0){
printf("This year is not a leap year\n");
}
else if(year%4==0){
printf("This year is leap year\n");
}

else{
printf("This year is not a leap year\n");
}
return 0;
}
