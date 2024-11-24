#include <bits/stdc++.h>
using namespace std;

void dosomething(){
	int n;
	cin>>n;
	int dist[n];
	for(int i=0;i<n;i++){
		cin>>dist[i];
	}
	int prefix[n];
	prefix[0]=0;
	for(int i=1;i<n;i++){
		prefix[i]=dist[i-1]+prefix[i-1];
	}
	int k;
	cin>>k;
	int g=0;
	int tsum=accumulate(dist, dist+n,0LL);
	long long res=0;
	for(int i=0;i<k;i++){
		int u;
		cin>>u;
		int h=abs(prefix[u]-prefix[g]);
		res+=min(h,tsum-h);
		// cout<<h<<" "<<tsum-h<<endl;
		// cout<<res<<endl;
		g=u;
	}
	cout<<res<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		dosomething();
	}
}