#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;
        s--, t--;
        vector<vector<int>> g(n + 1);
        vector<int> vec(k);
        for (int i = 0; i < k;i++){
            cin >> vec[i];
            vec[i]--;
        }
        for (int i = 0; i < m;i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> v1;
        auto bfs = [&](int ss) -> vector<int>
        {
            queue<int> que;
            vector <int> dp(n,INT64_MAX);
            que.push(ss);
            dp[ss] = 0;
            while(!que.empty()){
                auto r=que.front();
                que.pop();
                for(auto &vv:g[r]){
                    if(dp[vv]>1+dp[r]){
                        dp[vv] = 1 + dp[r];
                        que.push(vv);
                    }
                }
            }
            return dp;
        };
        vector <int> dis1=bfs(s);
        vector <int> dis2=bfs(t);

        for(auto &y:dis1){
            cout << y << " ";
        }
        cout << endl;
        for(auto &y:dis2){
            cout << y << " ";
        }
        cout << endl;
    }
}