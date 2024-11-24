#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector <vector <int>> dp(n+1,vector <int> (m+1,INT_MAX));
    // dp[0][0] = 0;
    for (int i = 0; i <= n;i++){
        dp[i][0] = i;
    }
    for (int j = 0; j <= m;j++){
        dp[0][j] = j;
    }
    int res = INT_MAX;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if (s[i] == t[j]){
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
            dp[i + 1][j + 1] = min({dp[i + 1][j+1],1+dp[i][j+1],1+dp[i+1][j],1+dp[i][j]});
        }
    }
    // for (int i = 0; i <= n;i++){
    //     for (int j = 0; j <= m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;
}