#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    int su = 0;
    vector<pair <int,int>> val;
    for(int i = 0; i < n; i++){
        int t, v;
        cin >> t >> v;
        t--;
        su += v;
        // mp[v] = t;
        val.push_back({t, v});
    }

    if(su%3!=0){
        cout << -1 << endl;
        return 0;
    }
    int su3 = su / 3;
    vector<vector<int>> dp(su3 + 2, vector<int>(su3 + 3, 105));
    
    dp[0][0] = 0;
    for (int i = 0; i < n;i++){
        int this_team = val[i].first;
        int this_val = val[i].second;
        vector<vector<int>> ndp(su3 + 2, vector<int>(su3 + 3, 105));
        for (int j = 0; j <= su3;j++){
            for (int k = 0; k <= su3;k++){
                if(j-this_val>=0){
                    ndp[j][k] = min(ndp[j][k],dp[j - this_val][k] + (this_team != 0));
                    ndp[k][j] = min(ndp[k][j],dp[k][j - this_val] + (this_team != 1));
                }
                ndp[j][k] = min(ndp[j][k],dp[j][k] + (this_team != 2));
            }
        }
        dp = ndp;
    }
    cout << (dp[su3][su3] >= 105 ? (-1) : (dp[su3][su3]));
}