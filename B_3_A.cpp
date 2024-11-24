#include <bits/stdc++.h>
using namespace std;

int binpow(int a,int b){
    if(b==0){
        return 1;
    }
    int r = 1;
    while(b>0){
        if(b&1){
            r = r*a ;
        }
        a = a * a;
        b >>= 1;
    }
    return r;
}

int main(){
    int n;
    cin >> n;
    vector<int> res;
    while(n>0){
        int h = log(n) / log(3);
        // cout << h << endl;
        n -= binpow(3, h);
        // cout << n << endl;
        res.push_back(h);
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}