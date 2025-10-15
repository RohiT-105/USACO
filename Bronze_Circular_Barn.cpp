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

// // class dsu
// // {   
// //     public:
// //         vll parent;
// //         vll size;
// //         dsu(ll n)
// //         {
// //             parent.resize(n+1);
// //             size.resize(n+1,1);
// //             fr(i,1,n+1) 
// //             {   
// //                 parent[i]=i;
// //             }
// //         }
// //         ll find(ll x) 
// //         {
// //             if (x != parent[x]) 
// //             {
// //                 parent[x] = find(parent[x]);
// //             }
// //             return parent[x];
// //         }
// //         bool same(ll a, ll b) 
// //         {
// //             return find(a)==find(b);
// //         }
// //         void join(ll a, ll b) 
// //         {            
// //             a=find(a);
// //             b = find(b);
// //             if(size[a]<size[b]) swap(a,b);
// //             size[a] += size[b];
// //             parent[b]=a;
// //         }
// // };
class segtree
{
    public:
        vector<ll> tree;
        segtree(ll n)
        {
            tree.resize(4*n,LLONG_MAX);
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
            tree[x]=min(tree[2*x],tree[(2*x)+1]);
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
            tree[x]=min(tree[2*x],tree[(2*x)+1]);
        }
        ll sum(ll l,ll r,ll x,ll tl,ll tr)
        {
            if(tr<l || tl>r) return LLONG_MAX;
            if(l<=tl && r>=tr) return tree[x];
            ll mid= tl+ (tr-tl)/2;
            return min(sum(l,r,2*x,tl,mid) , sum(l,r,(2*x)+1,mid+1,tr));
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

// bool isprime(ll n)
// {
//     ll i=2;
//     while(i*i<=n)
//     {
//         if(n%i==0) return false;
//         i++;
//     }
//     return true;
// }
// ll sieve(ll n)
// {
//     ll limit=n*log(n*log(n))+10,count=0;
//     limit=max(1ll*15,limit);
//     limit=n+1;
//     vector<bool> a(limit,1);
//     a[0]=0;
//     a[1]=0;
//     ll ans=0;
//     fr(i,2,limit)
//     {
//         if(a[i])
//         {   
//             ans+=i;
//             for(ll j=i*2;j<limit;j+=i) a[j]=0;
//         }
//     }
//     return ans;
// }
// //print("ANS")
// //B87678
// vll fac1(2e6+1),fac2(2e6+1);
// void pre()
// {
//     fac1[0]=1;
//     fac2[0]=1;
//     fr(i,1,2e6+1)
//     {
//         fac1[i]=(fac1[i-1]*i)%MOD;
//         fac2[i]=(fac2[i-1]*modinv(i))%MOD;
//     }

// }
vll fac(3e5+1);
vll facinv(3e5+1);
void pre()
{
    fac[0]=1;
    facinv[0]=modinv(1);
    fr(i,1,3e5+1)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        facinv[i]=((facinv[i-1])*(modinv(i)))%MOD;
    }
}
void solve() 
{
    ll n;
    cin>>n;
    vll a(n);
    fr(i,0,n)
    {
        cin>>a[i];
    }
    ll ans=INT_MAX;
    fr(i,0,n)
    {
        ll p=0,q=i,d=0;
        fr(j,0,n)
        {
            d+=(p*a[q%n]);
            q++;
            p++;
        }
        ans=min(ans,d);
    }
    cout<<ans;
}

signed main()
{
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}