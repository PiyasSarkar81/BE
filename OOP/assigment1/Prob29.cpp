#include<iostream>

using namespace std;

class Book{

string isbn;
string title;
string *authors;
double price;

public:

void setIsbn(string i)
{
isbn = i;
}

void setTitle(string t)
{
title = t;
}

void setAuthors()
{
cout<<"Enter the number of authors."<<endl;
int n;
cin>>n;
authors = new string [n];
for(int i =0;i<n;i++)
{
cin>>authors[i];
}
}

void setPrice(double p)
{
price = p;
}

string getIsbn() const
{
return isbn;
}

string getTitle() const
{
return title;
}

string *getAuthors () 
{
return authors;
}

double getPrice() const
{
return price;
}

void disp()
{
cout<<"ISBN : "<<isbn<<endl;
cout<<"Title : "<<title<<endl;
cout<<"Authors : "<<endl;
cout<<"Price: "<<price; 
} 
};

int main()
{

return 0;
}



