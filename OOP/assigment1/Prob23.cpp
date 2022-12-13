#include<iostream>
#include<math.h>

using namespace std;

static int acno = 1;

class SavingAccount{
    char *name;
    int Acc_no;
    double  balance;
    public:
    SavingAccount(char *name = "",double balance = 1000  ) 
    {
        Acc_no = acno++;
        this->name = name;
        this->balance = balance;
    }

    void withdraw(int a){
        if(balance - a >= 1000)
        {
            balance = balance -a;
        }
        else cout<<"Can't be withdraw because account must have a minimum balance of Rs. 1000."<<endl;
    }

    void deposit(int b){
        balance += b;
    }

    void interest(double r){
        cout<<"Interest : "<< balance *(r/100)<<endl;
        balance += balance *(r/100);
        cout<<"Total Balance : "<<balance<<endl;
    }

    void display()
    {
        cout<<"NAME : "<<name<<endl;
        cout<<"Account no : "<<Acc_no<<endl;
        cout<<"Balance : "<<balance<<endl;
    }
};

int main(){
    SavingAccount ob1("piyas",1000), ob2("Animesh",2000);
    ob1.display();
    ob2.display();
    ob1.interest(5);
    ob2.withdraw(500);
    ob1.deposit(500);
    ob1.display();
    ob2.display();

return 0;
}
