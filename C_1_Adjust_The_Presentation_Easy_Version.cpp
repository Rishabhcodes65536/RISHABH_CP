#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    for (int u = 1; u <= tt;u++){
        int n, m, k;
        cin >> n >> m >> k;
        int a[n],vis[n];
        for (int i = 0; i < n;i++){
            cin >> a[i];
            vis[i] = 0;
        }
        memset(vis, 0, n);
        int ptr = 0;
        int b[m];
        for (int i = 0; i < m;i++){
            cin >> b[i];
        }
        int j = 0;
        bool flag = 0;
        while(j<m && ptr<n){
            if(vis[b[j]-1]){
                j++;
                continue;
            }
            if(b[j]==a[ptr]){
                vis[b[j]-1] = 1;
                j++;
                ptr++;
            }
            else{
                // cout << "TIDAK" << endl;
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << "TIDAK" << endl;
        }
        else{
            cout << "YA" << endl;
        }
    }
}