#include <bits/stdc++.h>
#pragma agma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define compress_id(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define lowbit(x) x&(-x)
#define pb push_back
#define f first
#define s second
#define test() int t; cin >> t; for(;t;t--)
#define sz(x) (int)x.size()
#define cyes cout << "YES\n"
#define cno cout << "NO\n" 

using namespace std;

using ull = unsigned long long;
using ld = long double;
using point = complex<double>;
const int MAX = 1e6+5;
const int INF = (1<<30);
const int mod = 1e9+7;
const double pi = acos(-1);

inline int pow_mod(int a, int n){
    int ans = 1;
    for(;n ;n >>= 1){
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
    }
    return ans;
}

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15,x=(x^(x>>30))*0xbf58476d1ce4e5b9,x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    test(){
        int n, k;
        cin >> n >> k;
        vector<int> ar[n+1];
        unordered_map<int,int,custom_hash> mp;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            ar[x].push_back(i);
        }
        int ans = k;
        bool ok = false;
        for(int i = 1; i <= n ; i++) {
            if(ar[i].size()>=k) {
                ok = true;
                int x = 0, last = -1;
                for(int j = 0; j < k-1; j++){
                    x += ar[i][j]-last-1;
                    ans = min(ans, x + (k-j-1));
                    last = ar[i][j];
                }
                for(int j = 0 ; j + (k-1) < ar[i].size(); j++){
                    ans = min(ans, ar[i][j+(k-1)]-ar[i][j]+1-k);
                }
            }     
        }
        if(ok) cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}