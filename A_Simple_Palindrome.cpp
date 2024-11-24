#include <bits/stdc++.h>

using namespace std;


int main(){

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<char> vo;
        vo = {'a', 'e', 'i', 'o', 'u'};
        string res = "";
        int g = 0,rem;
        g = n / 5;
        rem = n % 5;
        for (int i = 0; i < min(n, 5);i++){
            for (int j = 0; j < g;j++){
                res += vo[i];
            }
            if(i<rem){
                res += vo[i];
            }
        }
        cout<<res<<endl;
    }
}