#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    // cout << tt << endl;
    for (int y = 0; y < tt; y++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        bool flag = 0;
        if(a>b){
            swap(a, b);
        }
        while(a!=0){
            if(b>=c && (b-c)%a == 0LL){
                cout << "YES" << endl;
                flag = 1;
                break;
            }
            b %= a;
            swap(a, b);
        }
        if(!flag){
            cout << "NO" << endl;
        }
    }
    return 0;
}