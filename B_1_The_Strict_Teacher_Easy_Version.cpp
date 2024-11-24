#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> v;
        for (int i = 0; i < m;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        while(q--){
            int pos;
            cin >> pos;
            auto lb = lower_bound(v.begin(), v.end(), pos) - v.begin();
            if(lb==m){
                if(pos==v.back()){
                    cout << 0 << endl;
                }
                else{
                    cout << n - v.back() << endl;
                }
            }
            else if(lb==0){
                if(pos==v.front()){
                    cout << 0 << endl;
                }
                else{
                    cout << v.front() - 1 << endl;
                }
            }
            else{
                if(pos==v[lb]){
                    cout << 0 << endl;
                }
                else{
                int prev = lb - 1;
                int dist = v[lb] - v[prev]-1;
                cout << (dist + 1) / 2 << endl;
                }
            }
        }
    }
}