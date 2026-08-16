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
        dsu(ll n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
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
            b = find(b);
            if(a==b) return;
            if(size[a]<size[b]) swap(a,b);
            size[a] += size[b];
            parent[b]=a;
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
 
bool isprime(ll n)
{
    ll i=2;
    while(i*i<=n)
    {
        if(n%i==0) return false;
        i++;
    }
    return true;
}
vector<bool> a;
ll sieve(ll n)
{
    ll limit=n*log(n*log(n))+10,count=0;
    limit=max(1ll*15,limit);
    limit=n+1;
    a.resize(limit,1);
    a[0]=0;
    a[1]=0;
    ll ans=0;
    fr(i,2,limit)
    {
        if(a[i])
        {   
            ans+=i;
            for(ll j=i*2;j<limit;j+=i) a[j]=0;
        }
    }
    return ans;
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
set<pair<ll,ll>> m;
set<ll> s;
ll n;
vector<string> maze;
vector<vector<vll>> comp;
vll thr;
void precompute()
{
    thr.resize(11);
    thr[0]=1;
    fr(i,1,11) thr[i]=thr[i-1]*3;
}
bool check(vector<vll>& state)
{
    fr(i,0,3)
    {
        if(state[i][0]==1 && state[i][1]==0 && state[i][2]==0) return true;
        if(state[i][2]==1 && state[i][1]==0 && state[i][0]==0) return true;
        if(state[0][i]==1 && state[1][i]==0 && state[2][i]==0) return true;
        if(state[2][i]==1 && state[1][i]==0 && state[0][i]==0) return true;
    }
    if(state[0][0]==1 && state[1][1]==0 && state[2][2]==0) return true;
    if(state[2][2]==1 && state[1][1]==0 && state[0][0]==0) return true;
    if(state[2][0]==1 && state[1][1]==0 && state[0][2]==0) return true;
    if(state[0][2]==1 && state[1][1]==0 && state[2][0]==0) return true;
    return false;
}
void dfs(ll i,ll j,vector<vll>& state)
{
    if(i<0 || i>=n || j<0 || j>=n) return;
    if(comp[i][j][0]==-1) return;
    vll g,g2;
    ll val=0;
    fr(k,0,3)
    {
        fr(l,0,3) val+=(thr[3*k+l]*state[k][l]);
    }
    if(m.count({val,n*i+j})) return;
    m.insert({val,n*i+j});
    ll p=0;
    if(comp[i][j][0]!=-2 && state[comp[i][j][1]][comp[i][j][2]]==2)
    {
        p=1;
        state[comp[i][j][1]][comp[i][j][2]]=comp[i][j][0];
        ll vall=0;
        fr(k,0,3)
        {
            fr(l,0,3) vall+=(thr[3*k+l]*state[k][l]);
        }
        if(check(state))
        {
            s.insert(vall);
            state[comp[i][j][1]][comp[i][j][2]]=2;
            return;
        }
    }
    dfs(i+1,j,state);
    dfs(i-1,j,state);
    dfs(i,j+1,state);
    dfs(i,j-1,state);
    if(p==1) state[comp[i][j][1]][comp[i][j][2]]=2;
}
void solve()
{   
    cin>>n;
    maze.resize(n);
    fr(i,0,n) cin>>maze[i];
    ll row,col;
    fr(i,0,n)
    {
        vector<vll> temp;
        for(ll j=0;j<3*n;j+=3)
        {
            if(maze[i][j]=='#') temp.pb({-1,-1,-1});
            else if(maze[i][j]=='O') temp.pb({0,maze[i][j+1]-'1',maze[i][j+2]-'1'});
            else if(maze[i][j]=='M') temp.pb({1,maze[i][j+1]-'1',maze[i][j+2]-'1'});
            else
            {
                temp.pb({-2,-2,-2});
                if(maze[i][j]=='B')
                {
                    row=i;
                    col=j/3;
                }
            }
        }
        comp.pb(temp);
    }
    vector<vll> start(3,vll(3,2));
    // vector<vll> visited(n,vll(n,0));
    dfs(row,col,start);
    cout<<s.size();
}    

signed main()
{ 
    // freopen("snowboots.in","r",stdin);
    // freopen("snowboots.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute();
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--)  
    solve();
}
