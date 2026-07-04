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
ll find(ll ele,vector<pair<ll,ll>>& comp)
{
    ll l=0,r=comp.size();
    while(l+1<r)
    {
        ll mid=l+(r-l)/2;
        if(comp[mid].first<=ele) l=mid;
        else r=mid;
    }
    return l;
}
void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>> pos,neg;
    fr(i,0,n)
    {
        ll l,r;
        cin>>l>>r;
        pos.pb({l,1});
        neg.pb({r,-1});
    }
    sort(all(pos));
    sort(all(neg));
    vector<pair<ll,ll>> comp;
    ll p1=0,p2=0,sum=0;
    while(p2<n)
    {
        ll s=comp.size();
        if(p1==n)
        {
            sum+=(neg[p2].second);
            if(!comp.empty() && neg[p2].first==comp[s-1].first) comp[s-1]={neg[p2].first,sum};
            else comp.pb({neg[p2].first,sum});
            p2++;
        }
        else if(pos[p1].first==neg[p2].first)
        {
            sum+=(pos[p1].second+neg[p2].second);
            if(!comp.empty() && pos[p1].first==comp[s-1].first) comp[s-1]={pos[p1].first,sum};
            else comp.pb({pos[p1].first,sum});
            p1++;
            p2++;
        }
        else if(pos[p1].first<neg[p2].first)
        {
            sum+=(pos[p1].second);
            if(!comp.empty() && pos[p1].first==comp[s-1].first) comp[s-1]={pos[p1].first,sum};
            else comp.pb({pos[p1].first,sum});
            p1++;
        }
        else
        {
            sum+=(neg[p2].second);
            if(!comp.empty() && neg[p2].first==comp[s-1].first) comp[s-1]={neg[p2].first,sum};
            else comp.pb({neg[p2].first,sum});
            p2++;
        }
    }
    // fr(i,0,comp.size()) cout<<comp[i].first<<" "<<comp[i].second<<nl;
    vector<pair<ll,ll>> tot(comp.size()),uni(comp.size());
    // tot[0]={comp[0].first-1,0};
    // tot[0]={comp[0].first-1,0};
    tot[0]={comp[0].first,0};
    uni[0]={comp[0].first,0};
    fr(i,1,comp.size())
    {
        uni[i]=comp[i];
        tot[i]=comp[i];
        if(comp[i-1].second==1) uni[i].second=uni[i-1].second+(comp[i].first-comp[i-1].first);
        else uni[i].second=uni[i-1].second;
        if(comp[i-1].second!=0) tot[i].second=tot[i-1].second+(comp[i].first-comp[i-1].first);
        else tot[i].second=tot[i-1].second;
    }
    // cout<<nl;
    // fr(i,0,comp.size()) cout<<tot[i].first<<" "<<tot[i].second<<nl;
    // cout<<nl;
    // fr(i,0,comp.size()) cout<<uni[i].first<<" "<<uni[i].second<<nl;
    ll tem=tot[tot.size()-1].second,ans=0;
    fr(i,0,n)
    {
        ll l=pos[i].first;
        ll r=neg[i].first;
        ll ind1=find(l,comp),ind2=find(r,comp);
        ans=max(ans,tem-(uni[ind2].second-uni[ind1].second));
    }
    cout<<ans;
}
signed main()
{ 
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}
