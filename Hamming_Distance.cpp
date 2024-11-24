#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;
const int N = 2e4+2;
int arr[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        // reverse(s.begin(), s.end());
        for (int j = 0; j<m;j++)
        {
            arr[i] += ((s[j] == '1') * (1 << j));
        }
    }
    // for (int i = 0; i < n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    int res = 34;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res = min(res, __builtin_popcount(arr[i] ^ arr[j]));
        }
    }
    cout << res << endl;
}