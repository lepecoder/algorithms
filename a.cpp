#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    int a[] = { 1, 2, 3, 4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    for_each(v.begin(), v.end(), [](int str) {cout << str << endl; });
    return 0;
}