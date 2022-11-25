#include <stdio.h> 

int length(char* string) {
	int count = 0;
	while (string[count] != '\0') {
		++count;
	}
	return count;

}

void convert(char s[]) 
{ 
    int num = 0,i; 
    int n = length(s); 
    for ( i = 0; i < n; i++) 
        num = num * 10 + (s[i] - 48); 
    printf("%d\n", num); 
} 
int main() { 
    char s[] = "123";  
    convert(s); 
    return 0; 
}
