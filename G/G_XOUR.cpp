#include <bits/stdc++.h>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        int mask = (1 << 31) - 1;
        mask -= 3;
        map <int,vector <int>> mp;
        for (int i = 0; i < n;i++){
            mp[a[i] & mask].push_back(a[i]);
        }
        for(auto &z:mp){
            sort(z.second.rbegin(),z.second.rend());
        }
        for (int i = 0; i < n;i++)
        {
            a[i] = mp[a[i] & mask].back();
            mp[a[i] & mask].pop_back();
        }
        for (int i = 0; i < n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }   
}