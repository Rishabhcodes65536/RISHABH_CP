#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#ifdef LOCAL_SYS
#include "debug.h"
#else
#define dbg(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

void solve(){
    int n = rand(1,2000),k=rand(1,1e9);
    cout <<n<< endl;
    cout<<k<<endl;
    for(int i = 0;i < n;i++){
        cout << rand(1,1e9)<< " "; 
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL_SYS
        freopen("error.txt", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
        cerr << fixed << setprecision(4);
    #endif
        
    freopen("2_input.txt", "w", stdout);
      
    int t = rand(1,100);
    // cin >> t;
    // t = (int)1;
    cout << t << endl;
    for(int i = 1;i <= t;i++){
      solve();
    }

    #ifdef LOCAL_SYS
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds> (stop - start);
        cerr << endl << "Time: " << ((long double)duration.count())/((long double)1e9) << "s " << endl;
    #endif

  return 0;
}