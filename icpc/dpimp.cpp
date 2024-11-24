#include<bits/stdc++.h>
using namespace std;


bool solveUsingDP(string &s, string &m, int x, int t1, int t2) {
	if(t1 > t2) return true;
	
	bool ans = false;
	if(s[x] == m[t1] && s[x] == m[t2]) {
		ans = solveUsingDP(s, m, x - 1, t1 + 1, t2) || solveUsingDP(s, m, x - 1, t1, t2 - 1);
	}
	else if(s[x] == m[t1]) {
		ans = solveUsingDP(s, m, x - 1, t1 + 1, t2);
	}
	else if(s[x] == m[t2]) {
		ans = solveUsingDP(s, m, x - 1, t1, t2 - 1);
	}
	return ans;
}


void solve(int test_case) {
	cout << "Case " << test_case << ": ";
	int l;
	cin >> l;
	string s, m;
	cin >> s >> m;
	bool result = solveUsingDP(s, m, s.size() - 1, 0, m.size() - 1);
	cout << (result ? "YES\n" : "NO\n");
}

int main() {
	int tt;
	cin >> tt;
	for(int test_case = 1 ; test_case <= tt ; ++test_case) {
		solve(test_case);
	}
	
/*
	s = "abcde"
	m = "dbace"
	m1 = "db|ace"
	t1 = acebd
*/
}