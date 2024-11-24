#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int pile = 1;
    int maxi = arr[0];
    for (int i = 1; i < n;i++){
        if(maxi==0){
            maxi = arr[i];
            pile++;
        }
        else{
            maxi = min(maxi - 1, arr[i]);
        }
    }
    cout << pile << endl;
}