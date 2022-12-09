#include<iostream>
#include<math.h>
using namespace std;

class GradeCard 
{
   string name,dept;
   int roll,semester,n;
   double cgpa;
    int *a;
   public:
   void getData()
   {
       cout << "Enter the department : ";
       cin >> dept;
       cout << "Enter the name : ";
       cin >> name;
       cout << "Enter the roll no. : ";
       cin >> roll;
       cout << "Enter the semester : ";
       cin >> semester;
       cout << "Enter the number of subjects : ";
       cin >> n;
       a = new int [n];
       cout << "Enter the marks in the subjects :";
       int sum = 0;
       for(int i = 0; i < n; i++)
       {
           cin>>a[i];
       }
       cout << "Enter the CGPA : ";
       cin >> cgpa;
   }

   void getMax(GradeCard arr[])
   {
       double m = -1.0;
       for(int i = 0 ; i < 60; i++)
       {
           if(m<arr[i].cgpa)
           {
               m = arr[i].cgpa;
           }
       }
       for(int i = 0; i < 60; i++)
       {
           if(m==arr[i].cgpa)
           {
            cout << arr[i].name <<" roll number "<<arr[i].roll<< " got the maximum CGPA = " << arr[i].cgpa;
            return ;
           }
       }
   }
       
};
int main()
{
    
        GradeCard g[60];
        for(int i = 0; i < 60; i++)
        g[i].getData();

        g[0].getMax(g);


   return 0;
}