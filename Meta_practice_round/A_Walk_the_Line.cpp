#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("walk_the_line_input.txt", "r", stdin);
    freopen("walk_the_line_output.txt", "w", stdout);
    int ttt;
    cin >> ttt;
    for (int tt = 1; tt <= ttt; tt++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        long long mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            long long u;
            cin >> u;
            v.push_back(u);
            mini = min(mini, u);
        }
        long long right = max(n - 1, 1);
        long long left = max(n - 2, 0);
        if (mini * right + mini * left <= k)
        {
            printf("Case #%d: YES\n", tt);
        }
        else
        {
            printf("Case #%d: NO\n", tt);
        }
    }
}