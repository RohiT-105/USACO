#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
#define all(a) a.begin(),a.end()

class dsu
{   
    public:
        vll parent;
        vll size;
        ll comp;
        dsu(ll n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            comp=n-1;
            fr(i,1,n+1) 
            {   
                parent[i]=i;
            }
        }
        ll find(ll x) 
        {
            if (x != parent[x]) 
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        bool same(ll a, ll b) 
        {
            return find(a)==find(b);
        }
        void join(ll a, ll b) 
        {            
            a=find(a);
            b=find(b);
            if(a==b) return;
            if(size[a]<size[b]) swap(a,b);
            size[a]+=size[b];
            parent[b]=a;
            comp--;
        }
};
// class segtree
// {
//     public:
//         vector<ll> tree;
//         segtree(ll n)
//         {
//             tree.resize(4*n,0);
//         }
//         void build(vector<ll>& v,ll x,ll tl,ll tr)
//         {
//             if(tl==tr)
//             {
//                 tree[x]=v[tl];
//                 return;
//             }
//             ll mid=(tl+tr)/2;
//             build(v,2*x,tl,mid);
//             build(v,2*x+1,mid+1,tr);
//             tree[x]=tree[2*x]+tree[2*x+1];
//         }
//         void update(ll pos,ll val,ll x,ll tl,ll tr)
//         {
//             if(tl==tr)
//             {
//                 tree[x]=val;
//                 return;
//             }
//             ll mid=(tl+tr)/2;
//             if(pos<=mid) update(pos,val,2*x,tl,mid);
//             else update(pos,val,2*x+1,mid+1,tr);
//             tree[x]=gcd(tree[2*x],tree[2*x+1]);
//         }
//         ll query(ll l,ll r,ll x,ll tl,ll tr)
//         {
//             if(r<tl||tr<l) return 0;
//             if(l<=tl&&tr<=r) return tree[x];
//             ll mid=(tl+tr)/2;
//             return gcd(query(l,r,2*x,tl,mid),query(l,r,2*x+1,mid+1,tr));
//         }
// };

// class segtree
// {
//     public:
//         vector<ll> tree;
//         segtree(ll n)
//         {
//             tree.resize(4*n,LLONG_MAX);
//         }
//         void build(vector<ll>& v,ll x,ll tl,ll tr)
//         {
//             if(tl==tr)
//             {
//                 tree[x]=v[tl];
//                 return;
//             }
//             ll mid=(tl+tr)/2;
//             build(v,2*x,tl,mid);
//             build(v,2*x+1,mid+1,tr);
//             tree[x]=min(tree[2*x],tree[2*x+1]);
//         }
//         void update(ll pos,ll val,ll x,ll tl,ll tr)
//         {
//             if(tl==tr)
//             {
//                 tree[x]=val;
//                 return;
//             }
//             ll mid=(tl+tr)/2;
//             if(pos<=mid) update(pos,val,2*x,tl,mid);
//             else update(pos,val,2*x+1,mid+1,tr);
//             tree[x]=min(tree[2*x],tree[2*x+1]);
//         }
//         ll query(ll l,ll r,ll x,ll tl,ll tr)
//         {
//             if(r<tl||tr<l) return LLONG_MAX;
//             if(l<=tl&&tr<=r) return tree[x];
//             ll mid=(tl+tr)/2;
//             return min(query(l,r,2*x,tl,mid),query(l,r,2*x+1,mid+1,tr));
//         }
// };

// ll dist(ll x1,ll y1,ll x2,ll y2)
// {
//     return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
// }
 
long long MOD = 998244353;
 
long long modpow(long long a, long long b) 
{
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
long long modinv(long long q) 
{
    return modpow(q, MOD - 2);
}
// static long long merge_count(vector<long long>& a) {
//     vector<long long> tmp(a.size());
//     function<long long(size_t,size_t)> solve = [&](size_t L, size_t R) -> long long {
//         if (R - L <= 1) return 0;
//         size_t M = (L + R) / 2;
//         long long cnt = solve(L, M) + solve(M, R);
 
//         size_t i = L, j = M, k = L;
//         while (i < M || j < R) {
//             if (j == R || (i < M && a[i] <= a[j])) tmp[k++] = a[i++];
//             else { tmp[k++] = a[j++]; cnt += (M - i); }
//         }
//         for (size_t t = L; t < R; ++t) a[t] = tmp[t];
//         return cnt;
//     };
//     return solve(0, a.size());
// }
 
// // Accepts a vector<int>, prints and returns the number of swaps required.
// long long swaps_to_sort(const vector<ll>& arr) {
//     vector<long long> v(arr.begin(), arr.end());
//     long long swaps = merge_count(v);
//     // cout << swaps << '\n';
//     return swaps;
// }
// vll intersect(ll a,ll b,ll c,ll d,ll p,ll q,ll r,ll s)
// {
//     if(q>=d || s<=b || p>=c || r<=a) return {0,0,0,0};
//     else 
//     {
//         ll t(0),bb(0),l(0),rr(0);
//         if(d<=s) t=1;
//         if(b>=q) bb=1;
//         if(a>=p) l=1;
//         if(c<=r1) rr=1;
//         return {t,bb,l,rr};
//     }
// }
// bool comp(pair<ll,ll> a,pair<ll,ll> b)
// {
//     if(a.first<b.first) return true;
//     else if(a.first==b.first)
//     {
//         if(a.second>=b.second) return true; 
//     }
//     return false;
// }
// set<vector<vll>> s;
ll n,m;
vector<vector<vll>> tree;
vector<multiset<ll>> path;
vll enjoy;
void dfs(ll par,ll node)
{
    for(auto x:tree[node])
    {
        if(x[0]==par) continue;
        enjoy[x[0]]+=(enjoy[node]+x[2]);
        path[x[0]]=path[node];
        path[x[0]].insert(x[1]);
        if(path[x[0]].size()>11) path[x[0]].erase(path[x[0]].begin());
        dfs(node,x[0]);
    }
}
void solve()
{   
    cin>>n;
    tree.resize(n+1);
    enjoy.resize(n+1);
    path.resize(n+1);
    fr(i,2,n+1)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        tree[i].pb({a,b,c});
        tree[a].pb({i,b,c});
    }
    dfs(0,1);
    cin>>m;
    vector<vector<pair<ll,ll>>> dp(11);
    fr(i,0,11)
    {
        fr(j,1,n+1)
        {
            if(path[j].size()>i)
            {   
                auto it=path[j].end();
                fr(k,0,i+1) it--;
                dp[i].pb({(*it),enjoy[j]});
            }
            else dp[i].pb({0,enjoy[j]});
        }
        sort(all(dp[i]));
        fr(j,1,n)
        {
            dp[i][j].second=max(dp[i][j].second,dp[i][j-1].second);
        }
    }
    fr(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        ll l=0,r=n;
        while(l+1<r)
        {
            ll mid=l+(r-l)/2;
            if(dp[y][mid].first<=x) l=mid;
            else r=mid;
        }
        cout<<dp[y][l].second<<nl;
    }
}    

signed main()
{ 
    // freopen("family.in","r",stdin);
    // freopen("family.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--)  
    solve();
}
