#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using ll = long long;

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;
// template <unsigned int MOD>
// struct MinimalModInt {
//     unsigned int v;
//     MinimalModInt (long long _v = 0) {
//         v = _v % MOD;
//         if (v < 0) v += MOD;
//     }

//     MinimalModInt operator+(const MinimalModInt& a) const {
//         return MinimalModInt(v + a.v);
//     }
//     MinimalModInt operator-(const MinimalModInt& a) const {
//         return MinimalModInt(v - a.v);
//     }
//     MinimalModInt operator*(const MinimalModInt& a) const {
//         return MinimalModInt((unsigned long long)v * a.v);
//     }
// };

// template <unsigned int MOD>
// ostream& operator << (ostream& os, const MinimalModInt<MOD>& a){
//     return os << a.v;
// }

// using Mint = MinimalModInt<998244353>;

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> range;

    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        r++;
        range.emplace_back(l,r);
    }

    vector<Mint> dp(n);
    dp[0] = 1;
    dp[1] = -1;

    for (int i = 0; i < n; i++){
        if (i > 0) dp[i] =  dp[i] + dp[i - 1];
        for (int j = 0; j < k; j++){
            int l, r;
            tie (l, r) = range[j];
            if (i + l < n) dp[i+l] = dp[i+l] + dp[i];
            if (i + r < n) dp[i+r] = dp[i+r] - dp[i];
        }
    }
    cout << dp[n-1].v << endl;
    
}

void naiveDP(){

    int n, k; cin >> n >> k;
    vector<int> jumps;

    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        for (int d = l; d <= r; d++){
            jumps.emplace_back(d);
        }
    }

    vector<Mint> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++){
        for (int d : jumps){
            if ((i - d) >= 0) {
                dp[i] = dp[i] + dp[i - d];
            }
        }
    }

    cout << dp[n - 1].v << endl;

}

struct solvestruct {
    int n;
    int k;
    vector<pair<int, int>> ranges;
};
// solvestruct is a structure
// solvestruct(int, int, vector<pair<int,int>>
// interpretation 
// n is the number of cells
// k is the number of ranges
// ranges are the ranges


// cin {int int list-of-ints } -> solvestruct
// get the inputs and present them as a solvestruct
// given inputs outputs solvestruct
solvestruct getInputs (){
    int n, k; cin >> n >> k;
    vector<pair <int, int>> ranges(k);
    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        r++;
        ranges[i] = make_pair(l, r);
    }
    solvestruct ans;
    ans.n = n;
    ans.k = k;
    ans.ranges = ranges;
    return ans;
}


// solvestruct int vector<Mint> -> mutate(dp)
// loop through all ranges and add and subtract from the difference array
void diffarr(solvestruct s, int i, vector<Mint>& dp){
        for (int j = 0; j < s.k; j++){
            int l, r;
            tie (l, r) = s.ranges[j];
            if(i + l < s.n) dp[i+l] = dp [i+l] + dp[i];
            if(i + r < s.n) dp[i+r] = dp [i+r] - dp[i];
        }
}

// int vector<Mint> -> mutate(dp)
// make the current element uptodate
void setElement(int i, vector<Mint>& dp){
        if (i > 0) dp[i] = dp[i] + dp[i - 1];
}

// solvestruct -> Mint
// DP optimized solution
Mint optimizedDP(solvestruct s){
    vector <Mint> dp(s.n);
    dp[0] = 1;
    dp[1] = -1;

    // solvestruct int vector<Mint> -> mutate(dp)
    // for every element in the dp array, mutate the dp array according to the 
    // diffference array logic
    for (int i = 0; i < s.n; i++){
        setElement(i, dp);
        diffarr(s, i, dp);
    }

    return dp[s.n - 1];
}


int main(){
    cout << optimizedDP(getInputs()).v <<endl;
    return 0;
}

