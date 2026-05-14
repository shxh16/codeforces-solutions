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
ll n;
void solve(){
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;i<n;++i) cin >> a[i];
    vector<ll> copy(n);
    copy = a;
    sort(copy.begin(),copy.end());
    vector<ll> not_in_place;
    bool found = true;
    for(ll i = 0;i<n;++i){
        if(a[i]!=copy[i]) found = false,not_in_place.push_back(a[i]);
    }
    if(found) cout << "-1" << '\n';
    else{
        sort(not_in_place.begin(),not_in_place.end());
        ll answer = 1000000000;
        for(ll i = 0;i<not_in_place.size();++i){
            answer = min(answer,max(not_in_place[i]-copy[0],copy[n-1]-not_in_place[i]));
        }
        cout << answer << '\n';
    }
}
int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
