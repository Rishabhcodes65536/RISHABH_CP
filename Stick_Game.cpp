#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<bool> vb(n+1, false);

    for (int i = 1; i <= n;i++){
        for(auto y:v){
            if(i-y<0)
                break;
            
            if(!vb[i-y]){
                vb[i] = true;
                break;
            }
        }
    }
    string s = "";
    for (int i = 1; i <= n;i++){
        s += (vb[i] ? 'W' : 'L');
    }
    cout << s << endl;
}