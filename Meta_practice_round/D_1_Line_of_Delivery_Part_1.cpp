#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("line_of_delivery_part_1_input.txt", "r", stdin);
    // freopen("line_of_delivery_part_1_output.txt", "w", stdout);
    int tt;
    cin >> tt;
    for (int t = 0; t < tt;t++){
        int n, q;
        cin >> n >> q;
        int left = -1, right = -1;
        int mini = INT_MAX,ptr=-1;
        map<int, int> mp;
        set<int> l, r;
        vector<int> v;
        int dir = 1;
        for (int i = 0; i < n;i++){
            int xx;
            cin >> xx;
            v.push_back(xx);
            if(abs(q-xx)<mini){
                if(xx<q){
                    dir = 0;
                }
                else{
                    dir = 1;
                }
                mini = abs(q - xx);
                ptr = xx;
            }
        }
        cout << dir << endl;
        queue<int> que;
        // if(!dir){
            for (int i = 0; i < n;i++){
                if(v[i] <= ptr){
                    que.push(i + 1);
                }
                else{
                    if(que.size()){
                        if(dir){
                            que.front() = i + 1;
                        }
                        else{
                            // if(que.size()){
                            que.pop();
                            que.push(i + 1);
                            // }
                        }
                    }
                }
            }
        // }
        cout << "Case #" << t+1 << ": ";
        cout <<que.front()<<" "<<mini<< endl;
    }
}