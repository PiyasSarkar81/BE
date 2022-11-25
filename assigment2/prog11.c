#include<stdio.h>
int main(){
int i,sub[5],agg=0,per=0;
printf("Enter the marks in five subjects\n");
for(i=0;i<5;i++){
scanf("%d",&sub[i]);
}
for(i=0;i<5;i++){
agg+=sub[i];

}
per =agg/5;
printf("aggregate marks obtained by the student is: %d\n",agg);
printf("percentage marks obtained by the student is: %d\n",per);

return 0;
}
  
