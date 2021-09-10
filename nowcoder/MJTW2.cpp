#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int needToTrain, minPulse, maxPulse, trainChange, restChange;
    cin >> needToTrain >> minPulse >> maxPulse >> trainChange >> restChange;
    int Pulse = minPulse;
    int trainTime = 0; // 训练时间
    int Time = 0;      // 总时间
    if (trainChange > (maxPulse - minPulse)) {
        cout << -1;
        return 0;
    }
    while (trainTime < needToTrain) {
        if (Pulse + trainChange <= maxPulse) {
            // 可以训练
            Pulse += trainChange;
            trainTime++;
        } else {
            // 需要休息
            Pulse -= restChange;
            Pulse = max(Pulse, minPulse);
        }
        Time++;
    }
    cout << Time;

    return 0;
}