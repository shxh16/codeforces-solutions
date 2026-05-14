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
    vector<ll> even;
    vector<ll> odd;
    for(ll i = 0;i<n;++i){
        cin >> a[i];
        if(a[i]%2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    ll sum = 0;
    if(odd.size()) sum = odd[odd.size()-1];
    ll even_ptr = even.size();
    ll odd_ptr = 1;
    if(odd.size()==0) odd_ptr = 0;
    for(ll i = 0;i<n;++i){
        if(odd_ptr && even_ptr>=0){
            cout << sum << ' ';
            if(even_ptr-1 >=0){
                sum += even[even_ptr-1];
            }
            even_ptr--;
        }
        else if(odd_ptr){
            if(even.size()){
                if(odd.size()%2==0 && i == n - 1) cout << 0 << ' ';
                else{
                    if(odd_ptr%2 == 0) cout << sum << ' ';
                    else cout <<sum - even[0] << ' ';
                }
                odd_ptr++;
            }
            else{
                if(i%2 == 0) cout << sum << ' ';
                else cout << 0 << ' ';
            }
        }
        else cout << 0 << ' ';
    }
    cout << '\n';
}
int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
