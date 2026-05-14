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
ll n,k,q,c,l,r;
void solve(){
    cin >> n>>k>>q;
    vector<ll> a(n,k);
    vector<array<ll,2>> mex;
    vector<array<ll,2>> min;
    for(ll i = 0;i<q;++i){
        cin >> c >> l >> r;
        if(c == 2) mex.push_back({l,r});
        else min.push_back({l,r});
    }
    sort(mex.begin(),mex.end());
    sort(min.begin(),min.end());
    ll ptr = 0;
    for(ll i = 0;i<mex.size();++i){
        l = mex[i][0];
        r = mex[i][1];
        // cout << l << '\n';
        // cout << r << '\n';
        for(ll j = 0;j<min.size();++j){
            // cout << min[j][0] << '\n';
            // cout << min[j][1] << '\n';
            if(min[j][0]<l && l<=min[j][1]){
                for(ll ptr1 = l-1;ptr1<min[j][1];++ptr1) a[ptr1] = k+1;
            }
            if(min[j][0]<=r && r<min[j][1]){
                for(ll ptr1 = min[j][0]-1 ;ptr1<r;++ptr1) a[ptr1] = k+1;
            }
        }
        for(ll j = mex[i][0]-1;j<mex[i][1];j++){
            if(a[j]==k){
                a[j] = ptr;
                ptr++;
                ptr %= k;
            }
            else{
                ptr = a[j];
                ptr++;
                ptr %= k;
            }
        }
    }
    for(ll i = 0;i<n;++i) cout << a[i] << " ";
    cout << '\n';
}
int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
