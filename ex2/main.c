#include <stdio.h>
void Rhombus();
void convertFrom20ToDec();
int main(){
    int userParam = 0;
    do{
        printf("Choose an option:\n1. Rhombus\n2. Base 20 to Decimal\n3. Base to Decimal\n"
            "4. Pow2\n5. Different bits\n6. Add\n7. Multiply\n0. Exit\n");
        if (scanf("%d", &userParam) != 1) {
            printf("unknown error happened.program exiting....\n");
            userParam = 0;
        }
        getchar();
        switch(userParam){
            case 1:
                Rhombus();
                break;
            case 2:
                convertFrom20ToDec();
                break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 0:
            break;
            default:
            printf("wrong option!\n");
                break;
        }
    }while(userParam != 0);
    return 0;
}
void convertFrom20ToDec() {
    char c = '\0';
    int num = 0,pow20=1,digit = 0,flag = 0;
    printf("Enter a reversed number in base 20:\n");
    do {
        c = getchar();
    } while (c == ' ' || c == '\t');
    while (c != '\n' && c != EOF) {
        if( c>='0' && c<='9') {
            digit = (c-'0');
        } else if(c>='a' && c<='j') {
            digit = (c-'a' + 10);
        } else if(c>='A' && c<='J') {
            digit = (c-'A' + 10);
        }else{
            printf("Error! %c is not a valid digit in base 20\n",c);
            flag = 1;
        }
        if(!flag) {
            digit *= pow20;
            num += digit;
            pow20 *= 20;
        }
        c = getchar();
    }
    if(!flag){
        printf("%d\n",num);
    }
}