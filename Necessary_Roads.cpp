#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> tin(n), dp(n);
    vector<int> vis(n, 0);
    int time = 0;
    vector<pair <int,int>> bridge;
    function<void(int, int)> dfs = [&](int u, int p)
    {
        vis[u] = 1;
        tin[u] = dp[u] = ++time;

        for(auto v:g[u]){
            if(v!=p){
                if(vis[v]){
                    dp[u] = min(dp[u], tin[v]);
                }
                else{
                    dfs(v, u);
                    dp[u] = min(dp[u], dp[v]);
                    if(dp[v]>tin[u]){
                        if(u>v)
                            swap(u, v);
                        bridge.push_back({u, v});
                    }
                }
            }
        }
    };
    dfs(0, 0);
    cout << bridge.size() << endl;
    for(auto &h:bridge){
        cout << h.first+1 << " " << h.second+1 << endl;
    }
}