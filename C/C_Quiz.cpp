#include <bits/stdc++.h>

using namespace std;
#define int long long
const int M = 1e9 + 7;

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    int l = 0, h = (m/k);
    //bsearch on number of segments
    while(l<=h){
        int mid = (l) + (h - l) / 2LL;
        int corr = mid * k;
        int rem = max(0LL, n - corr);
        // cout << rem << endl;
        int w = n - corr;
        int g = rem / k;
        int gg = rem % k;
        int poss = g * (k - 1LL);
        poss += gg;
        // cout << mid << " " << poss << " " << corr << endl;
        if(poss+corr>=m){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l << endl;
    int res = 0;
    for (int i = 0; i < l;i++){
        res += (k);
        res %= M;
        res *= 2LL;
        res %= M;
    }
    int rems = m - l * k;
    // cout << rems << endl;
    res += rems;
    res %= M;
    cout << res << endl;
}