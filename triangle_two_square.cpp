#include <bits/stdc++.h>

using namespace std;

struct point{
    int x;
    int y;
};

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        double a, b, x, y;
        cin >> a >> b >> x >> y;
        auto poss = [&](point q, point w, point e, point r,int dir) -> bool
        {
            double slope1 = (q.y - e.y) / (q.x - e.x);
            double slope2 = (w.y - r.y) / (w.x - r.x);
            if(dir==0){
                double z = slope1 * (-q.x) + q.y;
                double z2 = slope2 * (-w.x) + w.y;
                return z > z2;
            }
            if(dir==1){
                double 
            }
        };
    }
}