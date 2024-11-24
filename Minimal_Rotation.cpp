#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    s += s;
    // string temp = "";
    int ans=0,ptr = 0;
    for(int i = 1; i <2*n; i++){
        if(s[i]<s[ans+ptr]){
            ans = i - ptr;
            i = ans;
            ptr = 0;
        }
        else if(s[i]>s[ans+ptr]){
            ptr = 0;
        }
        else{
            ptr++;
        }
        // cout << ans << endl;
    }
    string res = "";
    int k = 0;
    while(k<n){
        res += s[ans];
        ans += 1;
        ans = ans % (2 * n);
        k++;
    }
    cout << res << endl;
}