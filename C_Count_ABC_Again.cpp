#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 2;i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
            cnt++;
    }
    while(q--){
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        auto check = [&](int u, int v, int w) -> bool {
            if(u<0 || v<0 || w<0 || u>=n || v>=n || w>=n){
                return false;
            }
            return (s[u] == 'A' && s[v] == 'B' && s[w] == 'C');
        };
        if(check(pos,pos+1,pos+2) || check(pos-1,pos,pos+1) || check(pos-2,pos-1,pos)){
            cnt--;
        }
        s[pos] = c;
        if (check(pos, pos + 1, pos + 2) || check(pos - 1, pos, pos + 1) || check(pos - 2, pos - 1, pos))
        {
            cnt++;
        }
        cout << cnt << endl;
    }
}