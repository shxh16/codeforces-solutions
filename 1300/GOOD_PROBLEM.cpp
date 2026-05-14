#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Code ios::sync_with_stdio(false);
#define by cin.tie(nullptr);
#define Shrinil cout.tie(nullptr)
const long long MOD = 1e9 + 7;
ll ceil_div(ll a,ll b){
    return (a+b-1LL)/(b);
}
bool pow_2(ll n){
    if(n == 0) return true;
    return ((n > 0)&&(n & (n - 1)) == 0);
}
ll n,k,l,r;
void solve(){
    cin >> n>>l>>r>>k;
    if(n%2) cout << l << '\n';
    else if(n == 2) cout << - 1<< '\n';
    else{
        bool found = false;
        ll power_2 = 1;
        while((!found && (power_2<=(1000000000000000000LL)))){
            if(power_2>l && (power_2<=r)) found = true;
            else power_2 *= 2;
        }
        if(found){
            if(k<=(n - 2)) cout << l << '\n';
            else cout << power_2 << '\n';
        }
        else cout << -1 << '\n';
    }
}
int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
