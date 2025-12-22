#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
#define all(a) a.begin(),a.end()
// static const ll mod=1e9+7;
// long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
//     vector<int> left(arr.begin() + l, arr.begin() + m + 1);
//     vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
 
//     int i = 0, j = 0, k = l;
//     long long invCount = 0;
 
//     while (i < left.size() && j < right.size()) {
//         if (left[i] <= right[j]) {
//             arr[k++] = left[i++];
//         } else {
//             arr[k++] = right[j++];
//             invCount += (left.size() - i); // count inversions
//         }
//     }
 
//     while (i < left.size()) arr[k++] = left[i++];
//     while (j < right.size()) arr[k++] = right[j++];
 
//     return invCount;
// }
 
// long long mergeSortAndCount(vector<int>& arr, int l, int r) {
//     if (l >= r) return 0;
//     int m = l + (r - l) / 2;
//     long long invCount = 0;
//     invCount += mergeSortAndCount(arr, l, m);
//     invCount += mergeSortAndCount(arr, m + 1, r);
//     invCount += mergeAndCount(arr, l, m, r);
//     return invCount;
// }
 
// // Example usage:
// // int main() {
// //     vector<int> arr = {2, 4, 1, 3, 5};
// //     long long inversions = mergeSortAndCount(arr, 0, arr.size() - 1);
// //     cout << "Number of inversions: " << inversions << "\n";
// // }
 
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
        void build(vector<ll>& v, ll x, ll tl,ll tr)
        { 
            if(tl==tr)
            {
                tree[x]=v[tl-1];
                return;
            }
            ll mid= tl+ (tr-tl)/2;
            build(v,2*x,tl,mid);
            build(v,(2*x)+1,mid+1,tr);
            tree[x]=tree[2*x]^tree[(2*x)+1];
        }
        void update(ll val,ll pos,ll x,ll tl,ll tr)
        {
            if(tl==tr)
            {
                tree[x]=val;
                return;
            }
            ll mid= tl+ (tr-tl)/2;
            if(pos<=mid) update(val,pos,2*x,tl,mid);
            else update(val,pos,(2*x)+1,mid+1,tr);
            tree[x]=tree[2*x]^tree[(2*x)+1];
        }
        ll xorr(ll l,ll r,ll x,ll tl,ll tr)
        {
            if(tr<l || tl>r) return 0;
            if(l<=tl && r>=tr) return tree[x];
            ll mid= tl+ (tr-tl)/2;
            return xorr(l,r,2*x,tl,mid)^xorr(l,r,(2*x)+1,mid+1,tr);
        }
};
 
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
// vll v(1000000);
void solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<vll> v(2*n-1,vll(2*n-1));
    map<pair<ll,ll>,ll> m;
    fr(i,0,n) fr(j,0,n) {cin>>v[i+j][j-i+n-1]; m[{i+j,j-i+n-1}]=1;}
    // fr(i,0,2*n-1) 
    // {
    //     fr(j,0,2*n-1) cout<<v[i][j]<<" ";
    //     cout<<nl;
    // }
    k=2*k+1;
    fr(i,1,2*n-1)
    {
        v[0][i]+=v[0][i-1];
        v[i][0]+=v[i-1][0];
    }
    fr(i,1,2*n-1) fr(j,1,2*n-1) v[i][j]+=(v[i-1][j]+v[i][j-1]-v[i-1][j-1]);
    ll ans=0;
    fr(i,k-1,2*n-1) fr(j,k-1,2*n-1) 
    {
        if(!m[{i,j}]) continue;
        ll val=v[i][j];
        if(i-k>=0) val-=v[i-k][j];
        if(j-k>=0) val-=v[i][j-k];
        if(i-k>=0 && j-k>=0) val+=v[i-k][j-k];
        ans=max(ans,val);
    }
    cout<<ans;
}
signed main()
{
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll _=sieve(100000);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}