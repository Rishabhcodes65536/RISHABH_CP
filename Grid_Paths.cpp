#include <bits/stdc++.h>

using namespace std;
#define int long long
const int M = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    vector<string> ves;
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        ves.push_back(s);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = (ves[0][0]=='.');   
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(i==0 && j==0 || ves[i][j]=='*')
                continue;
            
            if(i-1>=0){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= M;
            }
            if(j-1>=0){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= M;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}