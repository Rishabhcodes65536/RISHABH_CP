#include <bits/stdc++.h>

using namespace std;
#define int long long

const int M = 1e9 + 7;


signed main(){

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    vector<int> ndp = dp;
    for (int j = 0; j < n; j++) {
        for (int i = v[j]; i <= x;i++){
            if(i-v[j]<0){
                continue;
            }
            dp[i] += dp[i - v[j]];
            dp[i] %= M;
        }
        // dp = ndp;
        // for(int )
        // cout << dp[i] << endl;
    }
    cout << dp[x] << endl;
}

//trans


//sum+v[i],i
//sum i+1