#include<stdio.h>

struct student {
char name[20];
int roll;
float math;
float DS;
float CN;
float WN;
float OS;

float total;
};

int main(){
int n;
printf("Enter the number of students of your class : ");
scanf("%d",&n);
struct student s[n];
int i;
for(i=0;i<n;i++){
printf("Enter the name of the student : ");
scanf("%s",&s[i].name);
printf("Enter the marks of math : ");
scanf("%f",&s[i].math);
printf("Enter the marks of DS : ");
scanf("%f",&s[i].DS);
printf("Enter the marks of CN : ");
scanf("%f",&s[i].CN);
printf("Enter the marks of WN : ");
scanf("%f",&s[i].WN);
printf("Enter the marks of OS : ");
scanf("%f",&s[i].OS);
}
for(i=0;i<n;i++){
s[i].total = s[i].math + s[i].DS + s[i].CN + s[i].WN + s[i].OS;
} 
int j;
struct student t;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(s[i].total>s[j].total){
t=s[j];
s[j]=s[i];
s[i] = t;
}
}
}

printf("Top 5 students are:\n");
for(i=0;i<5;i++){
printf("%s\n",s[i].name);
}

return 0;
}
