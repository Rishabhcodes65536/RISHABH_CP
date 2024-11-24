#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ff first
#define ss second



// 4 4 4 4 4 4 3 3 3   3 pair valid hai 


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        for (auto y : mp)
        {
            pq.push({y.second, y.first});
        }
        int uniq = 0;
        int dummy = INT_MAX;

        for (int i = 0; i < min(n, k); i++)
        {
            auto x = pq.top();
            // mp[x]
            if (x.first <= 1)
            {
                break;
            }
            mp[x.second]--;
            pq.pop();
            pq.push({mp[x.second], x.second});
            uniq++;
            // mp[dummy]++;
            // dummy += 1;
        }
        vector<pair<int, int>> zz;
        int sum = 0;
        for (auto &h : mp)
        {
            zz.push_back({h.first, h.second});
            sum += h.second;
        }
        sort(zz.begin(), zz.end());
        int res = 0;
        res += (uniq * (uniq - 1)) / 2 + (((uniq * (uniq - 1)) / 2+(uniq>0)) * (sum));
        for (int j = zz.size() - 1; j >= 0;j--){
            sum -= zz[j].second;
            res += sum*zz[j].second;
        }
        // for (auto &z : zz)
        // {
        //     cout << z.ff << " " << z.ss << endl;
        // }
        // cout << endl;
        cout <<res<<endl;
    }
}

//8+7+6+4+2

//2 3 4 5 6

// 1e9 1e9

// 1e9-1 1e9

// 1e9-1 1e9-1

// 2 2 3 3 4 4
// 2 2 3 4 5 6

// 8+3+2+1

//2 2 3 3 3 4 4 4 5



//0+1+2+3+3+5+5+14