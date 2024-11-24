#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> g[i][j];
            if(i-1>=0){
                g[i][j] |= g[i-1][j];
            }
        }
    }
    vector < vector<int>> rev(m,vector <int> (n));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            rev[j][i] = g[i][j];
        }
    }
    while(q--){
    int req;
    cin >> req;
    int lb = 0, ub = n - 1;
    for (int u = 0; u < req;u++){
        int reg, val;
        char c;
        cin >> reg >> c >> val;
        reg--;
        if(c=='>'){
            int ubb = upper_bound(rev[reg].begin(), rev[reg].end(), val) - rev[reg].begin();
            lb = max(lb, ubb);
        }
        else{
            int lbb = lower_bound(rev[reg].begin(), rev[reg].end(), val) - rev[reg].begin() - 1;
            ub = min(ub, lbb);
        }
    }
    if(lb>ub){
        cout << -1 << endl;
    }
    else{
        cout << lb + 1 << endl;
    }
    }
}