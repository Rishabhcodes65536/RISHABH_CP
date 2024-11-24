#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    string res = "";
    for(auto &g:s){
        if(g!='.'){
            res += g;
        }
    }
    cout << res << endl;
}