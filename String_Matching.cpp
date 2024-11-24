#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    string s, p;
    cin >> s >> p;
    string t = p +"$"+s;
    vector<int> z = z_function(t);
    int res = 0;
    for (int y = p.size() + 1; y < t.size();y++)
    {
        // cout << z[y] << " ";
        if(z[y]==p.size())
            res++;
    }
    cout << res << endl;
}