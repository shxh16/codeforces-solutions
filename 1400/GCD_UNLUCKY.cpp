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
    return ((n > 0)&&(n & (n - 1)) == 0);
    if(n == 0) return true;
}
ll n;
ll a[100000];
ll b[100000];
void solve(){
    cin >> n;
    bool found = true;
    for(ll i = 0;i<n;++i){
        cin >> a[i];
        if(i){
            if(a[i]>a[i-1]) found = false;  
            if(a[i-1]%a[i]) found = false;
        }
    }
    for(ll i = 0;i<n;++i){
        cin >> b[i];
        if(i){
            if(b[i]<b[i-1]) found = false;
            if(b[i]%b[i-1]) found = false;
        }
    }
    if(a[n-1]!=b[0] || (b[n-1]%a[n-1]) || (a[0]%b[0])) found = false;
    for(ll i = 0;i<(n-1);++i){
        if(gcd(a[i],b[i+1])!=b[0]) found = false;
    }
    if(found) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main(){
    code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
