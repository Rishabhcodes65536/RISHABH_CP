#include <bits/stdc++.h>

using namespace std;

int countdigit(int x){

    int dig = 0;
    while(x>0){
        x /= 10;
        dig++;
    }
    return dig;
}

int main(){
    long long l, r;
    cin >> l >> r;
    function<long long(long long, long long)> dfs = [&](int pos,int dig) -> int {

    };
    f
}