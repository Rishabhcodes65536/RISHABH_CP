#include <bits/stdc++.h>

using namespace std;

//Display elements of the array
void display(vector<int> a, int n){
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    //Obtaining length of array
    int n;
    cin >> n;

    //Declaring a vector of integers
    vector<int> a;
    vector<int> b;
    
    //Taking input of array of integers
    for(int i=1; i<=n; i++){
         a[i]=i;
         b[i]=i;
    }
    while(next_permutation(a.begin(), a.end())){
        int k=a[1]&b[1];
        bool flag=false;
        for(int i=1;i<=n;++i){
        if(a[i] & b[i] !=k){
            flag=true;
        }
        }
        if(!flag){
            cout<<"HI"<<endl;
        for(int j=1;j<=n;++j){
            cout<<a[j]<<" "<<b[j]<<endl;
        }
        break;
        }
    }

    return 0;
}