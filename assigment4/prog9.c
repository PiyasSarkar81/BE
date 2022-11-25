#include <stdio.h>
 
void upperCase(char* Str1){
    int i;
    for (i = 0; Str1[i]!='\0'; i++)
  	{
  		if(Str1[i] >= 'a' && Str1[i] <= 'z')
  		{
  			Str1[i] = Str1[i] -32;
		}
  	}
}

int main()
{
  	char str[100];
  	int i;
 
  	printf("\n Please Enter a String that you want to Convert into Uppercase :  ");
  	scanf ("%[^\n]s", str);
  	upperCase(str);
  	printf("\n The given String in Upper Case = %s\n", str);
  	
  	return 0;
}
