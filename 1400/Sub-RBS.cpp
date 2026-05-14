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
string s;
void solve(){
    cin >> n;
    cin >> s;
    vector<ll> brackets;
    ll length = 1;
    for(ll i = 0;i<(n-1);++i){
        if(s[i]==s[i+1]){
            length++;
        }
        else{
            if(s[i]=='(') brackets.push_back(length);
            else brackets.push_back(-length);
            length = 1;
        }
    }
    brackets.push_back(-length);
    if(brackets.size()<4) cout << -1 << '\n';
    else{
        if(brackets.size()==4 && brackets[brackets.size()-2]==1) cout << -1 << '\n';
        else cout << n - 2 << '\n';
    }
}
int main(){
    code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
