#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int msk = 1; msk < (1 << k);msk++){
        int ans = 1;
        bool flag = 0;
        for (int z = 0; z < k;z++){
            if((1<<z)&msk){
                if(a[z]>1e18/ans){
                    flag = 1;
                    break;
                }
                ans *= a[z];
            }
        }
        int bits = __builtin_popcountll(msk);
        if(!flag){
            res = res + (bits & 1 ? (1LL) : (-1LL)) * (n / ans);
        }
    }
    cout << res << endl;
}