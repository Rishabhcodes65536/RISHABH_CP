#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        string v;

        vector<pair<int, char>> a;
        for (auto it : m)
        {
            a.push_back({it.second, it.first});
        }
        sort(a.rbegin(), a.rend());

        // reverse(v.begin(),v.end());

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 1; j <= a[i].first; j++)
            {
                v.push_back(a[i].second);
            }
        }
        // cout << v << endl;
        ll j = 0;
        string ans = "";
        ans.resize(n, '0');
        for (int i = 0; i < n; i += 2)
        {
            // ans.push_back(v[j]);
            ans[i] = v[j];
            j++;
        }
        for (int i = 1; i < n; i += 2)
        {
            // ans.push_back(v[j]);
            ans[i] = v[j];
            j++;
        }

        cout << ans << endl;
    }
}