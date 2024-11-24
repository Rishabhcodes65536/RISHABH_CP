#include <bits/stdc++.h>

using namespace std;

vector<int> V;

void calc(int n){
    for (int j = 2; j <= sqrt(n);j++){
        if(n%j==0 && j+j<n){
            V.push_back(j);
            if(j*j!=n && (n/j + n/j) <n){
                V.push_back(n / j);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n;i++){
        v.push_back(v[i]);
    }
    V.resize(0);
    V.push_back(1);
    calc(n);
    sort(V.begin(),V.end());
    vector<vector<int>> dp(n+2, vector<int>(V.size()+2, 0));
    for (int j = 0; j < V.size(); j++){
        for (int i = 0; i < n;i++){
            if(i-V[j]>=0){
                dp[i][j] = dp[i - V[j]][j] & (v[i] == 1);
                if(i+V[j]>=n){
                    if(dp[i][j]){
                        cout << "YES"<<endl;
                        return 0;
                    }
                }
            }
            else{
                dp[i][j] = (v[i]==1);
            }
        }
    }
    cout << "NO" << endl;
}