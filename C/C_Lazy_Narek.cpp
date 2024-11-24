#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin >> tt;
        set<char> st;
        st.insert('n');
        st.insert('a');
        st.insert('r');
        st.insert('e');
        st.insert('k');
        string chaman = "narek";
        while (tt--)
        {
            int n, m;
            cin >> n >> m;
            vector<string> ves;
            vector<vector<array<int, 4>>> joke(n, vector<array<int, 4>>(5, array <int,4> ()));
            for (int i = 0; i < n; i++)
            {
                string s;
                cin >> s;
                string h = "";
                for (auto &c : s)
                {
                    if (st.count(c))
                    {
                        h += c;
                    }
                }
                for (int j = 0; j < 5;j++){
                    int ptr = j;
                    int cnt = 0;
                    bool flag = ((ptr == 0) ? (1) : (0));
                    bool comp = 0,reach_zero=flag;
                    for(auto &y:h){

                        if(y == chaman[ptr]) {
                            if(ptr==chaman.size()-1){
                                comp = 1;
                                if(flag){
                                    cnt++;
                                }
                                else{
                                    flag = 1;
                                }
                                ptr = 0;
                            }
                            else{
                                if(ptr==0){
                                    reach_zero = 1;
                                }
                                ptr++;
                                // ptr %= 5;
                            }
                        }   
                    }
                    joke[i][j] = {cnt,ptr,comp,reach_zero};
                    // cout << joke[i][j][1] << " ";
                }
                // cout << endl;
                // cout << h << endl;
                ves.push_back(h);
            }
            vector<vector<vector <int>>> dp(n + 2, vector<vector <int>>(6, vector <int> (2,INT_MIN)));
            function<int(int, int,int)> recursive = [&](int i, int u,int found) -> int{
                if(i==n){
                    return 0;
                }
                if(dp[i][u][found]!=INT_MIN){
                    return dp[i][u][found];
                }
                int incl=0,excl=0;
                int next_flag = (joke[i][u][1] == 0 ? (0) : (1));
                int next_step = joke[i][u][1];
                int comp = (10 * joke[i][u][0] - ves[i].size() + (((u!=0) && (joke[i][u][2] && (found)) ? (10) : (0)) + recursive(i + 1, next_step,next_flag)));
                // cout << comp << endl;
                incl = max(incl,comp);
                // cout << next_flag << " " << next_step << " " << comp << endl;
                excl = 0 + recursive(i + 1, u,found);
                // cout << incl << " " << excl << endl;

                return dp[i][u][found] = max(incl, excl);
            };
            int res = recursive(0, 0,0);
            // cout << "-- -- -- -- -- -- -- -- -- - "<< endl;
            cout << res << endl;
    }
}