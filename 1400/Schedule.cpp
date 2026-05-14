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
    ll n,m;
    void solve(){
        cin >> n >> m;
        vector<ll> a(m);
        for(ll i = 0;i<m;++i) cin >> a[i];
        vector<ll> first;
        vector<ll> second(n-1);
        sort(a.begin(),a.end());
        if(n == 1 && m != 1){
            first.push_back(a[0]);
            second.push_back(a[m-1]);
        }
        else{
            ll ptr1 = 0;
            ll ptr2 = m-1;
            ll total = 0;
            while(total!=(n-1)){
                if(total%2) first.push_back(a[ptr2]),ptr2--;
                else first.push_back(a[ptr1]),ptr1++;
                total++;
            }
            sort(first.begin(),first.end());
            for(ll i = 0;i<first.size();++i) second[i] = first[first.size()-i-1];
            if(n%2){
                first.push_back(a[ptr1]);
                second.push_back(a[ptr2]);
            }
            else{
                first.push_back(a[ptr2]);
                second.push_back(a[ptr2]);
            }
            sort(first.begin(),first.end());
            sort(second.begin(),second.end(),greater<ll>());
        }
        for(ll i = 0;i<n;++i){
            for(ll j = 0;j<6;++j){
                if(j%2) cout << second[i] << " ";
                else cout << first[i] << " ";
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
