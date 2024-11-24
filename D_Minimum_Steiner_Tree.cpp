// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> vec(m);
//     vector<vector<int>> g(n + 1);
//     for (int i = 0; i < n-1;i++){
//         int u, v;
//         cin >> u >> v;
//         u--, v--;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for (int q = 0; q < m;q++){
//         cin >> vec[q];
//         vec[q]--;
//     }
//     int hh = ceil(log2(n));
//     vector<vector<int>> dp(n, vector<int>(hh + 1, 0));
//     vector<int> in(n + 1), ou(n + 1);
//     int timer = 0;
//     function<void(int, int)> dfs = [&](int v, int p)
//     {
//             in[v] = ++timer;
//             dp[v][0] = p;
//             for (int x = 1; x <= hh;x++){
//                 dp[v][x] = dp[dp[v][x - 1]][x - 1];
//             }
//             for (auto &f : g[v])
//             {
//                 if (f != p)
//                 {
//                     dfs(f, v);
//                 }
//             }
//             ou[v] = ++timer;
//     };
//     dfs(0, 0);
//     auto ispossible = [&](int u, int v) -> bool
//     {
//         return in[u] <= in[v] && ou[u] >= ou[v];
//     };
//     auto lca = [&](int u, int v) -> int
//     {
//         if(ispossible(u,v))
//         {
//             return u;
//         }
//         if(ispossible(v,u))
//         {
//             return v;
//         }
//         for (int i = hh; i >= 0;i--)
//         {
//             if(!ispossible(dp[u][i],v))
//             {
//                 u = dp[u][i];
//             }
//         }
//         return dp[u][0];
//     };

//     int common_lca = vec[0];
//     for (int i = 1; i < vec.size();i++){
//         int r = lca(common_lca, vec[i]);
//         common_lca = r;
//     }
//     // cout << common_lca << endl;
    
// }



#include <bits/stdc++.h>

using namespace std;

int F;

int main(){
        int n, m;
        cin >> n >> m;
        vector<int> vec(m);
        F = m;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n-1;i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int q = 0; q < m;q++){
            cin >> vec[q];
            vec[q]--;
        }
        set<int> st;
        for(auto &r:vec){
            st.insert(r);
        }
        int flag = 0,x=0;
        function<int(int, int)> dfs = [&](int u, int p) -> int
        {
            int z = 0;
            if (st.count(u)){
                z++;
            }
            for (auto &v: g[u]){
                if(v!=p){
                    z += dfs(v, u);
                }
            }
            if(z==0 || flag){
                // cout << u << " " << flag<<" "<<z<< endl;
                x++;
            }
            if(z==m){
                flag = 1;
            }
            return z;
        };
        dfs(0, 0);
        // cout << x << endl;
        cout << n - x << endl;
}