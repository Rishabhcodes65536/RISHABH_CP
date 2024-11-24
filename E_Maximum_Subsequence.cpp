#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    auto get_v = [&](int l, int r) -> vector<int>
    {
        int sz = (r - l + 1);
        vector<int> sub;
        for (int y = 0; y < (1 << sz);y++){
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                if(y&(1<<i)){
                    sum += v[i+l];
                    sum %= m;
                }
            }
            sub.push_back(sum);
        }
        return sub;
    };

    vector<int> ll = get_v(0, n / 2);
    vector<int> rr = get_v(n / 2+1, n - 1);
    sort(ll.begin(), ll.end());
    sort(rr.begin(), rr.end());
    // for(auto y:ll){
    //     cout << y << " ";
    // }
    // cout << endl;
    // for(auto z:rr){
    //     cout << z << " ";
    // }
    // cout << endl;
    int res = 0;
    for(auto y:ll){
        int z = (m - y + m);
        int zz = (m - y + m)%m;
        int ind1 = (lower_bound(rr.begin(), rr.end(), z)-rr.begin());
        int ind2 = (lower_bound(rr.begin(), rr.end(), zz)-rr.begin());
        // cout << ind1;
        res = max({res, (y + (ind1>0 ? (rr[ind1-1]):(0)))%m});
        res = max({res, (y + (ind2>0 ? (rr[ind2-1]):(0)))%m});
        // res = max({res, y});
        // cout << y << " ka max " << res << endl;
        // auto it2 = lower_bound(rr.begin(), rr.end(), z);
    }
    cout << res << endl;
}