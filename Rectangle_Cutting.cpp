// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     if(n>m){
//         swap(n, m);
//     }
//     vector<vector<int>> dp(max(n,m) + 3, vector<int>(max(n,m) + 3,-1));
//     function<int(int, int)> recursive = [&](int u, int v) -> int {
//         if(u==v){
//             return 0;
//         }
//         assert(u >= 1 && v >= 1 && u<=max(n,m) && v<=max(n,m));
//         if(u>v){
//             swap(u, v);
//         }
//         if(dp[u][v]!=-1){
//             return dp[u][v];
//         }
//         int res = 1e6;
//         for (int i = 1; i < v;i++){
//             res = min(res, 1 + recursive(u, i) + recursive(u, v - i));
//         }
//         for (int i = 1; i < u; i++)
//         {
//             res = min(res, 1 + recursive(v, i) + recursive(u-i, v));
//         }
//         return dp[u][v] = res;
//     };
//     cout << recursive(n, m);
// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (n > m)
        swap(n, m);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                int minCuts = INT_MAX;
                for (int k = 1; k < j; ++k)
                {
                    minCuts = min(minCuts, 1 + dp[i][k] + dp[i][j - k]);
                }
                for (int k = 1; k < i; ++k)
                {
                    minCuts = min(minCuts, 1 + dp[k][j] + dp[i - k][j]);
                }
                dp[i][j] = minCuts;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
