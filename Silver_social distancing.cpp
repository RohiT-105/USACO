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
    ll n,m;
    cin>>n>>m;
    vll a,b;
    fr(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        a.pb(x); b.pb(y);
    }
    sort(all(a));
    sort(all(b));
    ll l(1),r(b[m-1]-a[0]),ans;
    ans=r;
    while(l<=r)
    {
        ll mid= l + (r-l)/2;
        // cout<<mid<<endl;
        ll cows(n),start(a[0]),end(0-mid-1);
        fr(i,0,m)
        {
            start=max(a[i],end+mid);
            if(start<=b[i])
            {
                cows--;
                cows=cows- (b[i]-start)/mid;
                end= start + ((b[i]-start)/mid)*mid;
            }
        }
        if(cows<=0)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
}
signed main()
{
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t;
    // while(t--) 
    solve();
}