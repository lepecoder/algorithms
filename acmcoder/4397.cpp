#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    int n;
    cin >> n;
    cin>> a>>b;
    int res = 0;
    int t;
    for (int i=0;i<n;i++){
        if(a[i]==b[i]){
            t=0;
        }else{
            t=1;
        }
        res = 2*res+t;
    }
    cout << res;
    return 0;
}