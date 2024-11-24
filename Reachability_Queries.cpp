#include <bits/stdc++.h>
using namespace std;

const int N = 50001;
bitset<N> bi[N];

#define disp(v)                                         \
    for (int i = 0; i < v.size(); i++)                  \
    {                                                   \
        cout << v[i] << " ";                            \
    }                                                   \
    cout << endl;                                       \
    
vector<int> vis,roots;

void dfs(int u, vector<int> &x, vector<vector<int>> &gra)
{
    vis[u] = 1;
    for (auto &h : gra[u])
    {
        if (!vis[h])
        {
            dfs(h, x, gra);
        }
    }
    x.push_back(u);
}

void dfs2 (int u, vector<int> &x, vector<vector<int>> &gra)
{
    vis[roots[u]] = 1;
    for (auto &h : gra[roots[u]])
    {
        if (!vis[roots[h]])
        {
            dfs2(h, x, gra);
        }
    }
    x.push_back(roots[u]);
}

void dfs3(int u, vector<vector<int>> &gra)
{
    vis[roots[u]] = 1;
    bi[roots[u]][roots[u]]=1;
    for (auto &h : gra[roots[u]])
    {
        if (!vis[roots[h]]){
            dfs3(h, gra);
        }
        bi[roots[u]] |= bi[roots[h]];
    }
    // x.push_back(roots[u]);
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m,q;
    cin >> n >> m>>q;
    vector<vector<int>> g(n), g_(n);
    vector<int> out(n), in(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g_[v].push_back(u);
        out[u]++;
        in[v]++;
        // outdeg[u].push_back(u);
    }
    // vector<bool> vis(n, false);
    vis.clear();
    vis.resize(n, 0);
    vector<int> vec;
    for (int i = 0; i < n;i++){
        if(!vis[i])
            dfs(i, vec, g);
    }
    // disp(vec);
    reverse(vec.begin(), vec.end());
    vis.clear();
    vis.resize(n, 0);
    // disp(vis);
    // vector<int> roots(n, 0);
    roots.resize(n+2, 0);
    int k = 0;
    for(auto &y:vec){
        if(!vis[y]){
            vector<int> compo;
            dfs(y,compo,g_);
            // disp(compo);
            int root = k++;
            for(auto &u:compo){
                roots[u] = root;
                // bi[root].set(u);
            }
        }
    }
    // disp(roots);
    map<pair <int,int>, int> mp;
    vector<vector<int>> compo(n+3);
    for (int i = 0; i < n;i++){
        for(auto &h:g[i]){
            if(roots[h]!=roots[i] && !mp[{roots[i],roots[h]}]){
                compo[roots[i]].push_back(roots[h]);
                mp[{roots[i], roots[h]}]++;
            }
        }
    }
    vis.clear();
    vis.resize(n, 0);
    vec.clear();
    vec.resize(0);

    //topo sort

  
    for (int i = 0; i < n;i++){
        if(!vis[i]){
            dfs(i, vec, compo);
        }
    }
    disp(vec);
    vis.clear();
    vis.resize(n, 0);

    // reverse(vec.begin(), vec.end());
    for(auto &z:vec){
        // bi[roots[z]][roots[z]] = 1;
        // for(auto &h:compo[z]){
        //     bi[roots[z]] |= bi[roots[h]];
        // }
        if(!vis[z]){
            dfs3(z, compo);
        }
    }


    for (int i = 0; i < q;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (bi[roots[a]][roots[b]]==1 ? "YES":"NO") << endl;
    }
}