#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
#define all(a) a.begin(),a.end()  

void solve()
{
    ll n,m,c,ans(0);
    cin>>n>>m>>c;
    vll a(n);
    fr(i,0,n) cin>>a[i];
    sort(all(a));
    ll l(0),r(a[n-1]-a[0]);
    while(l<=r)
    {
        ll mid= l+ (r-l)/2;
        ll num(1),count(1),fir(a[0]);
        fr(i,1,n)
        {
            if(a[i]-fir<=mid && count<c) count++;
            else
            {
                count=1;
                num++;
                fir=a[i];
            }
        }
        if(num<=m)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
}
signed main()
{
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t;
    // while(t--) 
    solve();
}