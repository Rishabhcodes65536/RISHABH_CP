#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for(auto &c:s){
        if(!mp[c]){
            return -1;
        }
    }
    int res = 0, n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (i < n - 1 && m[s[i]] < m[s[i + 1]])
            res -= m[s[i]];
        else
            res += m[s[i]];
    }
    return res;
}

bool isValidRoman(string s)
{
    string invalid[] = {"IIII", "VV", "XXXX", "LL", "CCCC", "DD", "MMMM"};
    for (string t : invalid)
        if (s.find(t) != string::npos)
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (!isValidRoman(s))
        cout << "Invalid" << endl;
    else
        
    return 0;
}