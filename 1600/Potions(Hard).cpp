#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define code ios::sync_with_stdio(false);
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
ll n;
void solve(){
    cin >> n;
    ll a[n];
    for(ll i = 0;i<n;++i) cin >> a[i];
    multiset<ll> negative;
    ll sum = 0;
    ll number_potions = 0;
    for(ll i = 0;i<n;++i){
        if(a[i]>=0) sum += a[i],number_potions++;
        else{
            if(sum + a[i]>=0) sum += a[i],number_potions++,negative.insert(a[i]);
            else if(negative.size() && *negative.begin()<a[i]){
                sum -= *negative.begin();
                sum += a[i];
                negative.erase(negative.begin());
                negative.insert(a[i]);
            }
        }
    }
    cout << number_potions << '\n';
}
int main(){
    code by Shrinil;
    // int t; cin >> t;
    // while(t--){
        solve();
    // }
}
