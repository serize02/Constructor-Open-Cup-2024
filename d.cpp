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

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    test(){
        int n, m;
        cin >> n >> m;
        vector<int> ss, dd;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            ss.push_back(x);
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            dd.push_back(x);
        }
        ss.push_back(-1);
        sort(all(ss));
        sort(all(dd));
        vector<int> ans;
        int l = -1;
        bool ok = true;
        for(int i = 1; i < ss.size(); i++){
            bool f = false;
            for(int j = l+1; j < m; j++){
                if(dd[j] <= ss[i] and dd[j] > ss[i-1]){
                    ans.push_back(j+1);
                    l = j;
                    f = true;
                    break;
                }
            }
            ok = f;
            if(not ok) break;
        }
        if(not ok){
            cout << -1 << "\n";
            continue;
        }
        cout << ans.size() << "\n";
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}