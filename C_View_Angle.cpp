#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884L
#define in(k, a) for (auto k : a)
#define disp(a)                    \
    in(k, a) { cout << k << ' '; } \
    cout << endl
using namespace std;

int main()
{
    cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    vector<double> angles;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        
        double theta = atan2(y, x);
        double pi_rad = 180.0000000000;
        theta *= pi_rad / PI;
        if(theta<0){
            theta += 360.0;
        }
        angles.push_back(theta);
    }
    sort(angles.begin(), angles.end());
    double maxi = 0.0;
    for (int i = 1; i < n;i++){
        maxi = max(maxi, angles[i] - angles[i - 1]);
    }
    maxi = max(maxi,360.0 -( angles[n - 1] - angles[0]));
    cout << 360.0 - maxi<< endl;
}
