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
    ll n;
    cin>>n;
    vll v(n);
    fr(i,0,n) cin>>v[i];
    // fr(i,0,n) v[i]=v[i]*2;
    sort(all(v));
    vll left(n),right(n);
    left[0]=0;
    left[1]=v[1]-v[0];
    ll p1=1,p2=2;
    while(p2<n)
    {
        if(v[p2]<=v[p1]+left[p1]+1)
        {
            left[p2]=left[p1]+1;
            p2++;
        }
        else
        {
            p1++;
            if(p1==p2) 
            {
                left[p1]=v[p1]-v[p1-1];
                p2++;
            }
        }
    }    
    right[n-1]=0;
    right[n-2]=v[n-1]-v[n-2];
    p1=n-1;
    p2=n-2;
    while(p2>=0)
    {
        if(v[p2]>=v[p1]-(right[p1]+1))
        {
            right[p2]=right[p1]+1;
            p2--;
        }
        else
        {
            p1--;
            if(p1==p2) 
            {
                right[p1]=v[p1+1]-v[p1];
                p2--;
            }
        }
    } 
    // fr(i,0,n) cout<<right[i]<<" "; 
    ll l=1,r=v[n-1]-v[0];
    while(l+1<r)
    {
        ll mid=l+(r-l)/2;
        ll ind1=0,ind2=0;
        double rad=mid;
        rad=rad/2;
        rep(i,n-1,0)
        {
            if(left[i]<=rad)
            {
                ind1=i;
                break;
            }
        }
        rep(i,n-1,0)
        {
            if(left[i]<=rad-1)
            {
                ind2=i;
                break;
            }
        }
        ll ind3=n-1,ind4=n-1;
        fr(i,0,n)
        {
            if(right[i]<=rad)
            {
                ind3=i;
                break;
            }
        }
        fr(i,0,n)
        {
            if(right[i]<=rad-1)
            {
                ind4=i;
                break;
            }
        }
        ll dist1=v[ind3]-v[ind1];
        ll dist2=v[ind4]-v[ind2];
        if(dist1<=0) r=mid;
        else if(dist2<=mid) r=mid;
        else l=mid;
    } 
    double ans=r;
    cout<<setprecision(1)<<fixed<<ans/2;
}
signed main()
{ 
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}
