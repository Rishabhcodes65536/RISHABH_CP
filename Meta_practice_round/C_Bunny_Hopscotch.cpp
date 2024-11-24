#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("bunny_hopscotch_input.txt", "r", stdin);
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    // freopen("bunny_hopscotch_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        int R, C;
        ll K;
        cin >> R >> C >> K;

        vector<vector<int>> grid(R, vector<int>(C));
        int max_val = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
            {
                cin >> grid[i][j];
                max_val = max(max_val, grid[i][j]);
            }

        vector<vector<pair<int, int>>> cells(max_val + 1);
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cells[grid[i][j]].emplace_back(i, j);

        int lo = 0, hi = max(R, C), res = hi;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int max_row = min(mid, R - 1);
            int max_col = min(mid, C - 1);

            ll row_contrib = (ll)R * (2LL * max_row + 1) - 1LL * max_row * (max_row + 1);
            ll col_contrib = (ll)C * (2LL * max_col + 1) - 1LL * max_col * (max_col + 1);
            ll total_pairs = row_contrib * col_contrib - (ll)R * C, owner_same_pairs = 0;

            for (int b = 1; b <= max_val; ++b)
            {
                int count_bunnies = cells[b].size();
                if (count_bunnies <= 1)
                    continue;

                auto &locs = cells[b];
                sort(locs.begin(), locs.end());

                for (int r = 0; r < count_bunnies; ++r)
                {
                    int x_r = locs[r].first, y_r = locs[r].second;

                    auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
                    { return a.second < b.second; };
                    int l_bound = lower_bound(locs.begin(), locs.end(), make_pair(x_r - mid, -1)) - locs.begin();
                    int u_bound = upper_bound(locs.begin(), locs.end(), make_pair(x_r + mid, C)) - locs.begin();

                    int low_idx = lower_bound(locs.begin() + l_bound, locs.begin() + u_bound, make_pair(0, y_r - mid), comp) - locs.begin();
                    int high_idx = upper_bound(locs.begin() + l_bound, locs.begin() + u_bound, make_pair(0, y_r + mid), comp) - locs.begin();

                    owner_same_pairs += (ll)(high_idx - low_idx);
                }

                owner_same_pairs -= (ll)count_bunnies;
            }

            ll valid_pairs = total_pairs - owner_same_pairs;

            if (valid_pairs >= K)
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << "Case #" << tc << ": " << res << endl;
        // cout << res << "\n";
    }

    return 0;
}
