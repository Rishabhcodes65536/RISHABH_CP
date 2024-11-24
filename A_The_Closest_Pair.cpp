#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int maxi = (n * (n - 1)) / 2;
    if(k>=maxi){
        cout << "no solution" << endl;
    }
    else{
        int xx = 0;
        int yy = 0;
        for (int i = 0; i < n;i++){
            cout << xx << " " << yy << endl;
            yy += 2;
        }
    }
}