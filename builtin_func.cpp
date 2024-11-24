#include<bits/stdc++.h>
using namespace std;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                push_back
//#define int               long long
#define lb                lower_bound
#define ub                upper_bound
#define eb                emplace_back
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
const int M=1e9+7;
signed main(){
int t;
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//int n,k;
//string s
//array arr[n]
//char arr[n]
// cin>>t;
// while(t>0)
// {
// }
    int n;
    string decimalToBinary(int n);
    cin>>n;
    rep(i,0,n){
        
    cout<< decimalToBinary(i) <<" ka bultin ffs hai "<< __builtin_ffs (i)-1 <<" "<<endl;
    cout<< decimalToBinary(i) <<" return the number of 1 bit "<<__builtin_popcount (i)<<" "<<endl;
    cout<< decimalToBinary(i) <<" return the parity of number of 1-bit (number of1)%2 "<<__builtin_parity (i)<<" "<<endl;
        
    }

    return 0;
}
string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<64> (n).to_string();
     
    //Finding the first occurrence of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}