    #include <bits/stdc++.h>

    using namespace std;

    const int M = 1e9 + 7;

    #define int long long

    signed main(){
        int n, m;
        cin >> n >> m;
        vector<vector<array <long long,2>>> g(n+1);
        vector<array<long long, 3>> ggg;
        for (int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            a--, b--;
            ggg.push_back({a, b, c});
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        auto djikstra = [&](int st) -> vector<pair<long long, long long>>{
            vector < pair<long long, long long>> vep(n, {0, INT64_MAX});
            vep[st] = {1, 0};
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
            pq.push({0,st});
            while(!pq.empty()){
                auto w = pq.top();
                pq.pop();
                if(w.first>vep[w.second].second){
                    continue;
                }
                for(auto m : g[w.second]){
                    // cout << u << " " << c << endl;
                    if((w.first+m[1])<vep[m[0]].second){
                        vep[m[0]].second=w.first+m[1];
                        vep[m[0]].first = vep[w.second].first;
                        pq.push({vep[m[0]].second, m[0]});
                    }
                    else if((w.first+m[1])==vep[m[0]].second){
                        vep[m[0]].first += vep[w.second].first;
                        vep[m[0]].first %= M;
                    }
                }
            }
            return vep;
        };
        auto vep1 = djikstra(0);
        auto vep2 = djikstra(n-1);
        // for(auto &h:vep1){
        //     cout << h.first << " " << h.second << endl;
        // }
        // cout << endl;
        // for (auto &h : vep2)
        // {
        //     cout << h.first << " " << h.second << endl;
        // }
        for(auto &qq:ggg){
            int uu = qq[0];
            int vv = qq[1];
            int ww = qq[2];
            bool flag = 0;
            if(vep1[uu].second + ww + vep2[vv].second == vep1[n-1].second){
                if(((vep1[uu].first%M)*(vep2[vv].first%M))%M == vep1[n-1].first%M){
                    flag = 1;
                    // continue;
                }
            }
            if ((vep1[vv].second + ww + vep2[uu].second) == vep1[n - 1].second)
            {
                if ((vep1[vv].first % M * vep2[uu].first % M)%M == vep1[n - 1].first%M)
                {
                    // cout << "Yes" << endl;
                    // continue;
                    flag = 1;
                }
            }
            if(flag){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }