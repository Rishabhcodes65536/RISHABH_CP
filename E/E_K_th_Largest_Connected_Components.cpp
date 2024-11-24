#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

class DSU
{
    public:
    vector<int> parent, rank;
    map<int, indexed_set> mp;
    DSU(int N)
    {
        parent.resize(N+2);
        rank.resize(N+2, 1);
        for (int i = 1; i <= N; i++){
            parent[i] = i;
            mp[i].insert(i);
        }
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (rank[a] == rank[b])
        {
            rank[a]+=rank[b];
            parent[b] = a;
            for(auto &y:mp[b]){
                mp[a].insert(y);
            }
            // mp[b].clear();
        }
        else if (rank[a] > rank[b])
        {
            parent[b] = a;
            rank[a] += rank[b];
            for (auto &y : mp[b])
            {
                mp[a].insert(y);
            }
            // mp[b].clear();
        }
        else{
            parent[a] = b;
            rank[b] += rank[a];
            for (auto &yy : mp[a])
            {
                mp[b].insert(yy);
            }
            // mp[a].clear();
        }

    }
    
    int get_k_compo(int u,int k){
        int z = find_set(u);
        int sz = mp[z].size();
        if (sz - k < 0)
        {
            return -1;
        }
        // cout << *mp[z].find_by_order(sz - k) << endl;
        return *mp[z].find_by_order(sz - k);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<indexed_set> ves(n + 2);
    map<int, int> mp;
    DSU dsu(n);
    int k = 0;
    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            dsu.union_sets(x, y);
        }
        else
        {
            // if (!mp[x])
            // {
            //     if (y == 1)
            //     {
            //         cout << x << endl;
            //     }
            //     else
            //     {
            //         cout << -1 << endl;
            //     }
            //     continue;
            // }
            // int sz = ves[mp[x]].size();
            // if (sz - y < 0)
            // {
            //     cout << -1 << endl;
            //     continue;
            // }
            cout << dsu.get_k_compo(x,y) << endl;
        }
    }
}