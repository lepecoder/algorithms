// #include <bits/stdc++.h>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>
using namespace std;

const int threadsN = 3;
const int N = 100;

mutex mtx;
condition_variable cv[threadsN];
bool flags[threadsN];
int n = 0;

void f(int i) {
    // 激活第i个线程
    const int next = (i + 1) % threadsN;
    while (true) {
        unique_lock<mutex> lk(mtx);
        // cv[i].wait(lk, [i] { return flags[0]; });
        if (n <= N) { cout << "thread " << i << ": " << n++ << endl; }
        flags[i] = false;
        flags[next] = true;
        lk.unlock();
        sleep(1);
        // cv[next].notify_one();
        if (n > N) break;
    }
}

int main() {
    //
    flags[0] = true;
    vector<std::thread> vec = vector<thread>(threadsN);
    for (int i = 0; i < threadsN; i++) {
        vec.at(i) = thread(f, i);
        // vec.emplace_back(f, i);
    }
    for (auto &t : vec) { t.join(); }

    return 0;
}