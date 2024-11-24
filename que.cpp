#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 100;
    queue<int> q;
    while (n>0)
    {
        q.push(n % 3);
        n /= 3;
    }
    while(q.size()){
        cout<<q.front()<<endl;
        q.pop();
    }
    
}