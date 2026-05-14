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
string a;
void solve(){
    cin >> n;
    cin >> a;
    ll latest = 0;
    bool found = true;
    for(ll i = 0;i<n;++i){
        if(a[i]=='1'){
            if(i+1 - latest == 2) found = false;
            else latest = i+1;
        }
    }
    if(n+1 - latest == 2) found = false;
    if(!found){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        set<ll> elements;
        for(ll i = 0;i<n;++i){
            if(a[i]=='1'){
                while(elements.size()){
                    cout << *elements.rbegin() << " ";
                    elements.erase(*elements.rbegin());
                }
                cout << i+1 << " ";
            }
            else elements.insert(i+1);
        }
        while(elements.size()){
            cout << *elements.rbegin() << " ";
            elements.erase(*elements.rbegin());
        }
        cout << '\n';
    }
}
int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
