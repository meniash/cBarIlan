#include <stdio.h>
//print hello world program and check that everything is working in IDE and no warning pop up
int main(int argc, char* argv[]) {
printf("Hello, World!\n");
printf("Program name: %s\n", argv[0]);
for (int i = 1; i < argc; i++) {
    printf("Arg %d: %s\n", i, argv[i]);
}
return 0;
}