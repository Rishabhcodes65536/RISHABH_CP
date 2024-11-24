#include<bits/stdc++.h>
using namespace std;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                push_back
#define int               long long
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
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl
const int M=1e9+7;
#define test int t; cin>>t; while(t--)
#define SUMI0(a)   accumulate(a , a+n ,0)
#define MAX(v)    *max_element((v).begin(),(v).end())
#define MINI(v)   *min_element((v).begin(),(v).end()) 
#define PI atan(1)*4
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)
int countDivisors(int n)
{
int cnt = 0;
for (int i = 1; i <= sqrt(n); i++) {
 if (n % i == 0) {
 if (n / i == i)
  cnt++;
else // Otherwise count both
cnt = cnt + 2;
}
 }
return cnt;
}

int distintBitwiseOR(int arr[], int n)
{
    unordered_set<int> ans, prev;
 
    for (int i = 0; i < n; i++) {
        unordered_set<int> ne;
 
        for (auto x : prev){
            cout<<"This gets inserted "<<arr[i]<<" hi "<<x<<"    "<< (arr[i]|x)<<endl;
            ne.insert(arr[i] | x);
        }
        cout<<"This gets whole inserted "<<arr[i]<<" \n\n"<<endl;
        ne.insert(arr[i]);
 
        for (auto x : ne)
            ans.insert(x);
 
        prev = ne;
    }
    //disp(ans);
 
    return ans.size();
}
 
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);

	int n;
    cin>>n;
	inarr(arr,n);
    
	cout << distintBitwiseOR(arr, n);
	return 0;
}


//1 
//1 || 2
//2
//3 || 2
//3 || 3