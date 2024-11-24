#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> v(n);
        int u = 0;
        for (int i = 0; i < n;i++){
            cin >> v[i];
            u ^= v[i];
        }
        if(u){
            cout << "first" << endl;
        }
        else{
            cout << "second" << endl;
        }
    }
}