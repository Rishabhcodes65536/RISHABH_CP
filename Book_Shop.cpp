// #include <bits/stdc++.h>

// using namespace std;

// #define int long long

// signed main(){
//     int n, x;
//     cin >> n >> x;
//     pair <int,int> a[n];
//     for (int i = 0; i < n;i++){
//         cin >> a[i].first;
//     }
//     for (int i = 0; i < n;i++){
//         cin >> a[i].second;
//     }
//     sort(a, a + n);
//     vector<int> dp(x + 1, 0),ndp(x+1,0);
//     for (int i = 0; i < n;i++){

//         for (int j = 0; j <= x;j++){
//             if(j-a[i].first>=0){
//             ndp[j] = max(ndp[j],(a[i].second) + dp[j - a[i].first]);
//             }
//             ndp[j] = max(ndp[j],dp[j]);
//         }
//         // swap(dp, ndp);
//         for (int j = 0; j <= x;j++){
//             dp[j] = ndp[j];
//             ndp[j] = 0;
//         }
//         // dp = ndp;
//         // ndp.clear();
//         // ndp.resize(x + 1, 0);
//         // ndp = vector<int>(x + 1, 0);
//     }
//     cout << dp[x] << endl;
// }

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
    }
    sort(a, a + n);
    vector<int> dp(x + 1, 0), ndp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j - a[i].first >= 0)
            {
                ndp[j] = (a[i].second) + dp[j - a[i].first];
            }
            ndp[j] = max(ndp[j], dp[j]);
        }
        swap(dp, ndp);
    }
    cout << dp[x] << endl;
}