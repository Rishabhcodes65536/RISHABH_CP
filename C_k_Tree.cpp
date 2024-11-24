#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int main(){
    int n, k, d;
    cin >> n >> k >> d;
    vector <vector <vector<long long>>> dp(n+1,vector <vector <long long>> (n+1,vector <long long> (2,0)));
    dp[0][0][0] = 1;
    // dp[0][0][1] = 1;
    for (int j = 1; j <= n ;j++){
        for (int i = 1; i <= n;i++){
            for (int kk = 1; kk <= min(i,k);kk++){
                if(kk>=d){
                    dp[i][j][kk >= d] += dp[i - kk][j-1][0];
                    dp[i][j][kk >= d] %= M;
                    // dp[i][j][1] += dp[i - kk][j - 1][0];
                    dp[i][j][1] += dp[i - kk][j - 1][1];
                    dp[i][j][1] %= M;
                }
                else{
                    dp[i][j][0] += dp[i - kk][j-1][0];
                    dp[i][j][0] %= M;
                    dp[i][j][1] += dp[i - kk][j - 1][1];
                    dp[i][j][1] %= M;
                }
            }
        }
    }
    long long res = 0;
    for (int j = 1; j <= n;j++){
        res+=dp[n][j][1];
        res %= M;
    }
    cout << res << endl;
}