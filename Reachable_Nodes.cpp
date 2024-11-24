#include <bits/stdc++.h>
using namespace std;


const int N = 50001;
bitset<N> bi[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n),g_(n);
    vector<int> out(n);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g_[v].push_back(u);
        out[u]++;
        // outdeg[u].push_back(u);
    }

    queue<int> q;
    for (int i = 0; i < n;i++){
        if(out[i]==0){
            q.push(i);
        }
        bi[i].set(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : g_[u]){
            out[v]--;
            bi[v] |= bi[u];
            if(out[v]==0){
                q.push(v);

            }
        }
    }
    for(int i=0;i<n;i++){
        cout << bi[i].count() << " ";
    }
    cout << endl;
}