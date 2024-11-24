// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int D = 31;
const int Q = INT_MAX;


void solve(string &s)
{
    // cout << s.size() << endl;
    string t;
    t = s;
    // reverse(t.begin(),t.end());
    map<int, int> mp, tp;
    int n = s.size();
    int start = 0, end = n / 2;

    vector<long long> p_pow(s.size());
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
    {
        p_pow[i] = (p_pow[i - 1] * D) % Q;
    }

    vector<long long> h(s.size() + 1, 0), h2(t.size() + 1, 0);
    for (int i = 0; i < s.size(); i++)
    {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % Q;
        // h2[i+1] = (h2[i] + (t[i] - 'a' + 1) * p_pow[i]) % Q;
    }
    for (auto &y : h)
    {
        // cout << y << " ";
    }
    // cout << endl;

    int window_size = end + 1;
    for (int u = end; u < n - 1 && window_size < n; u++)
    {
        int hash1 = h[window_size];
        int hash2 = (h[n] - h[n - window_size] + Q) % Q;

        hash1 = (hash1 * p_pow[n - window_size]) % Q;

        // cout << hash1 << " " << hash2 << endl;
        if (hash1 == hash2)
        {
            cout << "YES\n";
            cout << s.substr(0, window_size);
            return;
        }
        window_size++;
    }
    cout << "NO" << endl;
    // int temp=mod_div(h,D,Q);;
    // for(int i=0;i<n;i++){
    // 	pre+=s[i];
    // 	pre_hash=(D*pre_hash+s[i])%Q;
    // 	mp[i+1]=pre_hash;
    // }
    // for(auto &p:mp){
    // 	cout<<p.first<<" "<<p.second<<endl;
    // }
    // suff_hash=pre_hash;
    // // tp[n]=suff_hash;
    // int size=n-1;
    // string ans;
    // for(int i=0;i<n;i++){
    // 	suff_hash = ((D%Q * (suff_hash%Q - s[i]%Q * temp%Q +Q)) +Q) % Q;
    // 	temp=mod_div(temp,D,Q);
    // 	if(suff_hash<0){
    // 		suff_hash+=Q;
    // 	}
    // 	// cout<<mp[size]<<" "<<suff_hash<<endl;
    // 	tp[size]=suff_hash;
    // 	if(mp[size]==suff_hash){
    // 		//YES
    // 		cout<<"YES\n";
    // 		cout<<s.substr(0,size);return;
    // 	}
    // 	size--;
    // }
    // // cout<<"NO"<<endl;
    // for(auto &p:tp){
    // 	cout<<p.first<<" "<<p.second<<endl;
    // }
}

// void doSomething(string &s){

// }

signed main()
{
    string s;
    cin >> s;
    solve(s);
}
