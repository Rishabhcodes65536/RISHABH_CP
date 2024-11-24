#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    while(c%b && c>0){
        c -= a;
    }
    if(c>=0){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}