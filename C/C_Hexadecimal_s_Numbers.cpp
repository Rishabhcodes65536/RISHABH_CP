#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string r = to_string(n);
    int mil_gaya = 0;
    string g = "";
    for (int i = 0; i < r.size();i++){
        if(r[i]>'1'){
            mil_gaya=1;
        }
        if(mil_gaya){
            g += "1";
        }
        else{
            g += r[i];
        }
    }
    int back_int_dec = stoi(g);
    int res = 0;
    int ptr = 1;
    while(back_int_dec>0){
        res += ((back_int_dec%10)*ptr);
        ptr <<= 1;
        back_int_dec /= 10;
    }
    cout << res << endl;

}