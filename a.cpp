#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// stack是基于deque实现的  相当于  deque双端队列  封闭了一端

// queue是基于deque实现的  相当于  deque双端队列  一段禁止入， 一段禁止出
int main() {
    //  构造
    // queue<int> q1 = {1,2,3,4};    //error
    // queue<int> q2(10);            //error
    queue<int> q3;

    vector<int> v1 = {1, 2, 3, 4, 5}; // 1,2,3,4,5依此入栈
    queue<int, vector<int>> q4(v1);

    list<int> l1 = {1, 2, 3, 4, 5};
    queue<int, list<int>> q5(l1);
    cout << endl << q5.front() << endl;
    cout << "------------\n";
    while (!q4.empty()) {
        cout << q4.front() << ' ';
        q4.pop();
    }

    cout << "------------\n";
    deque<int> d1 = {1, 2, 3, 4, 5};
    queue<int, deque<int>> q6(d1);
    queue<int> q7(d1); //用queue 为 stack  初始化时 deque可省  因为queue是基于deque实现的, 默认以deque方式构造

    // q4 = q5;  构造相同才能赋值
    q7 = q6;

    queue<int> q8;
    q8.push(3);
    q8.push(4);
    queue<int> q9;
    q9 = q8;

    // print_queue;
    vector<int> v2;
    while (!q9.empty()) {
        v2.push_back(q9.front());
        q9.pop();
    }
    for (auto tmp : v2) cout << tmp << ",";
    cout << endl;

    // q9 = d1;  // queue = deque 不可以
    // d1 = q9;  // deque = queue 不可以
    q9 = q6; // queue = queue<int, deque<int>>  可以
    q6 = q9; // queue<int, deque<int>> = queue

    //  取值
    q9.front();
    q9.back();

    q9.push(3); //尾进
    q9.emplace(3);
    q9.pop(); //头出

    q9.empty();
    q9.size();
    q9.swap(q6);

    return 0;
}
