#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    int dp[n + 1][32];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
        dp[i][0] = v[i];
    }
    for (int j = 1; j <= 31; j++)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    for (int g = 0; g < q; g++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        int u = x;
        for (int h = 31; h >= 0; h--)
        {
            if (y & (1 << h))
            {
                u = dp[u][h];
            }
        }
        cout << u + 1 << endl;
    }
}
