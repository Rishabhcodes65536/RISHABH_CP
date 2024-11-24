//1st person 

#include <bits/stdc++.h>

using namespace std;

int dfs(int i,multiset <int>& st,int &n,int &x,vector <int>& v){
    if(i==n){
        if(st.size()==0){
            return 0;
        }
        return 1e3;
    }

    int op1, op2, op3, op4;
    op1 = op2 = op3 = op4 = 1e9;

    if(st.size()){
        for (auto itt = st.begin(); itt != st.end();itt++)
        {
            auto it = itt;
            if((*it+v[i])<=x){
                int val = *it;
                st.erase(it);
                st.insert(val + x);
                op1 = min(op1,dfs(i+1,st,n,x,v));
                st.erase(st.find(val + x));

                st.insert(val);
                
            }
        }
    }
}

//existing mai dalo
//existing mai dalke finish karo
//new mai dalo
//new mai dalke finish karo

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n;i++){
        int z;
        cin >> z;
        v.push_back(z);
    }
    sort(v.begin(), v.end());

    
}