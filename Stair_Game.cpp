#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int u = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(i&1){
            u ^= (v[i]);
            }
        }
        if (u)
        {
            cout << "first" << endl;
        }
        else
        {
            cout << "second" << endl;
        }
    }
}

// 0 bob jeet raha

// 1 alice jeet raha

// 0 1 bob
// 1 1 0 alice

// 1 0 1 bob

// 0 0 1 alice

// 0 1 1 alice

// 1 1 1 bob