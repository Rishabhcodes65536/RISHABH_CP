#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> queries(t);
    int max_y = 0;

    for (int i = 0; i < t; i++)
    {
        cin >> queries[i];
        max_y = max(max_y, queries[i]);
    }

    int max_power = 0;
    while ((1LL << max_power) <= max_y)
    {
        max_power++;
    }

    vector<long long> dp(max_power + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= max_power; i++)
    {
        dp[i] = (dp[i - 1] * 2 + 1) % MOD;
    }

    for (int y : queries)
    {
        if ((y & (y - 1)) != 0 || y == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            int power = __builtin_ctz(y) + 1;
            cout << dp[power] << "\n";
        }
    }

    return 0;
}
