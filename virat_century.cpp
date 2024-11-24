                                    //  ॐ
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long int
using ld  = long double;


const int MOD = 1e9+7;  // check mod
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};


int dp[155][105][11][65][2]; // [runs][virat][wickets][balls]
mod_int prob=1;

int solve(int runs,int virat,int wickets,int balls,int strike){
    

      if(runs==0){
        if(virat==0){
             return 1;
        } 
        else{
             return 0;
        }  
      }

      if(wickets==10)
         return 0;

      if(balls==0)
         return 0;

      if(dp[runs][virat][wickets][balls][strike]!=-1){
          return  dp[runs][virat][wickets][balls][strike];
      }

      mod_int pr=0;

      for(int i=0;i<=6;i++){
           if(i==5){
              continue;
           }

           if(strike && i==0 && virat>0){
                continue;
           }
           
           int nxt_virat=virat;
           int nxt_runs=max(0,runs-i);

           if(strike){
              nxt_virat=virat-i;
              nxt_virat=max(0,nxt_virat);
           }
           
           int nxt_strike=strike; 
           if(i&1){
              nxt_strike^=1;
           }
           if(balls%6==1){
              nxt_strike^=1;
           }

           int nxt_wickets=wickets;
           if(i==0){
             nxt_wickets++;
           }
           pr+=prob*solve(nxt_runs,nxt_virat,nxt_wickets,balls-1,nxt_strike);
      }
    //   cout<<(int)pr<<endl;
      dp[runs][virat][wickets][balls][strike]=(int)pr;
      // cout<<runs<<' '<<virat<<' '<<wickets<<' '<<balls<<' '<<strike<<": "<<pr<<"\n";
      return (int)pr;
}

int main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int test =1;
    cin>>test;

    prob=1;
    prob/=6;

    for(int i=0;i<155;i++){
         for(int j=0;j<105;j++){
              for(int k=0;k<11;k++){
                  for(int b=0;b<65;b++){
                    for(int s=0;s<2;s++){
                          dp[i][j][k][b][s]=-1;
                    }
                  }
              }
         }
    }


    while(test--){
                    
                    int n,b,w,x;
                    cin>>n>>b>>w>>x;

                    cout<<solve(n,100-x,w,b,1); 


                    cout<<'\n';
                        

   }
        return 0;
}