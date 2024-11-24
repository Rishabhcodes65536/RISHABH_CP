#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int day;
    cin >> day;

    for (int i = 0; i < day;i++){
        vector<int> ndp = v;
        for (int i = 1; i < n-1;i++){
            ndp[i] = (v[i - 1] ^ v[i + 1]);
        }
        v = ndp;
    }
    v[0] = 0;
    v[n - 1] = 0;
    for(auto &y:v){
        cout << y << " ";
    }
    cout << endl;
    return 0;
}