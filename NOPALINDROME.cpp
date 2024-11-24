#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD2 = 998244353;
const int MOD1 = 1e9 + 7;
const int N = 1e5 + 5;

void SOLVE(vector<int> &v)
{

    int a, b;
    cin >> a >> b;
    
   
    while (1)
    {
        int k=b;
        v.push_back(1);
        if (a == v.size())
            return;

        while (k--)
        {
            
            v.push_back(0);
            if (a == v.size())
                return;
        }
        v.push_back(2);
        if (a == v.size())
            return;

        int c = 0;
        // cout<<b;

        if (b % 2 == 0  )
        {
            c = b / 2;
            c = c - 1;
        }
        else
        {
            c = b / 2;
        }
        // cout<<c;
         
       if(c<0){
        c=0;
       }
        while (c>0)  //0
        {
        //   if(c==0) break;
            v.push_back(0);
              if (a == v.size())
                return;

        }
        if (a == v.size())
            return;
      
    }
    return;
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);
    // #endif

    int T;
    cin >> T;
   
    while (T--)
    {
    vector<int> v;
         
        SOLVE(v);
        // int sum=0;
        for(auto it: v){
            // sum+=it;
            cout<<it;
        }
        
        int sum = accumulate(v.begin(), v.end(), 0);

        cout << sum << endl;
        // v.clear();
    }
    return 0;
}

/*
 */