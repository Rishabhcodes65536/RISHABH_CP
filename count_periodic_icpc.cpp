#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    vector<int> dict;

    // function<void(int)> dfs = [&](int y){

    // };
    // vector<string> ves;
    for (int period = 1; period <= 32;period++){
        for (int len = 1; len <= 32;len++){
            if(len%period==0){
                int num = 0;
                string h = "";
                for (int u = 0; u < len;u++){
                    if((u%(2*period))<period){
                        num <<= 1;
                        num += 1;
                        h += "1";
                    }
                    else{
                        num <<= 1;
                        h += "0";
                    }
                }
                dict.push_back(num);
                cout << h << endl;
                // ves.push_back(h);
            }
        }
    }
    // cout << dict.size() << endl;
    // for(auto &y:ves){
    //     cout << y << endl;
    // }
    sort(dict.begin(), dict.end());
    // for(auto &z:dict){
    //     cout << z << endl;
    // }
    // sort(dict.begin(), dict.end());
    int tt;
    cin >> tt;
    while(tt--){
        int l, r;
        cin >> l >> r;
        int lb_1 = upper_bound(dict.begin(), dict.end(), r)-dict.begin();
        int lb_2 = upper_bound(dict.begin(), dict.end(), l-1)-dict.begin();
        cout << (lb_1 - lb_2) << endl;
    }
}

//110011


//101010



//1100 1100 1100 1100 1100