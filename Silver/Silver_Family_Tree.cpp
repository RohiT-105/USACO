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
map<string,set<string>> m;
map<string,string> par;
string a,b;
bool aa,bb;
void dfs(string par,string node)
{
    if(node==a) aa=1;
    else if(node==b) bb=1;
    for(auto x:m[node])
    {
        if(x!=par) dfs(node,x);
    }
}
string lca(string par,string node, string a,string b)
{
    if(node==a || node==b) return node;
    ll co=0;
    string anc;
    for(auto x:m[node])
    {
        if(x==par) continue;
        string g=lca(node,x,a,b);
        if(g!="") 
        {
            co++;
            anc=g;
        }
    }
    if(co==0) return "";
    else if(co==1) return anc;
    else return node;
}
ll dfs2(string par,string node,string ser)
{
    if(node==ser) return 0;
    for(auto x:m[node])
    {
        if(x==par) continue;
        ll co=dfs2(node,x,ser);
        if(co!=-1) return 1+co; 
    }
    return -1;
}
void solve()
{   
    ll n;
    cin>>n>>a>>b;
    set<string> ppl;
    fr(i,0,n)
    {
        string x,y; 
        cin>>x>>y;
        m[x].insert(y); 
        par[y]=x;
        ppl.insert(x);
        ppl.insert(y);
    }
    string root="";
    for(auto x:par) ppl.erase(x.first);
    for(auto x:ppl)
    {
        aa=0;
        bb=0;
        dfs("",x);
        if(aa && bb)
        {
            root=x;
            break;
        }
    }
    if(root=="")
    {
        cout<<"NOT RELATED";
        return;
    }
    string head=lca("",root,a,b);
    ll d1=dfs2("",head,a);
    ll d2=dfs2("",head,b);
    if(d1>d2)
    {
        swap(d1,d2);
        swap(a,b);
    }
    if(d1==1 && d2==1) cout<<"SIBLINGS";
    else if(d1>=2 && d2>=2) cout<<"COUSINS";
    else
    {
        cout<<a;
        cout<<" is the ";
        fr(i,0,d2-2) cout<<"great-";
        if(d1==0) 
        {
            if(d2>1) cout<<"grand-";
            cout<<"mother ";
        }
        else cout<<"aunt ";
        cout<<"of "<<b;
    }
}    

signed main()
{ 
    freopen("family.in","r",stdin);
    freopen("family.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--)  
    solve();
}
