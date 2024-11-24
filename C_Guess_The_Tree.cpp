#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
// #define int long long
#define float long double
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define ppc __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
void dosomething()
{
    int n;
    scanf("%d", &n);
    set<pair<int, int>> vep;
    int u = 1, v = 2,xx=2;
    // set<int> vis;
    while (vep.size() < n - 1)
    {
        printf("? %d %d\n", u, v);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if (res == u)
        {
            vep.insert({u, v});
            u = 1;
            v = (xx + 1);
            xx++;
        }
        else{
            u = res;
        }
    }
    printf("!");
    for (auto &p : vep)
    {
        printf(" %d %d", p.first, p.second);
    }
    printf("\n");
    fflush(stdout);
}
signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        dosomething();
        // Case #<<t<<'='<< ;
    }
    return 0;
}