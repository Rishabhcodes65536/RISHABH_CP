#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int res = 0, x = 5 ;
    while(n/x>=1){
        res += (n / x);
        x *= 5;
    }
    // cout << (n-4) / 5 + (n/10) << endl;
    cout << res << endl;
}

//20 * 19 * 18 * 17