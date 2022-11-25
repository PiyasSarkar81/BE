#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
   
    int num,d=0,o=0,w,rem=0,p=0,i=0,j=0,len;
    long long b=0,t;
    char hexa[100];

    printf("Chose among the folloing options.\n\n");
    printf("1.Binary to Desimel.\n");
    printf("2.Binary to Octal.\n");
    printf("3.Binary to Hexadesimel\n");
    printf("4.Desimel to Binary.\n");
    printf("5.Desimel to Octal\n");
    printf("6.Desimel to Hexadecimel.\n");
    printf("7.Octal to Binary.\n");
    printf("8.Octal to desimel.\n");
    printf("9.Octal to Hexadesimel .\n");
    printf("10.Hexadesimel to Binary.\n");
    printf("11.Hexadesimel to desimel.\n");
    printf("12.Hexadesimel to Octal .\n");
    
    scanf("%d",&num);

    switch(num){
        case 1 : 
            printf("Enter the Binary number.\n");
            scanf("%ld",&b);
            d=0,w=1;
            while(b != 0)
            {
                rem = b%10;
                d = d+ rem*w;
                b = b/10;
                w = w*2;
            }
            printf("The Desimel value is %ld\n",d);
            break;
        case 2 :
        printf("Enter the Binary number.\n");
            scanf("%ld",&b);
            d=0,w=1;
            printf("Octal equivalent of binary number %ld is\n",b);
            while(b != 0)
            {
                rem = b%10;
                d = d+ rem*w;
                b = b/10;
                w = w*2;
                p++;
            }
            p=1;
            rem=0;
            while(d != 0){
                rem=d%8;
                o+=rem*p;
                d/=8;
                p*=10;
            }
            printf("%d\n",o);



        break;
        case 3 :
          printf("Enter the Binary number.\n");
            scanf("%ld",&b);
            d=0,w=1;
            while(b != 0)
            {
                rem = b%10;
                d = d+ rem*w;
                b = b/10;
                w = w*2;
            }
            i=0;
            rem=0;
            printf("The Hexadecimel valu is :\n");
            while(d != 0){
                rem=d%16;
                if(rem<10){
                    hexa[i]=rem+48;
                }
                else{
                    hexa[i]=rem+55;
                }
                i++;
                d/=16;
            }
            for(j=i-1;j>=0;j--){
                printf("%c",hexa[j]);
            }
            

        break;
        case 4 :
        printf("Enter the Desimel number.\n");
            scanf("%d",&d);
            printf("Binary valu is \n");
            rem= 0;
            p=1;
            while (d!=0)
            {
                rem=d%2;
                d/=2;
                b+=rem*p;
                p*=10;
            }
            printf("%ld",b);
            
        break;
        case 5 :
        printf("Enter the Desimel number.\n");
            scanf("%d",&d);
        printf("Octal equivalent of decimel number %d is\n",d);
         p=1;
            rem=0;
            while(d != 0){
                rem=d%8;
                o+=rem*p;
                d/=8;
                p*=10;
            }
            printf("%d\n",o);
        break;
        case 6 :
        printf("Enter the Desimel number.\n");
            scanf("%d",&d);

         i=0;
            rem=0;
            printf("The Hexadecimel valu is :\n");
            while(d != 0){
                rem=d%16;
                if(rem<10){
                    hexa[i]=rem+48;
                }
                else{
                    hexa[i]=rem+55;
                }
                i++;
                d/=16;
            }
            for(j=i-1;j>=0;j--){
                printf("%c",hexa[j]);
            }
        break;
        case 7 :
        printf("Enter the octal number.\n");
            scanf("%d",&o);
            printf("Binary value is \n");
             p=1;
            rem=0;
            while(o != 0){
                rem=o%10;
                d+=rem*p;
                o/=10;
                p*=8;
            }
            rem= 0;
            p=1;
            while (d!=0)
            {
                rem=d%2;
                d/=2;
                b+=rem*p;
                p*=10;
            }
            printf("%ld",b);


        break;
        case 8 :
        printf("Enter the octal number.\n");
            scanf("%d",&o);
            printf("Desimel value is \n");
            p=1;
            rem=0;
            while(o != 0){
                rem=o%10;
                d+=rem*p;
                o/=10;
                p*=8;
            }
            printf("%d",d);
        break;
        case 9 :
        printf("Enter the octal number.\n");
            scanf("%d",&o);
            printf("hexadesimel value is \n");
            p=1;
            rem=0;
            while(o != 0){
                rem=o%10;
                d+=rem*p;
                o/=10;
                p*=8;
            }
            i=0,rem=0;
            while(d != 0){
                rem=d%16;
                if(rem<10){
                    hexa[i]=rem+48;
                }
                else{
                    hexa[i]=rem+55;
                }
                i++;
                d/=16;
            }
            for(j=i-1;j>=0;j--){
                printf("%c",hexa[j]);
            }

        break;
        case 10:
        p=1;
        printf("Enter the Hexadecimel number.\n");
        scanf("%s",&hexa);
        len = strlen(hexa);
        printf("the Binary number is\n");
        for(i=len-1;i>=0;i--){
            if(hexa[i]>='0'&&hexa[i]<='9'){
                d += (hexa[i]-48)*p;
                p*=16;
            }
            else{
                d += (hexa[i]-55)*p;
                p*=16;
            }
        }
        rem= 0;
            p=1;
            while (d!=0)
            {
                rem=d%2;
                d/=2;
                b+=rem*p;
                p*=10;
            }
            printf("%ld",b);
        break;
        case 11:
        p=1;
        printf("Enter the Hexadecimel number.\n");
        scanf("%s",&hexa);
        len = strlen(hexa);
        printf(" the Desimel number is\n");
        for(i=len-1;i>=0;i--){
            if(hexa[i]>='0'&&hexa[i]<='9'){
                d += (hexa[i]-48)*p;
                p*=16;
            }
            else{
                d += (hexa[i]-55)*p;
                p*=16;
            }
        }
        

        printf("%d",d);
        break;
        case 12:
        p=1;
        printf("Enter the Hexadecimel number.\n");
        scanf("%s",&hexa);
        len = strlen(hexa);
        printf(" the Octal number is\n");
        for(i=len-1;i>=0;i--){
            if(hexa[i]>='0'&&hexa[i]<='9'){
                d += (hexa[i]-48)*p;
                p*=16;
            }
            else{
                d += (hexa[i]-55)*p;
                p*=16;
            }
        }
        p=1;
            rem=0;
            while(d != 0){
                rem=d%8;
                o+=rem*p;
                d/=8;
                p*=10;
            }
            printf("%d\n",o);


        break;

        default : printf( "Enter the valid Oparation.\n");
        break;
    }

    return 0;
}

