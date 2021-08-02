#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TEXT 512
struct msg_st {
    long int msg_type;
    char text[MAX_TEXT];
};

int main() {
    int x;
    while (scanf("%d", &x) != EOF) { printf("%d\n", x); }
    printf("结束\n");

    return 0;
}