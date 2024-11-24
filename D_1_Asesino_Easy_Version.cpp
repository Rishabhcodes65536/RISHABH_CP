#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> sus(n, 0);
        auto ask = [&](int u, int v)
        {
            printf("? %d %d\n", u, v);
            fflush(stdout);
            int bit;
            cin >> bit;
            return bit;
        };
        auto give = [&](int r)
        {
            // i don't know know man you seem to be a little sus lately
            // you sussy baka walt
            printf("! %d\n",r);
            fflush(stdout);
        };
        int w = -1;
        for (int i = 0; i+1 < n;i+=2){
            int resp1= ask(i + 1, (i + 1) % n + 1);
            int resp2= ask((i + 1) % n + 1,i+1);

            if(resp1 !=resp2){
                w = i+1;
                break;
                // if(sus[i]>1){
                //     give(i + 1);
                //     break;
                // }
                // if(sus[(i+1)%n]>1){
                //     give((i + 1) % n + 1);
                //     break;
                // }
            }
        }
        if(w == -1){
            give(n);
        }
        else{
            if(w==1){
                int resp3 = ask(1, n);
                int resp4 = ask(n, 1);
                if(resp3!=resp4){
                    give(1);
                }
                else{
                    give(2);
                }
            }
            else{
                int resp3 = ask(1, w);
                int resp4 = ask(w,1);
                // int resp5 = ask(1, w + 1);
                // int resp6 = ask(w + 1, 1);
                if(resp3!=resp4){
                    give(w);
                }
                else{
                    give(w + 1);
                }
            }
        }

    }
}