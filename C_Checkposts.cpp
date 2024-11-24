#include <bits/stdc++.h>
using namespace std;


#define int long long

const int M = 1e9 + 7;



class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int> &vis, vector<int> adjT[], vector<int> &component)
    {
        vis[node] = 1;
        component.push_back(node); 
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT, component);
            }
        }
    }

public:
    vector<vector<int>> kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        fill(vis.begin(), vis.end(), 0); 
        vector<vector<int>> sccs;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                vector<int> component;
                dfs3(node, vis, adjT, component);
                sccs.push_back(component);
            }
        }
        return sccs;
    }
};

signed main()
{

    int n;
    cin >> n;
    int w[n+3];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int edges;
    cin >> edges;
    vector<int> adj[n+3];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    Solution obj;
    vector <vector <int>> components = obj.kosaraju(n, adj);
    // for(auto &y:components){
    //     for(auto &z:y){
    //         // cout<<z<<" ";
    //     }
    //     cout<<endl;
    // }
    int res = 1,mincost=0;
    for(auto &q:components){
        map<int, int> mp;
        for(auto &r:q){
            mp[w[r]]++;
        }
        res = (res*mp.begin()->second)%M;
        mincost += mp.begin()->first;
        // mincost %= M;
    }
    cout << mincost << " " << res << endl;
    return 0;
}
