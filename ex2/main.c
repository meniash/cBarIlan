#include <stdio.h>
void Rhombus();
int main(){
    int userParam = 0;
    char c = '\0';
    do{
        printf("Choose an option:\n1. Rhombus\n2. Base 20 to Decimal\n3. Base to Decimal\n"
            "4. Pow2\n5. Different bits\n6. Add\n7. Multiply\n0. Exit\n");
        if (scanf("%d", &userParam) != 1) {
            printf("unknown error happened.program exiting....\n");
            userParam = 0;
        }
        switch(userParam){
            case 1:
                Rhombus();
            break;
            case 2:
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
        while ((c = getchar()) != '\n' && c != EOF) { }
    }while(userParam != 0);
    return 0;
}