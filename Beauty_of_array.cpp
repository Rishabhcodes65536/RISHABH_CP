#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find the previous and next smaller elements for each element
    vector<int> prev(n), next(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        prev[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        next[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Calculate the sum of XOR of the smallest and second smallest elements
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int left = prev[i] + 1, right = next[i] - 1;
        long long cnt = i - prev[i] + 1LL * (next[i] - i) * (i - prev[i]);
        ans += cnt * (arr[i] ^ arr[left]);
        cnt = 1LL * (right - i) * (i - prev[i]);
        ans += cnt * (arr[i] ^ arr[next[i]]);
    }

    cout << ans << endl;
    }

    return 0;
}
