#include <bits/stdc++.h>

using namespace std;

long long INF = INT64_MAX;
const long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
inline long long rnd(long long l = 0, long long r = INF)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}

long long res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fall_in_line_input.txt", "r", stdin);
    freopen("fall_in_line_output.txt", "w", stdout);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt;t++){
        int n;
        cin >> n;
        vector<array<long long, 2>> vep;
        res = n;
        for (int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            vep.push_back({u, v});
        }
        auto chk = [&](int x, int y)
        {
            long long x1 = vep[x][0], y1 = vep[x][1];
            long long x2 = vep[y][0], y2 = vep[y][1];
            long long cnt = 0;
            for (int p = 0; p < n;p++){
                long long x3 = vep[p][0], y3=vep[p][1];
                long long arr = x1 * (y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
                if(arr)
                    cnt++;
            }
            res = min(res, cnt);
        };
        if(n<=200){
            for (int i = 0; i < n;i++){
                for (int j = 0; j < n;j++){
                    if(i != j){
                        chk(i, j);
                    }
                }
            }
        }
        else{
            for (int i = 0; i < 200;i++){
                long long l = 0, h = 0;
                while(l==h){
                    l = rnd(0, n - 1);
                    h = rnd(0, n - 1);
                }
                chk(l, h);
            }
        }
        cout << "Case #" << t << ": ";
        cout << res << endl;
    }
}