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
class segtree
{
    public:
        vector<ll> tree;
        segtree(ll n)
        {
            tree.resize(4*n,0);
        }
        void build(vector<ll>& v,ll x,ll tl,ll tr)
        {
            if(tl==tr)
            {
                tree[x]=v[tl];
                return;
            }
            ll mid=(tl+tr)/2;
            build(v,2*x,tl,mid);
            build(v,2*x+1,mid+1,tr);
            tree[x]=tree[2*x]+tree[2*x+1];
        }
        void update(ll pos,ll val,ll x,ll tl,ll tr)
        {
            if(tl==tr)
            {
                tree[x]=val;
                return;
            }
            ll mid=(tl+tr)/2;
            if(pos<=mid) update(pos,val,2*x,tl,mid);
            else update(pos,val,2*x+1,mid+1,tr);
            tree[x]=tree[2*x]+tree[2*x+1];
        }
        ll query(ll l,ll r,ll x,ll tl,ll tr)
        {
            if(r<tl||tr<l) return 0;
            if(l<=tl&&tr<=r) return tree[x];
            ll mid=(tl+tr)/2;
            return query(l,r,2*x,tl,mid)+query(l,r,2*x+1,mid+1,tr);
        }
};

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
 
long long MOD = 1e9+7;
 
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
//         if(c<=r) rr=1;
//         return {t,bb,l,rr};
//     }
// }

void solve()
{
    ll ans=0;
    ll n=0;
    string s;
    cin>>n;
    cin>>s;
    vll gaps;
    ll temp=0;
    fr(i,0,n)
    {
        if(s[i]=='0') temp++;
        else if(temp>0)
        {
            gaps.pb(temp);
            temp=0;
        }
    }
    if(temp>0) gaps.pb(temp);
    ll x=gaps.size();
    if(x==1 && s[0]=='0' && s[n-1]=='0')
    {
        cout<<n-1;
        return;
    }
    if(gaps[0]>1 && s[0]=='0') ans=(gaps[0]/2)-1;
    if(gaps[x-1]>1 && s[n-1]=='0') ans=max(ans,(gaps[x-1]/2)-1);
    ll start=0,end=x;
    if(s[0]=='0') start++;
    if(s[n-1]=='0') end--;
    fr(i,start,end) if(gaps[i]>1) ans=max(ans,((gaps[i]-2)/3));
    if(x>1)
    {
        vector<pair<ll,ll>> ye;
        if(s[0]=='0') ye.pb({gaps[0]-1,INT_MAX});
        if(x>1 && s[n-1]=='0') ye.pb({gaps[x-1]-1,INT_MAX});
        fr(i,start,end) ye.pb({(gaps[i]-1)/2,gaps[i]});
        sort(all(ye));
        reverse(all(ye));
        ye[0].second=ye[0].first;
        ye[1].second=ye[1].first;
        vll final;
        fr(i,0,ye.size()) final.pb(ye[i].second);
        sort(all(final)); 
        ans=max(ans,final[0]);
    }
    cout<<ans+1;
}

signed main()
{
    freopen("socdist1.in","r",stdin);
    freopen("socdist1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}
