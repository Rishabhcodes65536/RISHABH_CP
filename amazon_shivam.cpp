#include <bits/stdc++.h>

using namespace std;



// #define ss second;

int main(){
    string s;
    cin >> s;
    int u, v;
    cin >> u >> v;
    map<char, int> mp;
    for(auto &h:s){
        mp[h]++;
    }
    auto greedy1 = [&]() ->int { // u<v ya u==v matlab identical ko nikalna lazmi samjhenge
        int cost = 0,rem=0;
        for(auto z:mp){
            cost += ((z.second / 2) * u);
            rem += (z.second & 1);
        }
        cost += ((rem / 2) * v);
        return cost;
    };
    auto greedy2 = [&]()-> int { // u>v matlab different nikalna lazmi samjenge
        int maxi = 0;
        for(auto &r:mp)
        {
            maxi = max(maxi, r.second);
        }
        int rem = s.size() - maxi;
        int cost = 0;
        int off = max(maxi - rem,0);
        cost += ((off) / 2) * u;
        cost += ((s.size() - off) / 2) * v;
        return cost;
    };
    int res = min(greedy1(), greedy2());
    cout << res << endl;
}

//a a a a a b c d