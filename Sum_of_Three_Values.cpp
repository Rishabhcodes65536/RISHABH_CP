#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    vector < pair<int, int>> vep;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        vep.push_back({v[i], i});
    }
    sort(v.begin(), v.end());
    sort(vep.begin(), vep.end());
    for (int i = 0;i<n-2;i++){
        for (int j = i + 1; j < n-1;j++){
            int r = v[i] + v[j];
            int ptr = lower_bound(v.begin() + j + 1, v.end(), s - r)-v.begin();
            if(ptr!=v.size() && v[ptr]==s-r){
                cout << vep[i].second + 1 << " " << vep[j].second + 1 << " " << vep[ptr].second + 1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

// n*n