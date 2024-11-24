#include <bits/stdc++.h>

using namespace std;

#define ll long long

int dp[1002][2050];
const int M = 1e9 +7;
int N;

void gen(int &curr, int nxt, int it, vector<int> &masks)
{
    if (it == N)
    {
        masks.push_back(nxt);
        return;
    }

    if (it + 1 < N && (((1 << it) & curr) == 0) && (((1 << (it + 1)) & curr) == 0))
    {
        gen(curr, nxt, it + 2, masks);
    }
    if (((1 << it) & curr) == 0)
    {
        gen(curr, nxt + (1 << it), it + 1, masks);
    }
    if (((1 << it) & curr) != 0)
    {
        gen(curr, nxt, it + 1, masks);
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    N = n;
    memset(dp, -1, sizeof(dp));
    // vector<int> masks;

    function<int(int, int)> dfs = [&](int j, int msk) -> int
    {
        if(j==m)
        {
            return (msk == 0 ? (1):(0));
        }
        if(dp[j][msk]!=-1)
        {
            return dp[j][msk];
        }
        // masks.clear();
        vector<int> masks;
        gen(msk, 0, 0,masks);
        int res = 0;
        for(auto r:masks)
        {
            // for(auto &y:masks){
            //     cout << y << " ";
            // }
            // cout << endl;
            res += dfs(j + 1, r);
            res %= M;
        }
        return dp[j][msk] = res;
    };
    int ans = dfs(0, 0);
    cout << ans << endl;
}