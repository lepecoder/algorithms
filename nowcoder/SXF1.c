#include <stdio.h>

// const int maxN = 100000;
int food[10000];
typedef struct tool {
    int food;
    int time;
} tool;

int main() {
    //
    int n = 0;
    int t;
    while (scanf("%d", &t)) {
        if (t == 7)
            break;
        else
            food[n++] = t;
    }
    // for (int i = 0; i < n; i++) { printf("%d ", food[i]); }
    tool tools[3];
    for (int i = 0; i < 3; i++) {
        tools[i].food = 0;
        tools[i].time = 0;
    }
    int res = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        res += 15; // 每种食物需要15分钟
        // 检查是否需要替换厨具
        int j, mintime = 100000, minidx = 0;
        int bs = 0;
        for (j = 0; j < 3; j++) {
            if (tools[j].food == food[i]) { // 食物相同，不需要替换
                bs = 1;
                tools[j].time = i + 1;
                break;
            }
            if (tools[j].time < mintime) {
                mintime = tools[j].time;
                minidx = j;
            }
        }
        if (bs == 0) { //需要替换
            tools[minidx].food = food[i];
            tools[minidx].time = i + 1;
            res += 6;
        }
    }
    printf("%d", res - 18);

    return 0;
}