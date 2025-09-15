#include <stdio.h>
void Rhombus();
void countBits();
void convertFrom20ToDec();
void checkIfPowerOf2();
void binaryAdd();
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
                checkIfPowerOf2();
                break;
            case 5:
                countBits();
                break;
            case 6:
                binaryAdd();
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
void checkIfPowerOf2() {
    unsigned int n;
    printf("Enter a number:\n");
    scanf("%u", &n);
    printf("%u %s a power of 2\n",
           n,
           (n > 0 && (n & (n - 1)) == 0) ? "is" : "is not");

}
#include <stdio.h>

void binaryAdd() {
    int carry,a=0,b=0;
    printf("Enter two numbers:\n");
    scanf(" %d %d",&a,&b);
    while (b != 0) {
        // carry now contains common set bits of a and b
        carry = a & b;

        // sum of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // carry is shifted by one so that adding it to a gives the required sum
        b = carry << 1;

    }

    printf("%d\n", a);
}

void countBits() {
    int a,b,x,count = 0;
    printf("Enter two numbers:\n");
    scanf(" %d %d",&a,&b);
    x= a^b;
    while(x) {
        x= x&(x-1);
        count++;
    }
    printf("There are %d different bits\n",count);
}