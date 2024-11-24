#include <bits/stdc++.h>

using namespace std;

// YE CODE HAI BHAGWAN BHAROSE

void rishcursion65536()
{
    // cout << "Rishabh is a good boy" << endl;
    vector<vector<array<int, 2>>> arrey(4, vector<array<int, 2>>(4));
    for (int i = 0; i < 4; i++)
    {
        int x, y, ab1, ab2;
        cin >> x >> y >> ab1 >> ab2;
        arrey[i][0] = {x, y};
        auto rotateWrtToPoint = [&](int a, int b, int u, int v)
        {
            auto translate = [&](int uu, int vv, int dx, int dy) -> array<int, 2>
            {
                return {uu + dx, vv + dy};
            };
            auto rotateAntiPerpendicularBitch = [&](int u, int v) -> array<int, 2>
            {
                return {-v, u};
            };
            auto translated = translate(a, b, -u, -v);
            auto myPointx = translated[0], myPointy = translated[1];
            for (int h = 1; h <= 3; h++)
            {
                auto temp = rotateAntiPerpendicularBitch(myPointx, myPointy);
                auto finallies = translate(temp[0], temp[1], u, v);
                myPointx = temp[0];
                myPointy = temp[1];
                arrey[i][h] = {finallies[0], finallies[1]};
            }
        };
        rotateWrtToPoint(x, y, ab1, ab2);
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arrey[i][j][0] << " " << arrey[i][j][1] << endl;
    //     }
    //     cout << "---------" << endl;
    // }
    int res = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int u = 0; u < 4; u++)
            {
                for (int v = 0; v < 4; v++)
                {
                    array<int, 2> p, q, r, s;
                    p = arrey[0][i];
                    q = arrey[1][j];
                    r = arrey[2][u];
                    s = arrey[3][v];
                    auto checkPerpendicularRhombusBitch = [&]() -> bool
                    {
                        auto checkEuclideanDistance = [](array<int, 2> g, array<int, 2> h) -> long long
                        {
                            // return abs(h[0] - g[0]) + abs(h[1] - g[1]);
                            return (1LL * (h[0] - g[0]) * (h[0] - g[0])) + (1ll * (h[1] - g[1]) * (h[1] - g[1]));
                        };
                        vector<long long> distances = {checkEuclideanDistance(p, q), checkEuclideanDistance(p, r), checkEuclideanDistance(p, s), checkEuclideanDistance(q, r), checkEuclideanDistance(q, s), checkEuclideanDistance(r, s)};
                        sort(distances.begin(), distances.end());
                        return (distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] && distances[0]!=0 && distances[4]==distances[0]+distances[1] && distances[5]==distances[4]);
                    };
                    if (checkPerpendicularRhombusBitch())
                    {
                        res = min(res, i + j + u + v);
                    }
                }
            }
        }
    }
    if (res == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        rishcursion65536();
    }
}