
#include <bits/stdc++.h>

#define int long long
using namespace std;

static const int N = 1e6 + 3, M = 1e9 + 7;

int dp[N][2];

void pre()
{
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][0] %= M;
        dp[i][0] += (dp[i - 1][0] + 3LL * dp[i - 1][0] % M) % M;
        dp[i][0] %= M;

        dp[i][1] = dp[i - 1][0];
        dp[i][1] %= M;
        dp[i][1] += ((dp[i - 1][1] % M) * 2LL) % M;
        dp[i][1] %= M;
    }
}

// dp[1][0] = dp[n-1][1]

// dp[1][0] = dp[n-1][0] + 3*(dp[n-1][0]) +

// dp[1][1] = dp[n-1][0]

// dp[1][1] = dp[n-1][1] + dp[n-1][1]

// case 1 separate add
// 2nd case apas mai mil gaye

// case 1.2 no merge(1) or merge ( mege poss_r + merge_poss_l + merge_poss_l*merge_poss_r)

signed main()
{

    int tt;
    cin >> tt;
    pre();
    while (tt--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % M << endl;
    }
}
// 1*1

// dp

// dp[n][2]

// 0 state ki

// ##
// ##
// ##
// ##   <-k
// ##
// ##
// ##
// ##
// ##

//          nahi
//(*)(*)   (**)

// level 1 ko fill karne ke liye ** (**)

// lvel 2 ko fill karne ke liye 2*2  ** (**)

// ab
// cd

// ab
// ac

// aa
// aa
//

// dp [0][0]=1   // ith level be discrete ho (#)(#)
//  dp[0][1]=1;  //ith level pe combined ho (##)

// dp[1][0] = dp[n-1][1]

// dp[1][0] = dp[n-1][0] + 2*(dp[n-1][0]) +

// dp[1][1] = dp[n-1][0]

// dp[1][1] = dp[n-1][1] + dp[n-1][1]