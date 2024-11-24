#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s, y;
    cin >> s;
    cin >> y;

    for (int i = 0; i < y.size(); i++)
    {
        // upper to lower case
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + 32;
        }
    }

    for (int i = 0; i < y.size(); i++)
    {
        // upper to lower case
        if ((y[i] >= 'A') && (y[i] <= 'Z'))
        {
            y[i] = y[i] + 32;
        }
    }
    // cout<<s<<" "<<y<<endl;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] < y[i])
        {
            cout << -1;
            return 0;
        }
        else if(s[i]>y[i])
        {
            cout << 1;
            return 0;
        }
    }
    cout<<0<<endl;
}
