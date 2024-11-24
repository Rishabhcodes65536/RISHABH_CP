#include <bits/stdc++.h>

using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    stack<pair <int,int>> st;
    vector<int> res;
    for (int i = 0; i < n;i++){
        while(!st.empty() && v[i]<=st.top().first){
            st.pop();
        }
        if(st.empty()){
            res.push_back(0);
        }
        else{
        res.push_back(st.top().second);
        }
        st.push({v[i],i+1});
    }
    for(auto &y:res){
        cout << y << " ";
    }
    cout << endl;
}