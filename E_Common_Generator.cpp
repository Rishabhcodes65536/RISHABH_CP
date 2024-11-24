#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 7e5;
int arr[N+4];
// int mini[N + 4];
vector<int> mini;
set<int> primes;

void pre(){
    memset(arr, 0, sizeof(arr));
    // memset(mini, 5e5, sizeof(mini));
    mini = vector<int>(N, 7e5 + 4);
    for (int i = 2; i <= N;i++){
        if(arr[i]==0){
            // mini[i] = i;
            // arr[i] = 1;
            for (int j = i + i; j <= N;j+=i){
                arr[j] = 1;
                if(j<mini.size()){
                mini[j] = min(mini[j], i);
                }
            }
        }
    }

    for (int i = 2; i <= N;i++){
        if(!arr[i]){
            primes.insert(i);
            // cout << i << " ";
        }
    }
    // cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int gen = -1;
        bool flag = 0;
        for (int i = 0; i < n;i++){
            if(i==0){
                if(primes.count(v[i])){
                    gen = v[i];
                }
                else{
                    gen = 2;
                }
            }
            else{
                if(primes.count(v[i])){
                    flag = 1;
                    break;
                }
                else{
                    if(gen!=2){
                        if(v[i]&1){
                            if(v[i]>gen && (v[i]-mini[v[i]] < 2*gen)){
                                // return -1;
                                // cout << "odd se kat gaya" << endl;
                                flag = 1;
                            }
                        }
                        else{
                            if(v[i]<2*gen){
                                flag = 1;
                            }
                        }
                    }
                }
            }   
        }
        if(flag){
            cout << -1 << endl;
        }
        else{
            cout << gen << endl;
        }
    }
}

//7 15 -> 7 10