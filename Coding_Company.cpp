#include <bits/stdc++.h>


#define int long long
using namespace std;

const int M = 1e9 + 7;

// int dp[101][101][10001];
signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        // cout << x << " ";
    }
    sort(v.begin(), v.end());
    // for(auto &u:v){
    //     cout << u << " ";
    // }
    int z = m + 5e3;
    //dp i
    vector<vector<int>> dp(n + 2,vector<int>(z+2, 0)),ndp;
    ndp = dp;

    // function<int(int, int, int)> dfs = [&](int i, int c, int pen) -> int {
    //     if(i==n){
    //         if(c>0){
    //             return 0;
    //         }
    //         return 1LL;
    //     }
    //     if(pen>z){
    //         return 0;
    //     }
    //     if(dp[i][c][pen]!=-1){
    //         return dp[i][c][pen];
    //     }

    //     //naya player ko ya to existing mai dalenge aur finish nahi karenge
    //     //existing mai dalke wo team end karenge
    //     //nayi team banayenge aur naye player ko us team mai dalenge
    //     //nayi team banayenge aur naye player ko usme dalke finish kar denge

    //     int op1(0), op2(0), op3(0), op4(0);

    //     if(c>0){   //koi existing team hai ki nahi
    //         op1 += c%M*dfs(i + 1, c, pen)%M; // c isliye kyuki koi bhi c unfinished team mai dal sakte hai
    //     }
    //     if(c>0 && pen+v[i]<=z){
    //         op2 += c%M*dfs(i + 1, c - 1, pen + v[i])%M;
    //     }
    //     if(pen-v[i]>=0){
    //     op3 += dfs(i + 1, c + 1, pen - v[i]);
    //     }
    //     op4 += dfs(i + 1, c, pen + v[i] - v[i]);

    //     return dp[i][c][pen] = (op1%M + op2%M + op3%M + op4%M) % M;
    // };
    
    dp[0][5e3] = 1;
    // cout << z << endl;
    for (int i = 0; i < n;i++){
        for (int j = 0; j <=n ;j++){
            for (int k = 0; k <= z;k++){
                if(j>0){
                    ndp[j][k] += j * dp[j][k];
                }
                if(j>0 && k+v[i]<=z){
                    ndp[j - 1][k + v[i]] += j*dp[j][k];
                }
                if(k-v[i]>=0){
                    ndp[j+1][k - v[i]] += dp[j][k];
                }
                ndp[j][k] += dp[j][k];
            }
        }
        for (int j = 0; j <= (n-(i+1));j++){
            for (int k = 0; k <= z;k++){
                dp[j][k] = ndp[j][k]%M;
                ndp[j][k] = 0;
            }
        }
    }
    int res = 0;

    // for (int j = 1; j <= n;j++){
        for (int kk = 5e3; kk <= z;kk++){
            res += dp[0][kk];
            res %= M;
        }
    // }
    cout << res << endl;
}

// // //number of teams 

// // // 1 <= n <= 100
// // // 0 <= x <= 5000
// // // 0 <= t_i <= 100

// // #include <bits/stdc++.h>

// // using namespace std;
// // using ll = long long;

// // const int M = 1e9 + 7;
// // const int K = 5e3; // Offset for handling negative penalties

// // int n, x;
// // vector<int> s;
// // vector<vector<vector<int>>> dp;

// // ll dfs(int i, int j, int k)
// // {
// //     if (k > x + K || k < 0)
// //         return 0; // Invalid penalty
// //     if (i == n)
// //         return (j == 0); // All people assigned and no unfinished groups

// //     if (dp[i][j][k] != -1)
// //         return dp[i][j][k];

// //     ll res = 0;

// //     // Case 1: Make a group with only the current person
// //     res = (res + dfs(i + 1, j, k)) % M;

// //     // Case 2: Finish an unfinished group with current person (requires an unfinished group)
// //     if (j > 0 && k + s[i] <= x + K)
// //         res = (res + j * dfs(i + 1, j - 1, k + s[i]) % M) % M;

// //     // Case 3: Start a new unfinished group with the current person
// //     if (j + 1 <= n - (i + 1))
// //         res = (res + dfs(i + 1, j + 1, k - s[i])) % M;

// //     // Case 4: Extend an unfinished group with the current person
// //     if (j > 0 && j <= n - (i + 1))
// //         res = (res + j * dfs(i + 1, j, k) % M) % M;

// //     return dp[i][j][k] = res;
// // }

// // int main()
// // {
// //     cin >> n >> x;
// //     s.resize(n);
// //     for (int i = 0; i < n; i++)
// //         cin >> s[i];
// //     sort(s.begin(), s.end());

// //     dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(x + K + 1, -1)));

// //     cout << dfs(0, 0, K) << endl;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// const int M = 1e9 + 7;
// const int OFFSET = 5e3;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     sort(v.begin(), v.end());

//     int z = m + OFFSET;
//     vector<vector<ll>> dp(n + 2, vector<ll>(z + 2, 0)), ndp(n + 2, vector<ll>(z + 2, 0));
//     dp[0][OFFSET] = 1; // Initialize base case with no unfinished teams and zero penalty offset

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             for (int k = 0; k <= z; k++)
//             {
//                 if (j > 0)
//                 {
//                     ndp[j][k] = (ndp[j][k] + j * dp[j][k] % M) % M; // Extend unfinished team
//                 }
//                 if (j > 0 && k + v[i] <= z)
//                 {
//                     ndp[j - 1][k + v[i]] = (ndp[j - 1][k + v[i]] + j * dp[j][k] % M) % M; // Finish team
//                 }
//                 if (k - v[i] >= 0)
//                 {
//                     ndp[j + 1][k - v[i]] = (ndp[j + 1][k - v[i]] + dp[j][k]) % M; // Start new team
//                 }
//                 ndp[j][k] = (ndp[j][k] + dp[j][k]) % M; // Add player as standalone
//             }
//         }

//         for (int j = 0; j <= n; j++)
//         {
//             for (int k = 0; k <= z; k++)
//             {
//                 dp[j][k] = ndp[j][k];
//                 ndp[j][k] = 0; // Reset for the next iteration
//             }
//         }
//     }

//     int res = 0;
//     for (int k = OFFSET; k <= z; k++)
//     {
//         res = (res + dp[0][k]) % M; // Sum all valid arrangements with zero unfinished teams
//     }

//     cout << res << endl;
//     return 0;
// }
