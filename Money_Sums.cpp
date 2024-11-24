#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0LL);
    vector<int> dp(sum + 3, 0),ndp(sum+3,0);
    dp[0] = 1;
    ndp[0] = 1;
    for (int i = 0; i < n;i++){
        for (int j = v[i]; j <= sum;j++){
            ndp[j] |= dp[j-v[i]];
        }
        // swap(dp, ndp);
        dp = ndp;
    }
    vector<int> vec;
    for (int i = 1; i <= sum;i++){
        if(dp[i]){
            vec.push_back(i);
        }
    }
    cout << vec.size()<<endl;
    for(auto &h:vec){
        cout << h << " ";
    }
    cout << endl;
}