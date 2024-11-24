#include <bits/stdc++.h>

using namespace std;

#define int long long

map<array<int, 3>, int> mp;

int half;

long long res = 0;

int n, m, k;
void dfs1(int i,int j,int cnt,vector <vector <int>>& g,int xo){
    xo ^= g[i][j];
    if(cnt==half){
        mp[{i,j,xo}]++;
        return;
    }

    if(i+1<n){
        dfs1(i+1,j,cnt+1,g,xo);
    }
    if(j+1<m){
        dfs1(i, j + 1, cnt + 1, g, xo);
    }
}

void dfs2(int i, int j, int cnt, vector<vector<int>> &g, int xo)
{
    // xo ^= g[i][j];
    if (cnt == n+m-2-half)
    {
        res += mp[{i, j, xo^k}];
        return;
    }

    if (i-1 >=0)
    {
        dfs2(i - 1, j, cnt + 1, g, xo^g[i][j]);
    }
    if (j -1>=0)
    {
        dfs2(i, j - 1, cnt + 1, g, xo^g[i][j]);
    }
}

signed main(){
    int N, M, K;
    cin >> N >> M >>K;
    n = N, m = M, k = K;
    half = (N + M - 2) / 2;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    
    dfs1(0, 0, 0,g,0);
    dfs2(n-1, m-1, 0,g,0);

    cout << res << endl;
}

//n+m-2 total moves

//even hai 

