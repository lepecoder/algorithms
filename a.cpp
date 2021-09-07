#include <atomic>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>
#include <utility>
#include <windows.h>
using namespace std;

void f1() {
    int n = 5;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << n << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void read() {
    ifstream infile("./in.txt");
    string tmp;
}

void f2(int &n) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    // locale::global(locale(""));
    // std::locale::global(std::locale(""));
    // std::setlocale(LC_ALL, "en_US.UTF-8");
    // wstring s = wstring_conver "你好";
    SetConsoleOutputCP(CP_UTF8);
    cout << "你好" << endl;
    // wcout << s << endl;
    // int n = 0;
    // std::thread t1;     // t1 is not a thread
    // std::thread t2(f1); // pass by value
    // std::thread tt(read);
    // std::thread t3(f2, std::ref(n)); // pass by reference
    // std::thread t4(std::move(t3));   // t4 is now running f2(). t3 is no longer a thread
    // t2.join();
    // t4.join();
    // std::cout << "Final value of n is " << n << '\n';
}