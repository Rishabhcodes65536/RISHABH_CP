// #include <bits/stdc++.h>

// using namespace std;
// #define int long long

// signed main(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> g(n + 1),g_(n+1);
//     vector<int> in(n+2,0);
//     for (int i = 0; i < m;i++){
//         int u, v;
//         cin >> v >> u;
//         u--, v--;
//         g[v].push_back(u);
//         g_[u].push_back(v);
//         in[u]++;
//     }
//     vector<int> res;
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int i = 0; i < n;i++){
//         if(in[i]==0){
//             pq.push(i);
//         }
//     }
//     while(!pq.empty()){
//         int r = pq.top();
//         pq.pop();
//         res.push_back(r+1);
//         for(auto &x:g[r]){
//             if(in[x]){
//                 in[x]--;
//                 if(in[x]==0){
//                     pq.push(x);
//                 }
//             }
//         }
//     }
//     for(auto &yy:res){
//         cout << yy << " ";
//     }
//     cout << endl;
// }

// #include <bits/stdc++.h>

// using namespace std;
// #define int long long

// signed main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> g(n + 1), g_(n + 1);
//     vector<int> in(n + 2, 0);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[v].push_back(u);
//         in[u]++;
//     }
//     vector<int> res;
//     priority_queue<int> pq;
//     for (int i = 1; i <= n; i++)
//     {
//         if (in[i] == 0)
//         {
//             pq.push(i);
//         }
//     }
//     while (!pq.empty())
//     {
//         int r = pq.top();
//         pq.pop();
//         res.push_back(r);
//         for (auto &x : g[r])
//         {
//             if (in[x])
//             {
//                 in[x]--;
//                 if (in[x] == 0)
//                 {
//                     pq.push(x);
//                 }
//             }
//         }
//     }
//     reverse(res.begin(), res.end());
//     for (auto &yy : res)
//     {
//         cout << yy << " ";
//     }
//     cout << endl;
// }

// Aur phir ye bhi
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1), g_(n + 1);
    vector<int> in(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        in[u]++;
    }
    vector<int> res;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            pq.push(-i);
        }
    }
    while (!pq.empty())
    {
        int r = -pq.top();
        pq.pop();
        res.push_back(r);
        for (auto &x : g[r])
        {
            if (in[x])
            {
                in[x]--;
                if (in[x] == 0)
                {
                    pq.push(-x);
                }
            }
        }
    }

    for (auto &yy : res)
    {
        cout << yy << " ";
    }
    cout << endl;
}