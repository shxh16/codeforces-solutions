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
ll n,m,x;
void solve(){
    cin >> n>>m;
    multiset<ll> swords;
    ll maximum = 0;
    for(ll i = 0;i<n;++i) cin >> x,swords.insert(x),maximum = max(maximum,x);
    vector<ll> b(m);
    vector<ll> c(m);
    for(ll i = 0;i<m;++i) cin >> b[i];
    for(ll i = 0;i<m;++i){
        cin >> c[i];
        maximum = max(maximum,c[i]);
    }
    vector<array<ll,2>> health_non_zero;
    vector<ll> health_zero;
    for(ll i = 0;i<m;++i){
        if(b[i] <= maximum){
            if(c[i]) health_non_zero.push_back({b[i],c[i]});
            else health_zero.push_back(b[i]);
        }
    }
    ll killed = 0;
    sort(health_non_zero.begin(),health_non_zero.end());
    sort(health_zero.begin(),health_zero.end(),greater<ll>());
    for(ll i = 0;i<health_non_zero.size();++i){
        if(swords.size() && (swords.lower_bound(health_non_zero[i][0]) != swords.end())){
            ll val = max(*swords.lower_bound(health_non_zero[i][0]),health_non_zero[i][1]);
            swords.erase(swords.lower_bound(health_non_zero[i][0]));
            swords.insert(val);
            killed++;
        }
        else{
            break;
        }
    }
    for(ll i = 0;i<health_zero.size();++i){
        if(swords.size() && health_zero[i] <= *prev(swords.end())){
            swords.erase(prev(swords.end()));
            killed++;
        }
    }
    cout << killed << '\n';
}

int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
