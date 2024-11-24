#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> mp, gp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a, a + n);
        // for(int i=0)
        int mex = 0;
        for(auto &z:mp){
            if(z.first>mex){
                break;
            }
            if(z.second>1){
                mp[z.first + k] += (z.second - 1);
                z.second = 1;
            }
            mex++;
        }
        
        cout << mex << endl;
    }
}