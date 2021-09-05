#include <bits/extc++.h>

using namespace std;

string buff;
bool isempty = true;
bool iseof = false;
mutex mtx;
condition_variable cv;

void read1() {
    ifstream infile("./in.txt");
    string tmp;
    while (!infile.eof()) {
        getline(infile, tmp);
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&] { return isempty == true; });
        buff = tmp;
        cout << "read " << buff << endl;
        isempty = false;
        lk.unlock();
        cv.notify_one();
    }
    iseof = true;
    buff.clear();
    isempty = false;
    infile.close();
    cout << "read exit \n";
}

void write1() {
    ofstream outfile("./out.txt");
    string tmp;
    while (true) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&] { return isempty == false; });
        outfile << buff << endl;
        cout << "write " << buff << endl;
        isempty = true;
        lk.unlock();
        cv.notify_one();
        // if (buff.empty()) break;
        if (iseof) break;
    }
    isempty = true;
    outfile.close();
    cout << "write exit \n";
}

int main() {
    //
    buff.clear();
    isempty = true;
    iseof = false;
    int a = 1;
    std::thread t1(read1);
    std::thread t2(write1);
    t1.join();
    t2.join();
    return 0;
}