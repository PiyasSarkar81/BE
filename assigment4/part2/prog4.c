#include <stdio.h>
struct student
{
char name[100];
int roll;
int marks[6];
double avg;
};
int main()
{
struct student s[10];
int i;
for(i=0;i<10;i++)
{
printf("Enter the name, roll no and marks of studnt %d in 6 subjects",i+1);
scanf("%s %d ",&s[i].name,&s[i].roll);
int j;
for(j=0;j<6;j++)
scanf("%d",&s[i].marks[j]);
}
int avg;
int j;
for(i=0;i<10;i++)
{
avg=0;
for(j=0;j<6;j++)
{
avg=avg+s[i].marks[j];
}
avg = avg/6.0;
s[i].avg = avg;
}
for(i=0;i<9;i++)
{
for(j=i+1;j<9;j++)
{
if(s[j].avg>s[j+1].avg)
{
struct student t1;
t1=s[j];
s[j]=s[j+1];
s[j+1]=t1;
}
}
}
printf("  Roll              Name                 Avg\n");
for(i=0;i<10;i++)
{
printf("%5d %20s %3.2f\n",s[i].roll,s[i].name,s[i].avg);
}
return 0;
}




