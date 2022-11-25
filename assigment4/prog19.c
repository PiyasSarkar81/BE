#include<stdio.h>

int check_date(int day, int mon, int year){
    int is_valid = 1, is_leap = 0;
    if (year >= 1800 && year <= 9999) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            is_leap = 1;
        }
        if(mon >= 1 && mon <= 12){
            if (mon == 2){
                if (is_leap && day == 29) {
                    is_valid = 1;
                }
                else if(day > 28) {
                    is_valid = 0;
                }
            }
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
                if (day > 30){
                    is_valid = 0;
                }
            }
            else if(day > 31){            
                is_valid = 0;
            }        
        }
        else{
            is_valid = 0;
        }
    }
    else{
        is_valid = 0;
    }

    return is_valid;
}

int main(){
    int day1, mon1, year1,day2, mon2, year2;
    int is_leap = 0, is_valid = 1;
    printf("Enter first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day1, &mon1, &year1);
    printf("Enter second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day2, &mon2, &year2);
    if(!check_date(day1, mon1, year1)){
        printf("First date is invalid.\n");        
    }
    if(!check_date(day2, mon2, year2)){
        printf("Second date is invalid.\n");
    }
    if(year1 > year2){
        printf("1\n");
    }
    else if (year1 < year2){
        printf("-1\n");
    }
    else{
        if (mon1 ==  mon2){
            if (day1 ==  day2){
                printf("0\n");
            }
            else if(day1 > day2){
                printf("1\n");
            }
            else{
                printf("-1\n");
            }
        }
        else if (mon1 > mon2){
            printf("1\n");
        }
        else {
            printf("-1\n");
        }        
    }
    return 0;
}
