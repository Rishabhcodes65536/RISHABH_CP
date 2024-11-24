#include <bits/stdc++.h>

using namespace std;
static bool comp(pair <int,int>& a,pair <int,int>& b){
    int op1 = (a.first > b.first) + (a.first > b.second) + (a.second > b.first) + (a.second > b.second) + (a.first>a.second)+(b.first>b.second);
    int op2 = (b.first > a.first) + (b.first > a.second) + (b.second > a.first) + (b.second > a.second) + (a.first > a.second) + (b.first > b.second);
    return op1 < op2;
}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<pair<int, int>> vep;
        vector<int> vec;
        for (int i = 0; i < n;i++){
            int u, v;
            cin >> u >> v;
            vep.push_back({u, v});
            vec.push_back(u);
            vec.push_back(v);
        }
        sort(vec.begin(), vec.end());
        vector<array<int, 3>> v;
        for (int i = 0; i < n;i++){
            int x = upper_bound(vec.begin(), vec.end(), vep[i].first)-vec.begin();
            int y = upper_bound(vec.begin(), vec.end(), vep[i].second)-vec.begin();
            v.push_back({x + y, vep[i].first, vep[i].second});
        }
        sort(v.begin(), v.end());
        // sort(vep.begin(), vep.end(),comp);
        for(auto &w:v){
            cout << w[1] << " " << w[2] << " ";
        }
        cout << endl;
    }
}