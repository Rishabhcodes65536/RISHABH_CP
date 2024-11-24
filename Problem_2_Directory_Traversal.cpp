#include  <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> sizes(n, 0);
    vector<vector<int>> g(n + 1);
    int root = -1;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        sizes[i]=s.size();
        int m;
        cin >> m;
        if(s=="bessie"){
            root = i;
        }
        for(int j=0;j<m;j++){
            int u;
            cin >> u;
            u--;
            g[u].push_back(i);
            g[i].push_back(u);
        }
    }
    vector<int> dp1(n, 0), dp2(n, 0);

    function<int(int, int)> dfs = [&](int u, int p) -> int
    {
        int ans = 0;
        for(auto &w:g[u])
        {
            if(w != p)
            {
                ans += sizes[w]*(g[w].size()-1 +g[w].size()>1 ? (1):(0)) + dfs(w, u);
            }
        }
        return dp1[u] = ans;
    };
}