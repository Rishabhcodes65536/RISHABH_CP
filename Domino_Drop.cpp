#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans=0;
        vector<int> res;
        int k = a[0]-1;
        int j = 0;
        while(j < n){
            if(k<j){
                ans += j - a[0]+1;
                a[0] = j+1;
            }
            k = max(k, j+a[j] - 1);
            res.push_back(ans);
            j++;
        }
        for(auto &r:res){
            cout << r << " ";
        }
        cout << endl;
    }
}


//[1,2,3]

//[2]

//