#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(a[i]);
        }
        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push((x + y) / 2);
        }
        cout << pq.top() << endl;
    }
}