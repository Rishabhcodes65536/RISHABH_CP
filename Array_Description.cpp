#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> dp(m + 2, 1),ndp(m+1,0);
    dp[0] = 0;
    dp[m + 1] = 0;
    for (int i = 0; i < n;i++){
        if(arr[i]>0){
            ndp[arr[i]] += dp[arr[i]];
            if(i>0){
            ndp[arr[i]] += dp[arr[i]-1];
            ndp[arr[i]] %= M;
            ndp[arr[i]] += dp[arr[i]+1];
            ndp[arr[i]] %= M;
            }
        }
        else{
            if(i>0){
                for (int j = 1; j <= m;j++){
                    ndp[j] += dp[j - 1];
                    ndp[j] %= M;
                    ndp[j] += dp[j];
                    ndp[j] %= M;
                    ndp[j] += dp[j + 1];
                    ndp[j] %= M;
                }
            }
            else{
                ndp = dp;
            }
        }
        for (int j = 1; j <= m;j++){
            dp[j] = ndp[j];
            ndp[j] = 0;
        }
    }
    int res = 0;
    for (int i = 1; i <= m;i++){
        res += dp[i];
        res %= M;
    }
    cout << res << endl;
}

//1 1 1
//1 1 2
//1 2 1
//1 2 2
//1 2 3
//2 1 1
//2 1 2
//2 2 1
//2 2 2
//2 2 2
//2 3 2
//2 3 3
//3 2 1
//3 2 2
//3 2 3
//3 3 2
//3 3 3