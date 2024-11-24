#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 1e9 + 7;

signed main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    vector<int> dp(x + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        // if(arr[i]<=x){
        //     dp[arr[i]]++;
        // }
    }
    sort(arr,arr+n);
    dp[0] = 1;
    for (int j = 1; j <= x;j++){
        for (int i = 0; i < n;i++){
            if(j-arr[i]<0)
                break;
            dp[j] += dp[j - arr[i]];
            dp[j] %= M;
        }
    }
    cout << dp[x] << endl;
}