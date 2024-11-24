#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ves;
    array<int, 5> dir = {-1, 0, 1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ves.push_back(s);
    }
    int hash_count = 0, res = INT_MAX;
    for(auto &z:ves){
        for(auto &c:z){
            if(c=='#'){
                hash_count++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            if (ves[i][j] == '#')
            {
                // hash_count++;
                bool flag = 0;
                ves[i][j] = '.';
                for (int l = 1; l < 5; l++)
                {
                    int x = i + dir[l - 1];
                    int y = j + dir[l];
                    if (x >= 0 && x < n && y >= 0 && y < m)
                    {
                        if (ves[x][y] == '#' && !flag)
                        {
                            int ans = 0;
                            vector<vector<int>> vis(n, vector<int>(m, 0));
                            function<void(int, int)> recursive = [&](int u, int v)
                            {
                                vis[u][v] = 1;
                                ans++;
                                for (int it = 1; it < 5; it++)
                                {
                                    int xx = u + dir[it - 1];
                                    int yy = v + dir[it];
                                    if(xx>=0 && xx<n && yy>=0 && yy<m){
                                        if(ves[xx][yy]=='#' && !vis[xx][yy]){
                                            recursive(xx, yy);
                                        }
                                    }
                                }
                            };
                            recursive(x, y);
                            int comp = ans == (hash_count - 1) ? (2) : (1);
                            // cout << ans << " " << comp << endl;
                            res = min(res, comp);
                            flag = 1;
                            break;
                        }
                    }
                }
                ves[i][j] = '#';
                // res = min(res, cnt);
            }
        }
    }
    if (hash_count <= 2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }
}