#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
 
void solve()
{
    ll n,t,ans(0);
    cin>>n>>t;
    vll a(n);
    fr(i,0,n) cin>>a[i];
    ll l(1),r(n);
    while(l<=r)
    {
        ll mid=l+ (r-l)/2;
        // cout<<mid;
        multiset<ll> s;
        fr(i,0,n)
        {
            if(s.size()<mid) s.insert(a[i]);
            else 
            {
                s.insert(a[i]+ *s.begin());
                s.erase(s.begin());
            }
        }
        ll time=*s.rbegin();
        // for(auto x:s) cout<<x<<endl;
        //     cout<<endl;
        if(time<=t)
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
}
signed main()
{
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t;
    // while(t--) 
    solve();
}
