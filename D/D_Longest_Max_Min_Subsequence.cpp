

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {

        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // sort(a, a + n);
        int uniq = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                uniq++;
            }
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
        }
        int flag = 0;
        int i = 0, j = 0;
        int maxi = -1, mini = n + 1;
        vector<int> greedy;
        set<pair<int,int>> st;
        int maxi = -1;
        while (j < n)
        {
            mp[a[j]]--;
            maxi = max(maxi, a[j]);
            mini = min(mini, a[j]);
            if (mp[a[j]] == 0)
            {
                while (1)
                {
                    auto it = st.end();
                    it--;
                    while(st.size() && (*it).second<maxi){
                        auto temp = it--;
                        st.erase(*it);
                        it = temp;
                    }
                    int v = it != st.end() ? ((*it).first) : (-1);
                    auto it2 = st.begin();
                    while (st.size() && (*it2).second < maxi)
                    {
                        auto temp = it2--;
                        st.erase(*it2);
                        it2 = temp;
                    }
                    if (greedy.size() % 2 == 0)
                    {
                        if (!st.size() || a[j] >= )
                        {
                            cout << "Pushed -> even_b -> " << " " << a[j] << endl;
                            greedy.push_back(a[j]);
                            st.clear();
                            mp[a[j]] = -1;
                            break;
                        }
                        else
                        {
                            auto [u,pos1] = *st.begin();
                            auto [v,pos2] = *st.rbegin();
                            cout << "Pushed -> even -> " << " " << v << endl;
                            greedy.push_back(v);
                            mp[v] = -1;
                            st.erase(st.find(v));
                        }
                    }
                    else
                    {
                        if (!st.size() || a[j] <= u)
                        {
                            cout << "Pushed -> odd_b -> " << " " << a[j] << endl;
                            greedy.push_back(a[j]);
                            st.clear();
                            mp[a[j]] = -1;
                            break;
                        }
                        else
                        {
                            cout << "Pushed -> odd -> " << " " << u << endl;
                            greedy.push_back(u);
                            mp[u] = -1;
                            st.erase(st.find(u));
                        }
                    }
                }
            }
            else
            {
                if(mp[a[j]]>0){
                st.insert(a[j]);
                }
            }
            j++;
            for(auto &r:st){
                cout << r << " ";
            }
            cout << endl;
        }
        cout << greedy.size() << endl;
        for (auto b : greedy)
        {
            cout << b << " ";
        }
        cout << endl;
        cout << "------------------------" << endl;
    }
}
