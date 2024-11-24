#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, int> mp;
    int i = 0, j = 0, temp = 0, res = 0;
    mp[0] = 1;
    while (j < n)
    {
        temp += v[j];
        res += mp[temp - m];
        mp[temp]++;
        j++;
    }
    cout << res << endl;
}