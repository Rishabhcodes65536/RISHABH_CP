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
#define PI atan(1)*4

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

signed main(){
int t;
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//int n,k;
//string s
//array arr[n]
//char arr[n]
//cout << fixed << setprecision(9);
int n,m;
cin>>n>>m;
map <int,int> map1;
map <int,int> maxtime;
unordered_map <int, int> umap;
int res=0;
//map <pair<int,int>,int> umap;
vector<vector<int>> vec;
unordered_map <int,int> ans;
rep(i,0,n){
    vector <int> temp;
    rep(j,0,2){
        int g;
        cin>>g;
        temp.pb(g);   
    }
    vec.pb(temp);
}
rep(i,0,n){
    umap[vec[i][0]]=i;
}
vector <vector<int>> ummeed;
ummeed = vec;
sort(all(vec));
int time=0;
// rep(i,0,n){
//     rep(j,0,2){
//         cout<<vec[i][j]<<" ";
//     }
//     cout<<endl;
// }
for(int i=0;i<n;i+=m){
    map <int,int> batman;
    map <int,int> hue;
    int count=0;
    int maxi=-1;
    int journey=-1;
    vector <int> tem;
    vector <pair<int,int>> vep;
    while(count<m && count+i<n){
        batman[vec[i+count][1]]++;
        hue[vec[i+count][1]]++;
        maxi=max(maxi,vec[i+count][0]);
        journey=max(journey,vec[i+count][1]);
        vep.pb({vec[i+count][0],vec[i+count][1]});
        count++;
    }
    // for(auto s:batman){
    //     cout<<s.first<<" "<<s.second<<endl;
    // }
    sort(vep.begin(),vep.end(),sortbysec);
    
    if(time<maxi){
        time=maxi;
    }
    // rep(n,0,vep.size()){
    //     cout<<vep[n].first<<" lo "<<vep[n].second<<endl;
    // }
    // rep(z,0,vep.size()){
    //     cout<<ummeed[z][0]<<" ummeed "<<ummeed[z][1]<<endl;
    // }

    rep(hi,0,vep.size()){
        time+=vep[hi].second;
        //cout<<time<<endl;
        ans[vep[hi].first]=time;
        batman[vep[hi].second]--;
        //cout<<"hi "<<batman[vep[hi].first]<<endl;
        if((batman[vep[hi].second])==0){
            //cout<<"HO"<<endl;
            time+=1 + hue[vep[hi].second]/2;
        }
        time-=vep[hi].second;
    }
    
    time+=2*journey;
    //cout<<" "<<time<<endl;
}
for(int i=0;i<n;++i){
    cout<<ans[ummeed[i][0]]<<" ";
}
cout<<endl;
    return 0;
}

// 5 4


// 3 7 //5  5 second 5 sec 5->5 10 sec me pe deliver 1 sec gappa 1 sec next loc 1 sec gappa 1 sec next loc 1 sec gappa 7 sec hotel
// 4 6 //5  //10 12 14 22pehotel 1pedeliver 23 1 sec gappa 5 pe deliver 28
// 5 5 //5
// 6 5 //5
// 7 1

// 5 3
// 6 5
// 3 7
// 4 6
// 7 1
// 5 5