#include<stdio.h>

int isVowel(char ch)
{
    switch (ch)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return 1;
            break;
        default:
            return 0;
    }
}

int main()
{
    char str[80];
    int i, found = 0, count = 0;
    printf("Enter a string: ");
    scanf ("%[^\n]s", str);
    printf("Vowels in successions are :\n");
    for (i = 0; str[i] != '\0'; i++){
        if (isVowel(str[i])) found++;
        else found = 0;
        if (found == 2){
            printf("%c%c\n", str[i - 1], str[i]);
            found = 1;
            count++;
        }
    }
    printf("\nTotal number of occurences : %d\n", count++);

    return 0;
}
