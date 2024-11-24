#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
    int n, a, b, c, d, p, q, y;
    cin >> n >> a >> b >> c >> d >> p >> q >> y;
    vector<int> v(n+1);
    map<int, int> mp;
    for (int i = 1; i <= n;i++){
        cin >> v[i];
        mp[i] = v[i];
    }
    int op1 = abs(mp[b] - mp[a])*p;
    int op2 = INT64_MAX;
    if(abs(mp[a]-mp[c])*p <=y){
    op2 = max(abs(mp[a] - mp[c]) * p, y) + (abs(mp[c] - mp[d]) * q) + (abs(mp[d] - mp[b]) * p);
    }
    // cout << op1 << " " << op2 << endl;
    cout << min(op1, op2) << endl;
    }
}

//1 se 3 jana hai

//3 second
//9+2+3

//14