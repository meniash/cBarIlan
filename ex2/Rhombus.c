#include <stdio.h>
void Rhombus() {
    int sidesLength = 0,i = 0, j =0 ,k=0;
    printf("enter the sides length:\n");
    scanf("%d",&sidesLength);
    
    for(i=sidesLength;i>0;i--) {
        for(j=i;j>0;j--) {
            printf(" ");
        }
        printf("/");
        for(k=sidesLength - i; k>0 ;k--) {
            printf(" ");
        }
        printf("*");
        for(k=sidesLength - i; k>0 ;k--) {
            printf(" ");
        }
        printf("\\");
        printf("\n");
    }
    printf("|");
    for(i = sidesLength; i >0; i--) {
        printf(" ");
    }
    printf("+");
    for(i = sidesLength; i>0; i--) {
        printf(" ");
    }
    printf("|");
    printf("\n");
    for(i=1;i<=sidesLength;i++) {
        for(j=i;j>0;j--) {
            printf(" ");
        }
        printf("\\");
        for(k=sidesLength - i; k>0 ;k--) {
            printf(" ");
        }
        printf("*");
        for(k=sidesLength - i; k>0 ;k--) {
            printf(" ");
        }
        printf("/");
        printf("\n");
    }
}