#include <bits/stdc++.h>

using namespace std;

int nck[501][501];

void pre(){

}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));

    for (int sz = 1;sz<=n;sz++){
        for (int i = 1;i<=n-sz+1;i++){
            int j = i + sz-1;
            for (int k = i; k <= j;k++){
                
            }
        }
    }
}