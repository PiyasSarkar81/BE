#include<stdio.h>
int main(){
float s1,s2,s3,a1,a2,a3;
printf("Enter the three angles of the triangle in degree\n");
scanf("%f %f %f",&a1,&a2,&a3);
printf("Enter the three	sides of the triangle\n");
scanf("%f %f %f",&s1,&s2,&s3);
if((s1+s2)>s3 && (s2+s3)>s1 && (s3+s1)>s2 && a1+a2+a3 == 180 ){
printf("triangle is valid\n");
}
else{
printf("triangle is not valid\n");
}
return 0;
}
