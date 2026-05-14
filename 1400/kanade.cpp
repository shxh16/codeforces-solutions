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
ll n,k;
ll a[200000];
void solve(){
    cin >> n>>k;
    set<ll> elements;
    map<ll,ll> freq;
    for(ll i = 0;i<n;++i){
        cin >> a[i];
        elements.insert(a[i]);
        freq[a[i]] = 1;
    }
    map<ll,ll> check;
    bool found = true;
    vector<ll> answer;
    while(elements.size() && found){
        ll value = *elements.begin();
        if(!check[value]){
            check[value] = 1;
            for(ll i = value;i<=k;i += value){
                if(!freq[i]){
                    found = false;
                    cout << -1 << '\n';
                    break;
                }
                else{
                    check[i] = 1;
                }
            }
            answer.push_back(value);
        }
        elements.erase(value);
    }
    if(found){
        cout << answer.size() << '\n';
        for(ll i = 0;i<answer.size();++i) cout << answer[i] << " ";
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
