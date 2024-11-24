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
    // mp[0] = 1;
    while (j < n)
    {
        if(!mp[v[j]]){
            temp++;
        }
        mp[v[j]]++;
        while(temp>m){
            if(mp[v[i]]==1){
                temp--;
            }
            mp[v[i]]--;
            i++;
        }
        res += (j - i + 1);
        j++;
    }
    cout << res << endl;
}