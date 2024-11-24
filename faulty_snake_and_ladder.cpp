#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<pair<int, int>> ves;
    for (int i = 0; i < n; i++)
    {
        int uu, vv;
        cin >> uu >> vv;
        mp[uu] = vv;
        ves.push_back({uu, vv});
    }

    vector<int> v;
    string line;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    getline(cin, line);
    istringstream stream(line);
    int num;
    while (stream >> num)
    {
        v.push_back(num);
    }

    int pos;
    cin >> pos;
    // for (auto z : v)
    // {
    //     cout << z << " ";
    // }

    auto func = [&]() -> bool
    {
        int curr = 1;
        for (int u = 0; u < v.size(); u++)
        {
            curr += v[u];
            if (mp.find(curr) != mp.end() && mp[curr] != -1)
            {
                curr = mp[curr];
            }
        }
        // cout << curr << endl;
        return curr == pos;
    };

    bool q = func();
    if (q)
    {
        cout << "Not affected" << endl;
        return 0;
    }

    for (int z = 0; z < n; z++)
    {
        int qq = ves[z].first;
        int ww = ves[z].second;
        mp[qq] = -1;
        mp[ww] = qq;
        bool zz = func();
        if (zz)
        {
            if (qq > ww)
            {
                cout << "Ladder " << ww << " " << qq << endl;
                return 0;
            }
            else
            {
                cout << "Snake " << qq << " " << ww << endl;
                return 0;
            }
        }
        mp[ww] = -1;
        mp[qq] = ww;
    }
    cout << "Not possible" << endl;
    return 0;
}
