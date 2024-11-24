
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                emplace_back
#define ppb               pop_back
#define int               long long
#define float             long double
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=(a);i>=(b);i--)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl
const int M=1e9+7;
#define test int t; cin>>t; while(t--)
#define SUMARR(a)   accumulate(a , a+n ,0LL)
#define SUM(v)      accumulate(all(v),0LL)
#define MAXIARR(a,n)  *max_element(a , a+n)
#define MINIARR(a,n)  *min_element(a , a+n)
#define MAX(v)      *max_element((v).begin(),(v).end())
#define MINI(v)     *min_element((v).begin(),(v).end()) 
#define PI           atan(1)*4
#define INF          INT64_MAX
#define fbo(x)       find_by_order(x)
#define ook(x)       order_of_key(x)
#define out(x)       cout<<x<<endl;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)
/////खुदी को कर बुलंद इतना के हर तकदीर से पहले खुदा बन्दे से खुद पूछे के बता तेरी रज़ा क्या है;/////
 

int getClosest(int, int, int);
 
// Returns element closest to target in arr[]
int findClosest(int arr[], int n, int target)
{
    // Corner cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
 
    // Doing binary search
    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
 
        if (arr[mid] == target)
            return arr[mid];
 
        /* If target is less than array element,
            then search in left */
        if (target < arr[mid]) {
 
            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],
                                  arr[mid], target);
 
            /* Repeat for left half */
            j = mid;
        }
 
        // If target is greater than mid
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],
                                  arr[mid + 1], target);
            // update i
            i = mid + 1;
        }
    }
 
    // Only single element left after search
    return arr[mid];
}
 
// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// between these two.
int getClosest(int val1, int val2,
               int target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

int getSum(int n)
{
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
 
 
void dosomething(){
// int n,k;
int n;
cin>>n;
if(!(n&1)){
    cout<<"No"<<endl;
}
else{
    cout<<"Yes"<<endl;
    int a=1,b=2*n;
    cout<<a<<" "<<b<<endl;
    rep(i,0,n/2){
        a+=2;
        b-=1;
        cout<<a<<" "<<b<<endl;
    }
    a=2;
    b--;
    rep(i,0,n/2){
        cout<<a<<" "<<b<<endl;
        a+=2;
        b-=1;
    }
}
}


signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
 
int t=1;
cin>>t;
// initialize();
while(t--){
// set <int> g;
dosomething();
//Case #<<t<<'='<< ;
}
    return 0;
}


//1 4
//2 3

//1 8
//3 7
//2 6
//4 5

//1 10
//3 4
//2 8
//6 7
//9 5

//1 k
//2 k-2
//3 k-1
//

//1 10
//3 9
//2 8
//6 7
//4 5

//1 10
//3 9
//5 8
//2 7
//4 6

//1 10
//2 8
//3 9

//
//4 5

//9 to 13 sum

//6 to 8 sum

//1 5
//2 6
//3 7
//4 8
//5 9


//2 10
//4 9
//6 8
//1 14
//3 13
//5 12
//7 11
//

//
