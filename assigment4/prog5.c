#include <stdio.h>

int main(){
    char str[50];
    int i, l = 0;
    printf("Input a string : ");
    scanf ("%[^\n]s", str);
    for (i = 0; str[i] != '\0'; i++){
        l++;
    }
    printf("So, the length of the string is : %d\n", l);
    return 0;
}
