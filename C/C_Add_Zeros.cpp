#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int tt;
    cin >> tt;
    for (int t = 0; t < tt;t++){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> v(n);
        for (int i = 0; i < n;i++){
            v[i] = a[i]+i;
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n;i++){
            mp[v[i]].push_back(i);
        }
        int ans = 0;
        priority_queue<vector<int>> q;
        for (int i = 1; i < n;i++){
            if(v[i]==n){
                q.push({v[i],i});
            }
        }
        int res = n;
        vector<int> vis(n, 0);
        while(!q.empty()){
            auto z = q.top();
            q.pop();
            int a = z[1];
            // int b = z[1];
            int c = z[0];
            if(c<vis[a]){
                continue;
            }
            vis[a] = c;
            res = max(res, c + a);
            if(mp.count(c+a)){
                for(auto &g:mp[c+a]){
                    if(!vis[g]){
                        q.push({c + a,g});
                    }
                }
            }
        }
            // for(auto &y:v){
            //     cout << y << " ";
            // }
            // cout << endl;
        cout << res<<endl;
    }
}