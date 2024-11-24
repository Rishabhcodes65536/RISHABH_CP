#include <bits/stdc++.h>

using namespace std;

#define int long long 

signed main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    if(n==1){
        cout << (v[0] == m) << endl;
        return 0;
    }
    map<pair<int, int>, int> dp;
    sort(v.begin(), v.end());
    //meet in the middle algo ka kamaal n.2^(n/2)

    auto get_mask_vec = [&](int l, int h) -> vector<int>
    {
        int sz = h - l + 1;
        if(sz==0){
            return {};
        }
        vector<int> sub;
        for (int i = 0; i < (1 << sz);i++){
            int msk=i;
            int u = 0;
            for (int j = 0; j <(h-l+1);j++){
                if (msk & (1<<j)){
                    u += v[j+l];
                }
            }
            sub.push_back(u);
        }
        return sub;
    };
    int res = 0;
    vector <int> left = get_mask_vec(0, (n-1)/2);
    vector <int> right = get_mask_vec((n-1)/2+1, n-1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    // for(auto &r:left){
    //     cout << r << " ";
    // }
    // cout << endl;
    // for (auto &r : right)
    // {
    //     cout << r << " ";
    // }
    // cout << endl;
    for(auto &b:left){
        int lb = lower_bound(right.begin(), right.end(), m - b) - right.begin();
        int ub = upper_bound(right.begin(), right.end(), m - b) -right.begin();
        res += (ub-lb);
    }
    cout << res << endl;
}