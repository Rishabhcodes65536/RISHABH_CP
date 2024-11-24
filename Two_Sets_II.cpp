#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int t_sum = (n * (n + 1)) / 2;
    if(t_sum&1){
        cout << 0 << endl;
        return 0;
    }
    int w = t_sum / 2;
    vector<int> dp(w + 2, 0),ndp(w+2,0);
    dp[0] = 1;
    for (int u = 1; u <= n;u++){
        for (int i = 1; i <= w; i++)
        {
            ndp[i] = dp[i];
            if(i-u>=0){
                ndp[i] += dp[i - u];
                ndp[i] %= M;
            }
        }
        dp = ndp;
        // ndp = vector<int>(w + 2, 0);
        for (int i = 0; i < ndp.size();i++){
            // cout << dp[i] << " ";
            ndp[i] = 0;
        }
        // cout << endl;
    }
    cout << dp[w] << endl;
}