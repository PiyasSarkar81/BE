#include <stdio.h>

void countWord(char* s){
    int count = 0, i;
    for (i = 0;s[i] != '\0';i++){
        if (s[i] == ' ' && s[i+1] != ' ')
            count++;    
    }
    printf("Number of words in given string are: %d\n", count + 1);
}
 
int main(){
    char s[200];
    printf("Enter the string:\n");
    scanf ("%[^\n]s", s);
    countWord(s);
    return 0;
}
