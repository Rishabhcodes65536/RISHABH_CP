#include <bits/stdc++.h>


using namespace std;

#define int long long

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int res = INT_MAX;
        for(int i = 0; i < n-1; i++){
            int r = v[i] + v[i + 1];
            // int st = i + 2;
            int ind = lower_bound(v.begin(), v.end(), r) - v.begin();
            int to_del = n - ind;
            res = min(res, i + to_del);
        }
        cout << res << endl;
    }
}