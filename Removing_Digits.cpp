#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n; i >= 0;i--){
        if(dp[i]==INT_MAX){
            continue;
        }
        auto vget = [&](int u) -> set<int>
        {
            set<int> ll;
            while(u>0){
                int w = u % 10;
                if(w){
                    ll.insert(w);
                }
                u /= 10;
            }
            return ll;
        };
        set<int> digs = vget(i);
        for(auto &y:digs){
            dp[i - y] = min(dp[i - y], 1 + dp[i]);
        }
    }
    cout << dp[0] << endl;
}