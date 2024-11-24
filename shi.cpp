#include <bits/stdc++.h>

using namespace std;
#define int long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    map<int, int> mp;
    for (int i=0; i < n;i++){
        int u;
        cin >> u;
        v.push_back(u);
        mp[u]++;
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n;i++){
        res += mp[v[i] - k];
    }
    cout << res << endl;
    return res;
}