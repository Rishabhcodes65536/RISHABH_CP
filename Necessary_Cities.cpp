#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> tin(n), dp(n);
    vector<int> vis(n, 0),res;
    int time = 0;
    vector<pair<int, int>> bridge;
    vector <int> is_art(n,0);
    
    function<void(int, int)> dfs = [&](int u, int p)
    {
        vis[u] = 1;
        tin[u] = dp[u] = ++time;
        int child = 0;
        for (auto v : g[u])
        {
            if (v != p)
            {
                if (vis[v])
                {
                    dp[u] = min(dp[u], tin[v]);
                }
                else
                {
                    dfs(v, u);
                    dp[u] = min(dp[u], dp[v]);
                    if (dp[v] >= tin[u])
                    {
                        if(!is_art[u] && p!=-1)
                        {
                            res.push_back(u);
                            is_art[u] = 1;
                        }
                    }
                    child++;
                }
            }
        }
        if(p==-1 && child>1){
            if(!is_art[u]){
                res.push_back(u);
                is_art[u] = 1;
            }
        }
    };
    dfs(0, -1);
    cout << res.size() << endl;
    for (auto &h : res)
    {
        cout << h+1 <<" ";
    }
    cout << endl;
}