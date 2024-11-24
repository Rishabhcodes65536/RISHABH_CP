#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[5002][5002][2];

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // memset(dp, -1e18, sizeof(dp));
    for (int i = 0; i < 5002; i++)
    {
        for (int j = 0; j < 5002; j++)
        {
            dp[i][j][0] = INT64_MIN;
            dp[i][j][1] = INT64_MIN;
        }
    }
    dp[0][n - 1][0] = 0;

    // for

    // cout<<dp[0][0][0]<<endl;
    // for (int i = 1; i <= n;i++){

    // }
    // recursive

    // vector <vector <vector <int>>> dp(n+1,vector <vector <int>> (n+1,vector <int> (2,INT64_MIN)));

    // function<int(int, int, int)> dfs = [&](int u, int v, int turn) -> int
    // {
    //     if (u > v)
    //     {
    //         return 0;
    //     }
    //     if (dp[u][v][turn] != INT64_MIN)
    //     {
    //         // cout<<"hehehe"<<endl;
    //         // cout<<u<<" "<<v<<" "<<turn<<endl;
    //         // cout<<dp[u][v][turn]<<endl;
    //         return dp[u][v][turn];
    //     }

    //     // left se
    //     int incl, incr;

    //     incl = (turn == 0 ? (a[u]) : (0)) + (1LL) * (dfs(u + 1, v, turn ^ 1));
    //     incr = (turn == 0 ? (a[v]) : (0)) + (1LL) * (dfs(u, v - 1, turn ^ 1));

    //     if (!turn)
    //         return dp[u][v][turn] = max(incl, incr);

    //     else
    //         return dp[u][v][turn] = min(incl, incr);
    // };
    // int res = dfs(0, n - 1, 0);
    cout << res << endl;
}
