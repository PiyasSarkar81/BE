#include<stdio.h>
int main()
{
int student[5][6],s=0,i,j,m;
for(i=0;i<5;i++)
{
printf("Enter the marks of student%d:\n",i+1);
for(j=0;j<5;j++)
{
scanf("%d",&student[i][j]);
s=s+student[i][j];
}
student[i][j]=s;
s=0;
}
m=0;
for(i=0;i<5;i++)
{
if(student[i][5]>=m)
m=student[i][5];
}
for(i=0;i<5;i++)
{
printf("\nThe total number of the student%d is:%d",i+1,student[i][5]);
}
printf("\nThe highest total marks is:%d\n",m);
return 0;
}


