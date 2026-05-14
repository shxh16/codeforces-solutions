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
string s;
void solve(){
    cin >> n >> k;
    vector<string> a(k);
    for(ll i = 0;i<k;++i){
        cin >> s;
        a[i] = s;
    }
    vector<ll> divisors;
    for(ll i = 1;i<=n;++i){
        if(n%i == 0) divisors.push_back(i);
    }
    // cout << divisors.size() << '\n';
    ll answer;
    for(ll i = 0;i<(divisors.size());++i){
        // cout << divisors[i] << '\n';
        bool found = true;
        string output = "";
        for(ll j = 0;j<divisors[i];++j){
            bool found1 = false;
            ll character[26] = {0};
            for(ll ptr = j;ptr<n;ptr += divisors[i]){
                set<char> occurences;
            for(ll ptr1 = 0;ptr1<k;++ptr1){
                    occurences.insert(a[ptr1][ptr]);
                }
                for(auto ptr1:occurences) character[int(ptr1 - 'a')]++;
            }
            for(ll ptr = 0;ptr<26;++ptr){
                if(character[ptr]>=(n/divisors[i])){
                    found1 = true;
                    output = output + (char('a' + ptr));
                    break;
                } 
            }
            if(found1 == true) continue;
            else found = false;
        }
        if(found){
            string answer1 = "";
            while (answer1.size()<n)
            {
                answer1 = answer1 + output;
            }
            cout << answer1 << '\n';
            break;
        }
    }
}
int main(){
    Code by Shrinil;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
