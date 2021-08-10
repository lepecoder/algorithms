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
    double d = 3.2;
    int x, y;
    x = 1.2;
    y = (x + 3.8) / 5.0;
    printf("%d\n", d * y);

    return 0;
}