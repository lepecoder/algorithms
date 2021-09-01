#include <condition_variable>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
using namespace std;
class ZeroAndEvenOdd {
  private:
    bool ze;
    bool other;
    int n;
    int k;
    std::condition_variable cv;
    std::mutex mtx;

  public:
    ZeroAndEvenOdd(int m) : ze(true), other(true), n(m), k(1) {}

    // printNumber(x) outputs "x", where x is an integer.
    // zero通知even和odd
    void printZero(std::function<void(int)> printNumber) {
        //待实现
        while (true) {
            if (k >= n) break;
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&] { return ze; });
            other = !other;
            ze = false;
            printNumber(0);
            lk.unlock();
            cv.notify_all();
        }
    }

    void printEven(std::function<void(int)> printNumber) {
        //待实现
        while (true) {
            if (k >= n) break;
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&] { return other && !ze; });
            ze = true;
            printNumber(k++);
            lk.unlock();
            cv.notify_one();
        }
    }

    void printOdd(std::function<void(int)> printNumber) {
        //待实现
        while (true) {
            if (k >= n) break;
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&] { return !other && !ze; });
            ze = true;
            printNumber(k++);
            lk.unlock();
            cv.notify_one();
        }
    }
};

void printNumber(int i) { std::cout << i; }

int main(int argc, char **argv) {
    int n = 5;
    // std::cin >> n;
    ZeroAndEvenOdd zeo(n);
    std::thread th1 = std::thread(std::bind(&ZeroAndEvenOdd::printZero, &zeo, std::placeholders::_1), printNumber);
    std::thread th2 = std::thread(std::bind(&ZeroAndEvenOdd::printEven, &zeo, std::placeholders::_1), printNumber);
    std::thread th3 = std::thread(std::bind(&ZeroAndEvenOdd::printOdd, &zeo, std::placeholders::_1), printNumber);
    th1.join();
    th2.join();
    th3.join();

    std::cout << std::endl;
    return 0;
}
